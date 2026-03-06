#include <Servo.h>
#include <HCSR04.h>
UltraSonicDistanceSensor distanceSensor(12, 13); 
#define roda1H 4 //esquerdo dianteiro
#define roda1A 5 //esquerdo traseiro
#define roda2A 6 //direito traseiro
#define roda2H 7 //direto dianteiro
int pos =0;
unsigned long tempomudanca = 0;
Servo myservo;
void setup(){
pinMode(roda1H, OUTPUT);
pinMode(roda1A, OUTPUT);
pinMode(roda2H, OUTPUT);
pinMode(roda2A, OUTPUT);
myservo.attach(11);
distanceSensor.measureDistanceCm(); 
}

void loop(){
 while(distanceSensor.measureDistanceCm()>=10){
   digitalWrite(roda1A, HIGH);
   digitalWrite(roda2A, HIGH);
 }
   digitalWrite(roda1A, LOW);
   digitalWrite(roda2A, LOW);
   temCoisaDosLados();
  
}
void temCoisaDosLados(){
  bool temNaDireita=false;
  bool temNaEsquerda=false;
  myservo.write(45);
  if(distanceSensor.measureDistanceCm()<=10){
    temNaDireita=true;
  }
  myservo.write(90);
  myservo.write(135);
  if(distanceSensor.measureDistanceCm()<=10){
    temNaEsquerda=true;
  }
  myservo.write(90);
  
}

void gire(bool temNaDireita, bool temNaEsquerda){
  if(temNaDireita && temNaEsquerda){
    digitalWrite(roda1H, HIGH);
    digitalWrite(roda2H, HIGH);
    if(millis()-tempomudanca==1000){
      tempomudanca=millis();
      digitalWrite(roda1H, LOW);
      digitalWrite(roda2H, LOW);
    }
    temCoisaDosLados();
  }else if(temNaDireita){
    digitalWrite(roda1H, HIGH);
    digitalWrite(roda2A, HIGH);
     if(millis()-tempomudanca==1000){
      tempomudanca=millis();
      digitalWrite(roda1H, LOW);
      digitalWrite(roda2A, LOW);
     }
   }else if(temNaEsquerda){
    digitalWrite(roda2H, HIGH);
    digitalWrite(roda1A, HIGH);
    if(millis()-tempomudanca==1000){
      tempomudanca=millis();
      digitalWrite(roda2H, LOW);
      digitalWrite(roda1A, LOW);
    }
  }
}

 
