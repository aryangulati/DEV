#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
int sensor=7; //The output of PIR sensor connected to pin 7
int push_switch=6; // push button switch connected to pin 6
int buzzer=8; // buzzer connected at pin 8
int sensor_value; //variable to hold read sensor value
int sms_count=0;
void setup()
{
pinMode(sensor,INPUT); // configuring pin 7 as Input
pinMode(push_switch,INPUT); // configuring pin 6 as Input
pinMode(buzzer,OUTPUT); // configuring pin 8 as OUTPUT
mySerial.begin(9600);
}

void loop()
{
Check_Burglar();// subroutine to check sensor status and activation of outputs
Check_Reset(); // subroutine to check if alarm reset switch pressed or not
}

void Check_Burglar()
{
sensor_value=digitalRead(sensor); // Reading sensor value from pin 7
if(sensor_value==HIGH) // Checking if PIR sensor sends a HIGH signal to Arduino
{
  digitalWrite(buzzer,HIGH); // Activating the buzzer 
  while(sms_count<3) //Number of SMS Alerts to be sent limited at 3
    {  
      SendTextMessage(); // Function to send AT Commands to GSM module
    }
}}
void Check_Reset()
{
if(digitalRead(push_switch==HIGH))// Checking if pushbutton was pressed 
{
digitalWrite(buzzer,LOW); // turning OFF the buzzer 
sms_count=0; // Reactivating the SMS Alert Facility
}}
void SendTextMessage()
{
  mySerial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  mySerial.println("AT+CMGS=\"+919867936816\"\r"); // change to the phone number you using 
  delay(1000);
  mySerial.println("Motion detected!");//the content of the message
  delay(200);
  mySerial.println((char)26);//the stopping character
  delay(1000);
  sms_count++;
  
  
}
