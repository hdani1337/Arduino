float distance;
float time;

void setup() {
  pinMode(10, OUTPUT);//Hangszóró (Trigger)
  pinMode(12, INPUT);//Mikrofon (Echo)
  Serial.begin(9600);
}

void loop() {
  digitalWrite(10, HIGH);
  delayMicroseconds(12);
  digitalWrite(10, LOW);
  time = pulseIn(12, HIGH)/2;//Várakozás a magas jelre
  distance = 343.5 * time / 10000;
  Serial.print(distance); Serial.println(" cm");
  delay(10);//Azt cső
}
