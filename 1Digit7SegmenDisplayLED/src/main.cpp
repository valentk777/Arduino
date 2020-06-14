#include <Arduino.h>

/*
      A 
      | 
      ___
F -> |___| <- B
E -> |_G_| <- C
       |  * <- DP
      D
*/
int E = 13;
int D = 12;
int C = 11;
int DP = 10;
int B = 9;
int A = 8;
int F = 7;
int G = 6;

void one();
void two();
void three();

void setup()
{
    Serial.begin(9600);
    pinMode(E, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(DP, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(A, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
}

void loop()
{
    one();
    delay(1000);
    two();
    delay(1000);
    three();
    delay(1000);
}

void one()
{
    digitalWrite(E, LOW);
    digitalWrite(D, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(A, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
}

void two()
{
    digitalWrite(E, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(A, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
}

void three()
{
    digitalWrite(E, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(A, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
}
