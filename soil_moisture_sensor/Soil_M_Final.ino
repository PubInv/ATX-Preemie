/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = A0; 
int sensorValue = 0;

void setup() {
  Serial.begin(9800);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
 
}

void loop () {
  sensorValue = analogRead(sensorPin);
  float moisture = (sensorValue * -0.033) + 36.172 ; // Air = 1023 & At 26% = 273
  Serial.println(sensorValue);
  if (sensorValue <=1023 && sensorValue>1006){
    lcd.setCursor(0,0);
    lcd.print("0-2.5%  ");
  }
   if (sensorValue <=1006 && sensorValue>944){
    lcd.setCursor(0,0);
    lcd.print("2.5-5%  ");
  }
  if (sensorValue <=944 && sensorValue>869){
    lcd.setCursor(0,0);
    lcd.print("5-7.5%  ");
  }
  if (sensorValue <=869 && sensorValue>793){
    lcd.setCursor(0,0);
    lcd.print("7.5-10% ");
  }
  if (sensorValue <=793 && sensorValue>717){
    lcd.setCursor(0,0);
    lcd.print("10-12.5%");
  }
  if (sensorValue <=717 && sensorValue>641){
    lcd.setCursor(0,0);
    lcd.print("12.5-15%");
  }
  if (sensorValue <=641 && sensorValue>565){
    lcd.setCursor(0,0);
    lcd.print("15-17.5%");
  }
  if (sensorValue <=565 && sensorValue>490){
    lcd.setCursor(0,0);
    lcd.print("17.5-20%");
  }
  if (sensorValue <=490 && sensorValue>414){
    lcd.setCursor(0,0);
    lcd.print("20-22.5%");
  }
  if (sensorValue <=414 && sensorValue>338){
    lcd.setCursor(0,0);
    lcd.print("22.5-25%");
  }
  if (sensorValue <=338){
    lcd.setCursor(0,0);
    lcd.print(">25%   ");
  }  
  delay(1000);
  
}


