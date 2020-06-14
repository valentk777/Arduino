#include <Arduino.h>
#include <string.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

char oldValue = 'N';
bool gameStarted = false;

void checkValue(char v);

void setup()
{
    pinMode(SW_pin, INPUT);
    //   Serial.begin(115200);
    Serial.begin(9600);
}

void loop()
{
    int res = analogRead(X_pin);

    if (res > 700)
        checkValue('D');
    else if (res < 400)
        checkValue('U');
    else
        checkValue('N');
}

void checkValue(char v)
{
    if (oldValue != v)
    {
        Serial.println(v);
        oldValue = v;
    }
}
