void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  PORTB = 0;
}

void loop() 
{
  for(int i = 0; i <= 31; i++)
  {
    PORTB = i;
    delay(420);
  }
}
