#include <WiFi.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>
#include <WebServer.h>


#include "config.h"

String v = "0.3";

WebServer server(80);

const int led = LED_BUILTIN;
const int rele = 16;

const char *webPage = 
"<HTML>"
"<head></head>"
"<body>"
"<center><form action='/'>"
"<button name='comando' type='submit' value='1'>ON Rele</button>"
"<button name='comando' type='submit' value='2'>ON Led</button><br>"
"<button name='comando' type='submit' value='3'>OFF Rele</button>"
"<button name='comando' type='submit' value='4'>OFF Led</button>"
"<br><a href=\"https://github.com/javacasm/CursoIOTCo/tree/main/codigo/control_web\">Codigo</a>"
"<br><img src=\"https://github.com/javacasm/Teleco_IOT/blob/master/images/Licencia_CC_peque.png?raw=true\">"
"</form></center>"
"</body>"
"</HTML>";

void handleForm()
{
    // only move if we submitted the form
    if (server.arg("comando"))
    {
        // get the value of request argument "dir"
        int comando = server.arg("comando").toInt();
        switch (comando)
        {
            case 1:
                digitalWrite(rele,HIGH);
                break;
            case 2:
                digitalWrite(led,HIGH);
                break;
            case 3:
                digitalWrite(rele,LOW);
                break;
            case 4:
                digitalWrite(led,LOW);
                break;
        }
        
        delay(50);
    }

    // in all cases send the response
    server.send(200, "text/html", webPage);
}




void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}


void setup() {
  pinMode(led, OUTPUT);
  pinMode(rele, OUTPUT);
  
  digitalWrite(led, LOW);
  digitalWrite(rele, LOW);
  
  Serial.begin(115200);

  Serial.print("Conectando a ");
  Serial.print(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado a ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(nombreESP32)) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleForm);

  server.on("/inline", []() {
    server.send(200, "text/plain", "tambien funciona asi...");
  });


  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server arrancado");
  String url="http://";
  url += WiFi.localIP().toString();
  Serial.println(url);

}

void loop() {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks
}
