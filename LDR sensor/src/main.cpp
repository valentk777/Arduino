#include <Arduino.h>

const byte ledPin = 13;
const byte ldrPin = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop()
{
  byte ldrStatus1 = analogRead(ldrPin);
  if (ldrStatus1 <= 100)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
