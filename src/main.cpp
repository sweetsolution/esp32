#include <Arduino.h>
#include <string>

const int LED_BUILTIN = 2;
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;


void setup() {
  Serial.begin(9600);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);
}


void dimm()
{
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(ledChannel, dutyCycle);
    delay(7);
  }
 
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledChannel, dutyCycle);
    delay(7);
  }

}

void loop() {
  dimm();

  std::string hello;
  hello = "Matthias";

  Serial.println("Hello world!");

  delay(1000);
}

