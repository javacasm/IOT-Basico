/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

#include "DHT.h"

IPAddress staticIP285_10(192,168,1,195);
IPAddress gateway285_10(192,168,1,1);
IPAddress subnet285_10(255,255,255,0);

WiFiServer server(80);

DHT dht12(12,DHT11);

DHT dht16(16,DHT11);

void setup()
{
     WiFi.begin("CEP_MONTILLA-UNIFI","CEPMONTILLA");
  WiFi.config(staticIP285_10, gateway285_10, subnet285_10);
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
      client.println("<h3 style=""color:#ff0000"">");
      client.println("Cabecera");
      client.println("</h3>");
    client.println("</head>");
    client.println("<body>");
      client.println("Temperatura");
      client.println("<span style=""color:#663333;font-size:23px"">");
      client.println((dht12.readTemperature( )));
      client.println("</span>");
      client.println("<br>");
      client.println("Humedad");
      client.println("<span style=""color:#663333;font-size:23px"">");
      client.println((dht16.readHumidity( )));
      client.println("</span>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
     delay(1);

}
