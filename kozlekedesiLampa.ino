void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);//autó piros
  pinMode(9, OUTPUT);//autó sárga
  pinMode(10, OUTPUT);//autó zöld
  pinMode(11, OUTPUT);//gyalogos piros
  pinMode(12, OUTPUT);//gyalogos zöld
  PORTB = 63;
  delay(1000);
  PORTB=0;
}

void loop() {
  //autó piros, gyalogos zöld
  Serial.println("Autó piros, Gyalogos zöld");
  digitalWrite(11,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  delay(5000);
  
  //gyalogos zöld, villog, autó sárga
  Serial.println("Autó sárga, Gyalogos zöld villog");
  digitalWrite(9,HIGH);
  for(byte i = 0; i < 4; i++)
  {
    digitalWrite(12,!digitalRead(12));
    delay(500);
  }
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  //késleltetés, hogy ne egyből legyen zöld a gyalogos után
  Serial.println("Autó sárga, Gyalogos piros");
  delay(1000);

  //autó zöld
  Serial.println("Autó zöld, Gyalogos piros");
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(5000);

  //autó sárga
  Serial.println("Autó sárga, Gyalogos piros");
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(9,LOW);
  delay(2000);
}
