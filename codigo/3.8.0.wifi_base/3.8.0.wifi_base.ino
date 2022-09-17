#include <WiFi.h>
#include <WiFiClient.h>

#include "config.h"  // Cambiamos  el SSI y la clave en el fichero config.h

const int led = LED_BUILTIN;

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  Serial.print("Conectando a ");
  Serial.print(ssid);  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); // imprime "." mientras intenta conectarse
  }
  Serial.println("");
  Serial.print("Conectado a ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {}
