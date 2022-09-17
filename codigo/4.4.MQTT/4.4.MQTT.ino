#include <WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>

#include "config.h"  // Cambiamos  el SSI y la clave en el fichero config.h

const int led = LED_BUILTIN;

WiFiClient espClient;
PubSubClient mqttClient(espClient);


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

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


  mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);
  
  mqttClient.setCallback(callback);

  while (!mqttClient.connected())
  {
    Serial.print("Starting MQTT connection...");
    if (mqttClient.connect(MQTT_CLIENT_NAME))   {
      mqttClient.subscribe("hello/world");  
    }
    else
    {
      Serial.print("Failed MQTT connection, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");

      delay(5000);
    }
  }
  


}

void loop() {

  mqttClient.publish("hello/world", "prueba");
  delay(5000);
  
}
