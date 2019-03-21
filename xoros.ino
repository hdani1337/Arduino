void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() 
{
  byte delayErtek = 255;
  
  PORTB = 0b10101;
  delay(delayErtek);
  PORTB |= 1 << 3;
  delay(delayErtek);
  PORTB &= ~(1 << 2);
  delay(delayErtek);
}
