#include <Arduino.h>
#include <string>

const int LED_BUILTIN = 2;
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;


// LED fading table from https://www.mikrocontroller.net/articles/LED-Fading
const uint16_t pwmtable_8D[32] PROGMEM =
{
    0, 1, 2, 2, 2, 3, 3, 4, 5, 6, 7, 8, 10, 11, 13, 16, 19, 23,
    27, 32, 38, 45, 54, 64, 76, 91, 108, 128, 152, 181, 215, 255
};


void setup() {
  Serial.begin(9600);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);
}


void dimm()
{
  for (int dutyCycle = 0; dutyCycle < 32; dutyCycle++) {
    ledcWrite(ledChannel, pwmtable_8D[dutyCycle]);
    delay(5);
  }
 
  for (int dutyCycle = 31; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledChannel, pwmtable_8D[dutyCycle]);
    delay(5);
  }

}

void loop() {
  dimm();

  std::string hello;
  hello = "Matthias";

  Serial.println("Hello world!");

  delay(200);
}