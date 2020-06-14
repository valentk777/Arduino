#include <Arduino.h>
#include "IRremote.h"

#define code0 16738455 // 0 as ON/OFF
#define code1 16724175 // 1
#define code2 16718055 // 2
#define code3 16743045 // 3

int RECEIVER = 11;
int LED0 = 4;
int LED1 = 13;
int LED2 = 8;
int LED3 = 7;
int itsONled[] = {0, 0, 0, 0};

IRrecv irrecv(RECEIVER);
decode_results results;

void setup()
{
    Serial.begin(9600);
    Serial.println("IR RECEIVER Button Decode");
    irrecv.enableIRIn();
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}

void changeState(int &state, int led)
{
    if (state)
    {
        digitalWrite(led, LOW);
        state = 0;
    }
    else
    {
        digitalWrite(led, HIGH);
        state = 1;
    }
}
void loop()
{
    if (irrecv.decode(&results)) // have received an IR signal
    {
        switch (results.value)
        {
        case code0:
            changeState(itsONled[0], LED0);
            break;
        case code1:
            changeState(itsONled[1], LED1);
            break;
        case code2:
            changeState(itsONled[2], LED2);
            break;
        case code3:
            changeState(itsONled[3], LED3);
            break;
        default:
            break;
        }
        Serial.println(results.value, DEC);
        Serial.println(results.decode_type);
        irrecv.resume(); //receive new value
    }
}