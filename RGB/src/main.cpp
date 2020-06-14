#include <Arduino.h>

int RED = 9;
int GREEN = 10;
int BLUE = 11;

void setColor(int red, int green, int blue);

void setup() {
    Serial.begin(9600);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
}

void loop() {
  int r = random(255);
  int g = random(255);
  int b = random(255);
  setColor(r, g, b);
  delay(1000);
}

void setColor(int red, int green, int blue) {
  digitalWrite(BLUE, blue);
  digitalWrite(GREEN, green);
  digitalWrite(RED, red);
}