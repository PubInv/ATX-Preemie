// This code placed in the public domain by Engineers Without Borders, Austin Chapter.

// The the temperatures here for a "cold baby" (MIN_TEMP) and "hot baby" (MAX_TEMP).
// If the RGB LED is properly configured on pins 9,10, and 11, and the TMP36 sensor 
// is read by Anolog 0, then the color will indicate the baby's status:
// RED means hot baby
// BLUE means cold baby
// GREEN means just right baby
// Right now if you want to change the window you have to reprogramm it digitally 
// by changing these value.


// I'm using this to save power.  http://www.reddit.com/r/arduino/comments/o5443/so_you_want_an_easy_way_to_save_power/
// On a standard Arduino R3, this won't save much power, but it gets us ready for using a better board in the actual
// application....and the more experience we get with that the better.  The article mentions Arduino-compatible
// non-prototype solutions that may be much superior to Arduino R3s, which are great for prototyping.
#include <avr/io.h>


 const float MAX_TEMP = 26.0;
 const float MIN_TEMP = 24.0;
 
 // This code combined two example from ARDX.
 
 //RGB LED pins
int ledDigitalOne[] = {9, 10, 11}; //the three digital pins of the digital LED 
                                   //9 = redPin, 10 = greenPin, 11 = bluePin

const boolean ON = LOW;     //Define on as LOW (this is because we use a common 
                            //Anode RGB LED (common pin is connected to +5 volts)
const boolean OFF = HIGH;   //Define off as HIGH

//Predefined Colors
const boolean RED[] = {ON, OFF, OFF};    
const boolean GREEN[] = {OFF, ON, OFF}; 
const boolean BLUE[] = {OFF, OFF, ON}; 
const boolean YELLOW[] = {ON, ON, OFF}; 
const boolean CYAN[] = {OFF, ON, ON}; 
const boolean MAGENTA[] = {ON, OFF, ON}; 
const boolean WHITE[] = {ON, ON, ON}; 
const boolean BLACK[] = {OFF, OFF, OFF}; 

//An Array that stores the predefined colors (allows us to later randomly display a color)
const boolean* COLORS[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, BLACK};


//TMP36 Pin Variables
int temperaturePin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade 
                        //(500 mV offset) to make negative temperatures an option
 
void loop()                     // run over and over again
{
 float temperature = getVoltage(temperaturePin);  //getting the voltage reading from the temperature sensor
 temperature = (temperature - .5) * 100;          //converting from 10 mv per degree wit 500 mV offset
                                                  //to degrees ((volatge - 500mV) times 100)
 Serial.println(temperature);                     //printing the result
   if (temperature < MIN_TEMP) {
     setColor(ledDigitalOne,BLUE);
   } else if (temperature > MAX_TEMP) {
     setColor(ledDigitalOne,RED);
   } else {
     setColor(ledDigitalOne,GREEN);
   }
  // Let's flash the LED long enough for people to see it, then go to sleep to save power....
  // Note: If 
// lpDelay(1);
 delay(250);
 setColor(ledDigitalOne,BLACK);
//  lpDelay(7);
 delay(1750);

}
// this code copied from ARDX (thanks!)

/*
 * getVoltage() - returns the voltage on the analog input defined by
 * pin
 */
float getVoltage(int pin){
 return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}

void setup(){
  for(int i = 0; i < 3; i++){
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs
  }
  Serial.begin(9600);  //Start the serial connection with the copmuter
                       //to view the result open the serial monitor 
                       //last button beneath the file bar (looks like a box with an antenae)
}

/* Sets an led to any color
   led - a three element array defining the three color pins (led[0] = redPin, led[1] = greenPin, led[2] = bluePin)
   color - a three element boolean array (color[0] = red value (LOW = on, HIGH = off), color[1] = green value, color[2] =blue value)
*/
void setColor(int* led, boolean* color){
 for(int i = 0; i < 3; i++){
   digitalWrite(led[i], color[i]);
 }
}

/* A version of setColor that allows for using const boolean colors
*/
void setColor(int* led, const boolean* color){
  boolean tempColor[] = {color[0], color[1], color[2]};
  setColor(led, tempColor);
}


/*
  lpDelay(quarterSeconds) - Low Power Delay.  Drops the system clock
                            to its lowest setting and sleeps for 256*quarterSeconds milliseconds.
*/
int lpDelay(int quarterSeconds) {
  int oldClkPr = CLKPR;  // save old system clock prescale
  CLKPR = 0x80;    // Tell the AtMega we want to change the system clock
  CLKPR = 0x08;    // 1/256 prescaler = 60KHz for a 16MHz crystal
  delay(quarterSeconds);  // since the clock is slowed way down, delay(n) now acts like delay(n*256)
  CLKPR = 0x80;    // Tell the AtMega we want to change the system clock
  CLKPR = oldClkPr;    // Restore old system clock prescale
}

