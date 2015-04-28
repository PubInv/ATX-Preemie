// This is throw-away code --- this just demonstrates
// using the pressure sensor to activate a motor.
// It is in expectation that the motor will be replaced with 
// a fan, and the pressure sensor replaced with a gas sensor.


//pressure PIN
int pressPin = 0; //the 

//LED Pin
int ledPin = 9;   //the pin the LED is connected to
                  //we are controlling brightness so
                  //we use one of the PWM (pulse width
                  // modulation pins)
                  
int motorPin = 7;

int pwmPin = 5;
void setup()
{
  pinMode(ledPin, OUTPUT); //sets the led pin to output
  pinMode(motorPin,OUTPUT);
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600);
}
/*
* loop() – this function will start after setup
* finishes and then repeat
*/
void loop()
{
  analogWrite(pwmPin,128);
int pressLevel = analogRead(pressPin); //Read the
                                        // presslevel
     
pressLevel = map(pressLevel, 0, 900, 0, 255);
         //adjust the value 0 to 900 to
         //span 0 to 255
pressLevel = constrain(pressLevel, 0, 255);//make sure the
                                           //value is betwween
                                           //0 and 255

analogWrite(ledPin, 128);  //write the value

 Serial.println(pressLevel);
if (pressLevel  < 100) {
  analogWrite(motorPin,255);
  delay(3000);
} else {
  analogWrite(motorPin,0); 
}
delay(500);

}
