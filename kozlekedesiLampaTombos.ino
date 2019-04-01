byte allapot[] = {0b10001,0b01011,0b01100,0b01010};
byte ido[] = {5,1,3,1};

void setup() {
  DDRB = 0b11111111;
  PORTB = 63;
  delay(1000);
  PORTB=0;
}

void loop() {
  for(byte i = 0; i < sizeof(allapot); i++)
  {
    PORTB = allapot[i];
    delay(ido[i] * 1000);  
  }
}
