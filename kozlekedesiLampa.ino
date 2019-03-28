void setup() {
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
  digitalWrite(11,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  delay(5000);
  
  //gyalogos zöld, villog, autó sárga
  digitalWrite(9,HIGH);
  for(byte i = 0; i < 4; i++)
  {
    digitalWrite(12,!digitalRead(12));
    delay(500);
  }
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  //késleltetés, hogy ne egyből legyen zöld a gyalogos után
  delay(1000);

  //autó zöld
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(5000);

  //autó sárga
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(9,LOW);
}
