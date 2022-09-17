#include "WiFi.h"
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "ABlocks_DHT.h"

String s_msg2;
String s_msg;
const char espwifi_ssid[]="OpenWrt";
const char espwifi_pass[]="qazxcvbgtrewsdf";
const char telegram_token[]="1005959855:AAFNsMCboucdaEi8awQlP_EuauPPJLtXptA";
WiFiClientSecure telegram_wifi_client;
UniversalTelegramBot telegram_bot(telegram_token, telegram_wifi_client);
String telegram_message_text="";
String telegram_message_chatid="";
String telegram_message_fromname="";
unsigned long telegram_last_update;
DHT dht14(14,DHT22);
unsigned long task_time_ms=0;

void espwifi_setup(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(espwifi_ssid,espwifi_pass);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void telegram_messages_getupdates(){
  if( (millis()-telegram_last_update)>=1000){
    int numNewMessages = telegram_bot.getUpdates(telegram_bot.last_message_received + 1);
    for (int i = 0; i < numNewMessages; i++){
      telegram_message_text=telegram_bot.messages[i].text;
      telegram_message_chatid=telegram_bot.messages[i].chat_id;
      telegram_message_fromname=telegram_bot.messages[i].from_name;

  s_msg2 = String("Hola ")+String(telegram_message_fromname)+String(" dices... ")+String(telegram_message_text);
  Serial.println(String("Telegram>> ")+String(s_msg2));
  telegram_bot.sendMessage(telegram_message_chatid,s_msg2,"Markdown");

    }
    telegram_last_update=millis();
  }
}

void setup()
{
    pinMode(14, INPUT);
  Serial.begin(115200);
  Serial.flush();
  while(Serial.available()>0)Serial.read();

  dht14.begin();
  espwifi_setup();
  Serial.println(String("Conectado al wifi con IP: ")+String(WiFi.localIP().toString()));
  telegram_wifi_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  Serial.println(String("Conectado a Telegram"));

}


void loop()
{
  yield();

  telegram_messages_getupdates();
    if((millis()-task_time_ms)>=1000){
      task_time_ms=millis();
      s_msg = String("Temperatura: ")+String(dht14.readTemperature())+String(" Humedad: ")+String(dht14.readHumidity());
      Serial.println(s_msg);
      telegram_bot.sendMessage(String("4545003"),s_msg,"Markdown");
    }

}
