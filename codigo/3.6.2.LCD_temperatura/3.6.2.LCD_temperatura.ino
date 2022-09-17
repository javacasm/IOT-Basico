// Combinamos el ejemplo del sensor TMP36 y el Hello World delLCD


#include <TMP36.h>
#include <LCD_I2C.h>

//Create an instance of the TMP36 class and 
//define the pin the sensor is connected to
//If using 3.3v Arduino, change 5 to 3.3
TMP36 myTMP36(4, 3.3); 

LCD_I2C lcd(0x27); // Configuramos la direccion de nuestro LCD

void setup() {
    Serial.begin(115200);

    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
}

void loop() {
  //create a variable and store the current temperature in
  //celsius in it using the getTempC function
  float celsius = myTMP36.getTempC(); 
  
  //create a variable and store the current temperature in
  //fahrenheit in it using the getTempF function
  float fahrenheit = myTMP36.getTempF(); 

  //Print the data to the Serial monitor
  Serial.print("Celsius: ");
  Serial.print(celsius);
  lcd.setCursor(2,0);
  lcd.print("Temperatura");
  lcd.setCursor(5, 1); // 
  lcd.print(celsius);
  delay(500);
}
