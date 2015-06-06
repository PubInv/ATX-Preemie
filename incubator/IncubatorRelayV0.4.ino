
// This code placed in the public domain by Engineers Without Borders, Austin Chapter.


 const float MAX_TEMP = 38.0;
 const float MIN_TEMP = 34.0;
 const float ALARM_MAX = 37.0;
 const float ALARM_MIN = 20.0; //very low for testing
 
 const int MOSFET_PIN = 9; 
 const int ALARM_PIN = 7;
 
 const int DEBUG_LEVEL = 0;
 
int ledDigitalOne[] = {9, 10, 11}; //the three digital pins of the digital LED 
                                   //9 = redPin, 10 = greenPin, 11 = bluePin

const boolean ON = LOW;     //Define on as LOW (this is because we use a common 
                            //Anode RGB LED (common pin is connected to +5 volts)
const boolean OFF = HIGH;   //Define off as HIGH

//TMP36 Pin Variables
// int temperaturePin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade 
                        //(500 mV offset) to make negative temperatures an option
                        
int speakerPin = 7;

int length = 4; // high notes for high-temp alarm, low notes for low-temp alarm
char highnotes[] = "cga "; 
int beats[] = { 1, 1, 2, 1};

char lownotes[] = "bac "; 

int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}


void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

                        
void sound_hot_alarm()
{
       if (DEBUG_LEVEL > 0) 
         Serial.println("Temperature WAY Too Hot, ALARMING_HOT!"); 
       for (int i = 0; i < length; i++) {
         if (highnotes[i] == ' ') {
           delay(beats[i] * tempo);
         } else {
           playNote(highnotes[i], beats[i] * tempo);
         }
       }
}

void sound_cold_alarm()
{
        if (DEBUG_LEVEL > 0) 
          Serial.println("Temperature WAY Too Cool, ALARMING_COLD!"); 
        for (int i = 0; i < length; i++) {
         if (highnotes[i] == ' ') {
           delay(beats[i] * tempo);
         } else {
           playNote(lownotes[i], beats[i] * tempo);
         }
       };
}
                        
void alarm_if_needed(float temp) {
     if (temp < ALARM_MIN) {
     sound_cold_alarm();
   } else if (temp > ALARM_MAX) {
     sound_hot_alarm();
   }
}
 
void loop()                     // run over and over again
{
 float temperature = getVoltage(A5);  //getting the voltage reading from the temperature sensor
 temperature = (temperature - .5) * 100;          //converting from 10 mv per degree wit 500 mV offset
                                                  //to degrees ((volatge - 500mV) times 100)
 int rawRead = analogRead(A5);
// Serial.println(rawRead);
 
 Serial.print("temp:");
 Serial.println(temperature);                     //printing the result
   if (temperature < MIN_TEMP) {
       if (DEBUG_LEVEL > 0) 
         Serial.println("Temperature Too Cool, turning On!"); 
     digitalWrite(MOSFET_PIN, LOW);
//     turn_MOSFET_ON(100.0);
   } else if (temperature > MAX_TEMP) {
       if (DEBUG_LEVEL > 0) 
         Serial.println("Temperature Too Hot, turning Off!"); 
     digitalWrite(MOSFET_PIN, HIGH);
//     turn_MOSFET_ON(0.0);

   } else {
     // do nothing!
     if (DEBUG_LEVEL > 0) 
         Serial.println("Temperature OK, turning Off!"); 
        digitalWrite(MOSFET_PIN, HIGH);
   }
   alarm_if_needed(temperature);
   delay(1000);
}

void turn_MOSFET_ON(float percent){
  int pwm = (percent * 256) / 100;
  pwm = (pwm > 255) ? 255 : pwm;
  if (DEBUG_LEVEL > 0) 
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
 if (DEBUG_LEVEL > 0) {
   Serial.println("input voltage");
   Serial.println(v);
 }
 return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}

void setup(){
  pinMode(MOSFET_PIN,OUTPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);  //Start the serial connection with the copmuter
                       //to view the result open the serial monitor 
                       //last button beneath the file bar (looks like a box with an antenae)
                       
}
