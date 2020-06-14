#include <Arduino.h>
#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM900
SoftwareSerial SIM900(7, 8); //SIM900 Tx & Rx is connected to Arduino #7 & #8
bool stop = false;
String incomingData;   // for storing incoming serial data
String message = "";   // A String for storing the message

void GsmConnected();
void SendMessage(const char text[]);
void DelAllSMS();
void UpdateSerial();
void UpdateSIM900Serial();
void send_message(String message);
void receive_message();

void setup()
{
  Serial.begin(9600);
  SIM900.begin(9600);
  GsmConnected();
  delay(20000); // Needed for smoke sensor
}

void loop()
{
  receive_message();
  if (!stop) {
    send_message("vanduo aptiktas");
    stop = true;
  }

  delay(1000);
  Serial.print("Done");
}

//----------------------------------------------
// Gsm commands
//----------------------------------------------

void GsmConnected()
{
  SIM900.println("AT+CMGF=1\r"); // Configuring TEXT mode
  delay(1000);
  // NOTE: this was changed!!!!!
  // SIM900.println("AT+CNMI=2,2,0,0,1\r"); // Decides how newly arrived SMS messages should be handled
  SIM900.println("AT+CNMI=2,2,0,0,0\r"); // Decides how newly arrived SMS messages should be handled
  delay(1000);
  UpdateSIM900Serial();
  // DelAllSMS();
}

void SendMessage(const char text[])
{
  // Change to your number
  SIM900.println("AT+CMGS=\"+37062217160\"\r");
  delay(1000);
  SIM900.print(text);
  delay(100);
  SIM900.write(26);
  delay(1000);
  // UpdateSIM900Serial();
}

void send_message(String message)
{
  SIM900.println("AT+CMGF=1");    //Set the GSM Module in Text Mode
  delay(100);  
  SIM900.println("AT+CMGS=\"+923030502311\""); // Replace it with your mobile number
  delay(100);
  SIM900.println(message);   // The SMS text you want to send
  delay(100);
  SIM900.println((char)26);  // ASCII code of CTRL+Z
  delay(100);
  SIM900.println();
  delay(1000);  
}

void receive_message()
{
  if (SIM900.available() > 0)
  {
    incomingData = SIM900.readString(); // Get the data from the serial port.
    Serial.print(incomingData); 
    delay(10); 
  }
}

void DelAllSMS()
{
  // Serial.println("AT+CMGD=1,4");  //Delete all SMS in box
  SIM900.print("AT+CMGDA=\"");
  SIM900.println("DEL ALL\"");
  delay(500);
  Serial.println("All Messages Deleted");
}

//----------------------------------------------
// Memory management
//----------------------------------------------
void UpdateSIM900Serial()
{
  delay(1000);
  while (SIM900.available())
    // SIM900.read();
    Serial.write(SIM900.read());
  delay(1000);
}

void UpdateSerial()
{
  delay(1000);
  while (Serial.available())
    Serial.read();
  delay(1000);
}
