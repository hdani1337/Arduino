#include <SimpleDHT.h>
SimpleDHT11 dht11;
float t, h;

void setup() {
  pinMode(11,OUTPUT);    // kék
  pinMode(12,OUTPUT);    // zöld
  pinMode(13,OUTPUT);    // piros
  pinMode(8,OUTPUT);     // relé
  digitalWrite(8, HIGH);    delay(1000);  digitalWrite(8, LOW);   // relé teszt
  Serial.begin(9600);    // soros port
}

void loop() {
  if (dht11.read2(7, &t, &h, NULL) == 0) {                 /* hiba > 0! */
     //&t és &h-ban történik meg az érékátadás
     //olyan, mintha globális változók lennének, nem paraméterek
     Serial.print(t,2); Serial.print("°C, "); //Celsius fok
     Serial.print(h,2); Serial.println("%");  //Páratartalom
  }  
  
  digitalWrite(12, HIGH); //Zöld fel
  digitalWrite(11, LOW);  //Kék le
  digitalWrite(13, LOW);  //Piros le
  
  if (t > 29) {
    digitalWrite(12, LOW);  
    digitalWrite(11, HIGH);  
    digitalWrite(8, HIGH); 
  }   //Zöld le, Kék fel, Relé fel
  
  else { 
    digitalWrite(8, LOW); 
  }  //Relé le
  
  if (h > 60) {
    digitalWrite(12, LOW);  digitalWrite(13, HIGH); 
  }  //Zöld le, Piros fel
  
  delay(2000);  
}
