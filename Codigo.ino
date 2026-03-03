#include <HCSR04.h>
UltraSonicDistanceSensor distanceSensor(12, 13); 
#define roda1H 4 //esquerdo dianteiro
#define roda1A 5 //esquerdo traseiro
#define roda2A 6 //direito traseiro
#define roda2H 7 //direto dianteiro
void setup(){
pinMode(roda1H, OUTPUT);
pinMode(roda1A, OUTPUT);
pinMode(roda2H, OUTPUT);
pinMode(roda2A, OUTPUT);
pinMode(11, OUTPUT);

distanceSensor.measureDistanceCm(); 
}

void loop(){
  while(distanceSensor.measureDistanceCm()>=5){
    digitalWrite(roda1A, HIGH);
    digitalWrite(roda2A, HIGH);
    
  }
  digitalWrite(roda1A, LOW);
  digitalWrite(roda2A, LOW);
  delay(1000);
  while(distanceSensor.measureDistanceCm()<5){
    digitalWrite(11, HIGH);
    digitalWrite(roda1H, HIGH);
    digitalWrite(roda2H, HIGH);
    delay(500);
    digitalWrite(roda1H, LOW);
    digitalWrite(roda2H, LOW);
    delay(500);
    digitalWrite(roda1H, HIGH);
    digitalWrite(roda2A, HIGH);
    
  }
    digitalWrite(roda1H, LOW);
    digitalWrite(roda2A, LOW);
    digitalWrite(11, LOW);
    delay(1000);
}
 
