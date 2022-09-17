const int tempPin = 4;     //Pin del sensor TMP36

void setup(){
  Serial.begin(115200);
}
void loop(){
  int tempVal = analogRead(tempPin);
  float volts = tempVal/1023.0;        // normalizamos a 0-1.0
  float temp = volts*33-5;             // aplicamos la formula del fabricante
  Serial.print("temperatura: "); 
  Serial.print(temp);                  
  Serial.println (" grados C");       
  delay(1000);                         
}
