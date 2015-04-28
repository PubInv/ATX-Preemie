void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

int mq4Pin = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int mq4 = analogRead(mq4Pin);
  Serial.println(mq4);
  delay(500);

}
