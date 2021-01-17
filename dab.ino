#include <SoftwareSerial.h>

SoftwareSerial bluetooth(3, 2);
//pins
int moistPin = A0; 
int motorPin = 9; 
//variables
float moistVal = 0.0; //variable that takes in moisture value
int tooDry = 150; //set low parameter for plant
int tooWet = 400; //set high parameter for plant
int received = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(moistPin, INPUT);
  pinMode(motorPin, OUTPUT);
  bluetooth.begin(9600);
}

void loop()
{
  if (bluetooth.available()>0){
    received = bluetooth.read();
  }
  //constantly checking for moisture
  moistVal = analogRead(moistPin);
  
  if(moistVal <= tooDry && received == '1'){
    digitalWrite(motorPin, HIGH);
    delay(1000);
    digitalWrite(motorPin, LOW);
    delay(1000);
    received = 0;
  }
  else if(moistVal >= tooWet && received == '1') {
    digitalWrite(motorPin, HIGH);
    delay(1000);
    digitalWrite(motorPin, LOW);
    delay(1000);
    received = 0;
  }
  Serial.println(moistVal);
  bluetooth.print(moistVal);
  delay(2500);
}
