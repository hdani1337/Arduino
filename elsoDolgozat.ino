//HORVÁTH DÁNIEL A CSOPORT

/*
  1. Induláskor villogjon a PIROS LED 4x, 200ms sebességgel, kapcsoljon le, majd utána világítson a ZÖLD LED.
  2. Az első nyomógomb megnyomására kapcsoljon le a ZÖLD LED és a PIROS LED folyamatosan villogjon. 
  3. A másik nyomógomb megnyomására álljon vissza az eredeti állapot (ZÖLD ON, PIROS OFF)
  4. Írja ki a konzolra az első nyomógomb lenyomásainak számát.
*/


byte piros = 8;
byte zold = 9;
byte elsoCount = 0;

volatile byte ok = 1;

int ledState = HIGH;         
int buttonState;             
int lastButtonState = LOW;   

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup() 
{
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(3), ON,  RISING);
  attachInterrupt(digitalPinToInterrupt(2), OFF, RISING); 

  DDRB = 0b11111111;
  PORTB = 0;

  for(byte i = 0; i < 4; i++)
  {//1.feladat
    PORTB = 01;
    delay(200);
    PORTB = 00;
    delay(200);
  }

  delay(50);
}

void ON() 
{
  ok = 1;
}

void OFF() 
{
  ok = 0;

  int reading = digitalRead(2);
 
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) elsoCount++;

  lastButtonState = reading;
}


void loop() 
{

  if (ok == 1)
  {//3. feladat
    PORTB = 10;
  }

  else
  {//2. feladat
    PORTB = 01;
    delay(200);
    PORTB = 00;
    delay(200);
  }

  Serial.println(elsoCount);//4. feladat
}
