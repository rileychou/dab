int moistPin = A0; //pin is A0
int moistVal = 0; //variable that takes in moisture value
int tooDry = 150; //set low parameter for plant
int tooWet = 400; //set high parameter for plant
//int buttonState = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(moistPin, INPUT);
}
void loop()
{
  //constantly checking for moisture
  moistVal = analogRead(moistPin);
  Serial.println(moistVal);
  int percent = 2.718282 * 2.718282 * (.008985 * moistVal + 0.207762); //calculate percent for probes about 1 - 1.5 inches apart
  Serial.print(percent);
  Serial.println("% Moisture ");
  if (moistVal <= tooDry) {
    //motor pulls on rubber band to open the tap, only when button on app clicked
    Serial.println(moistVal);
  }
  else if (moistVal >= tooWet) {
    //move motor to release the tap, only when button on app clicked
    Serial.println(moistVal);
  }
  else {
    //do not move motor
    Serial.println(moistVal);
  }
  delay(2500);
}
