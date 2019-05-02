byte trig = 6;
byte echo = 7;
byte red = 11;
byte green = 12;
byte blue = 13;
float distance;
float time;

void setup() {
  pinMode(trig, OUTPUT);//Hangszóró (Trigger)
  pinMode(echo, INPUT);//Mikrofon (Echo)
  pinMode(blue,OUTPUT); //Kék
  pinMode(green,OUTPUT); //Zöld
  pinMode(red,OUTPUT); //Piros
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(12);
  digitalWrite(trig, LOW);
  time = pulseIn(echo, HIGH)/2;//Várakozás a magas jelre
  distance = 343.5 * time / 10000;
  Serial.print(distance); Serial.println(" cm");
  
  if(distance <= 10 || distance >= 200) 
  {
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  }
  
  else if (distance >= 10 && distance <= 50)
  {
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
  }
  
  else 
  {
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  }
  
  delay(10);//Azt cső
}
