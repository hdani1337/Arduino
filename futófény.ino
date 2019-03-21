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
  PORTB = 1;
  byte delayErtek = 75;
  delay(delayErtek);

  for(int i = 1; i <= 4; i++)
  {
    PORTB = 1 << i;
    delay(delayErtek);
  }

  for(int i = 4; i > 0; i--)
  {
    PORTB = 1 << i;
    delay(delayErtek);
  }
}
