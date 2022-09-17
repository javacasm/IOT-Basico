// the number of the LED pin
const int ledPin = 2;  // GPIO02 es el Led de la placa


// Coniguración del PWM
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
 
void setup(){
  // configuramos el canal PWM 
  ledcSetup(ledChannel, freq, resolution);
  
  // Conectamos el canal al pin del LED
  ledcAttachPin(ledPin, ledChannel);
}
 
void loop(){
  // Aumentamos el brillo
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(ledChannel, dutyCycle);
    delay(2);
  }

  // disminiumos el brillo
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledChannel, dutyCycle);   
    delay(2);
  }
}
