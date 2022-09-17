#include <Wire.h>
#include "ABlocks_LiquidCrystal_I2C.h"
#include "WiFi.h"
#include <WebServer.h>
#include <Preferences.h>
#include "ABlocks_DHT.h"

double temperatura;
double Accesos;
double humedad;
LiquidCrystal_I2C lcd_1(0x27,16,2);
const char espwifi_ssid[]="OpenWrt";
const char espwifi_pass[]="qazxcvbgtrewsdf";
WebServer http_server;
Preferences eeprom_preferences;
DHT dht14(14,DHT22);

void espwifi_setup(){
	WiFi.mode(WIFI_STA);
	WiFi.begin(espwifi_ssid,espwifi_pass);
	while (WiFi.status() != WL_CONNECTED) delay(500);
}

void http_server_on_(){
	Accesos = (Accesos + 1);
	http_server.send(200,String("text/html"),String("<!DOCTYPE html><HTML><HEAD>")+String("<META ")+String("charset=\"ISO-8859-1\" name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" ")+String(" http-equiv=\"refresh\" content=\"5\" ")+String(" >")+String("<STYLE>")+String("body {background-color: #ffffff;}")+String("</STYLE>")+String("<TITLE>")+String("Tempertura & Humedad - Pepe - Server")+String("</TITLE>")+String("</HEAD><BODY>")+String("<p align=\"center\">")+String("<B>")+String("Temperatura: ")+String("</B>")+String(temperatura)+String(" C")+String("</p>")+String("<BR>")+String("<p align=\"center\">")+String("<B>")+String("Humedad: ")+String("</B>")+String(humedad)+String("%")+String("</p>")+String("<p align=\"center\">")+String("<IMG src=\"")+String("https://icons.iconarchive.com/icons/oxygen-icons.org/oxygen/256/Status-weather-showers-day-icon.png")+String("\" width=\"")+String("")+String("\" height=\"")+String("")+String("\" />")+String("</p>")+String("<div align=\"center\">")+String("<A href=\"")+String("http://www.arduinoblocks.com/web/project/811113")+String("\" target=\"")+String("_self")+String("\">")+String("Proyecto arduinoblocks")+String("</A>")+String("</div>")+String("<p align=\"center\">")+String("Accesos: ")+String((long)(Accesos))+String("</p>")+String("</BODY></HTML>"));
	eeprom_preferences.putDouble(String("accesos").c_str(),(long)(Accesos));
	lcd_1.setCursor(13, 0);
	lcd_1.print((long)(Accesos));

}

void setup()
{
  eeprom_preferences.begin("eeprom", false);
	pinMode(14, INPUT);
	pinMode(2, OUTPUT);
	Serial.begin(115200);
	Serial.flush();
	while(Serial.available()>0)Serial.read();

	dht14.begin();
	http_server.on("/",HTTP_GET,http_server_on_);
	lcd_1.begin();
	lcd_1.noCursor();
	lcd_1.backlight();
	espwifi_setup();
	Serial.println(WiFi.localIP().toString());
	lcd_1.setCursor(0, 0);
	lcd_1.print(WiFi.localIP().toString());
	delay(2000);
	http_server.begin(80);
	Accesos = eeprom_preferences.getDouble(String("accesos").c_str(),0);

}


void loop()
{
	yield();

	http_server.handleClient();
  	temperatura = dht14.readTemperature();
  	humedad = dht14.readHumidity();
  	if ((!isnan(temperatura))) {
  		lcd_1.clear();
  		if ((temperatura < 20)) {
  			lcd_1.setCursor(13, 1);
  			lcd_1.print(String("On "));
  			Serial.println(String("Relé ON"));
  			digitalWrite(2,HIGH);
  		}
  		else {
  			lcd_1.setCursor(13, 1);
  			lcd_1.print(String("Off"));
  			Serial.println(String("Relé Off"));
  			digitalWrite(2,LOW);
  		}

  		Serial.println(String("Temp:")+String(temperatura)+String("º C"));
  		lcd_1.setCursor(0, 0);
  		lcd_1.print(String("T:")+String(temperatura)+String(" C"));
  		Serial.println(String("Hum:")+String(humedad)+String(" %"));
  		lcd_1.setCursor(0, 1);
  		lcd_1.print(String("H:")+String(humedad)+String("%"));
  		lcd_1.setCursor(13, 0);
  		lcd_1.print((long)(Accesos));
  		Serial.println(String("Error leyendo sensor DHT22"));
  	}
  	else {
  		lcd_1.clear();
  		Serial.println(String("Error leyendo sensor DHT22"));
  		lcd_1.setCursor(0, 0);
  		lcd_1.print(String("Error leyendo sensor DHT22"));
  	}

  	delay(1000);

}