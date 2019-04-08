byte allapot[] = {0b10001,0b01011,0b01100,0b01010};
byte ido[] = {5,1,3,1};
volatile byte ok = 1;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), ON,  RISING);
  attachInterrupt(digitalPinToInterrupt(3), OFF, RISING); 
  DDRB = 0b11111111;
  PORTB = 63;
  delay(1000);
}

void ON() {
   ok = 1;
}
void OFF() {
   ok = 0;
}


void loop() {
  PORTB=0;
  
  if (ok == 1){
    for(byte i = 0; i < sizeof(allapot); i++)
    {
      PORTB = allapot[i];
      delay(ido[i] * 1000);  
    }
  }

  else
  {
    digitalWrite(9,LOW);
    delay(300);
    digitalWrite(9,HIGH);
    delay(300);
  }
}
