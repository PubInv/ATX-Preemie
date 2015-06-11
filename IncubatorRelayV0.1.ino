// This code placed in the public domain by Engineers Without Borders, Austin Chapter.


 const float MAX_TEMP = 38.0;
 const float MIN_TEMP = 34.0;
 const int MOSFET_PIN = 9; 
 
int ledDigitalOne[] = {9, 10, 11}; //the three digital pins of the digital LED 
                                   //9 = redPin, 10 = greenPin, 11 = bluePin

const boolean ON = LOW;     //Define on as LOW (this is because we use a common 
                            //Anode RGB LED (common pin is connected to +5 volts)
const boolean OFF = HIGH;   //Define off as HIGH

//TMP36 Pin Variables
int temperaturePin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade 
                        //(500 mV offset) to make negative temperatures an option
 
void loop()                     // run over and over again
{
 float temperature = getVoltage(A5);  //getting the voltage reading from the temperature sensor
 temperature = (temperature - .5) * 100;          //converting from 10 mv per degree wit 500 mV offset
                                                  //to degrees ((volatge - 500mV) times 100)
 int rawRead = analogRead(A5);
 Serial.println(rawRead);
 Serial.println(temperature);                     //printing the result
   if (temperature < MIN_TEMP) {
     Serial.println("Temperature Too Cool, turning On!"); 
     digitalWrite(MOSFET_PIN, LOW);
//     turn_MOSFET_ON(100.0);
   } else if (temperature > MAX_TEMP) {
     Serial.println("Temperature Too Hot, turning Off!"); 
     digitalWrite(MOSFET_PIN, HIGH);
//     turn_MOSFET_ON(0.0);

   } else {
     // do nothing!
     Serial.println("Temperature OK, turning Off!"); 
          digitalWrite(MOSFET_PIN, HIGH);
   }
   delay(1000);
}

void turn_MOSFET_ON(float percent){
  int pwm = (percent * 256) / 100;
  pwm = (pwm > 255) ? 255 : pwm;
  Serial.println(pwm);
  analogWrite(MOSFET_PIN, pwm);
}

// this code copied from ARDX (thanks!)

/*
 * getVoltage() - returns the voltage on the analog input defined by
 * pin
 */
float getVoltage(int pin){
 int v = analogRead(A5);
 Serial.println("input voltage");
 Serial.println(v);
 return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}

void setup(){
  pinMode(MOSFET_PIN,OUTPUT);
  Serial.begin(9600);  //Start the serial connection with the copmuter
                       //to view the result open the serial monitor 
                       //last button beneath the file bar (looks like a box with an antenae)
}


