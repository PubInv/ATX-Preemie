// Very simple sketch to test the driving a motor with a MOSFET:
// http://bildr.org/2012/03/rfp30n06le-arduino/

const int MOSFET_GATE_PIN = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(MOSFET_GATE_PIN,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 100; i++) {
    analogWrite(MOSFET_GATE_PIN, (i*255)/100);
    Serial.println(i);
    delay(200);
  }
}

