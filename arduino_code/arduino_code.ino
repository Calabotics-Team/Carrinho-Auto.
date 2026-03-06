#include <HCSR04.h>
#include <Servo.h>
#define echoPin 12 // recebedor do ultrassom
#define triggerPin 13 // gatilho de som ultrassônico
#define roda1H 4 //esquerdo dianteiro
#define roda1A 5 //esquerdo traseiro
#define roda2A 6 //direito traseiro
#define roda2H 7 //direito dianteiro

void setup(){

//------- I / O ---------
pinMode(triggerPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(roda1H, OUTPUT);
pinMode(roda1A, OUTPUT);
pinMode(roda2H, OUTPUT);
pinMode(roda2A, OUTPUT);
//--------------------
//----- ENGINE ATTACH -------
servo.attach(11);
//----------------------------
// -------- OBJECTS ----------
float duration;
float distance;
Servo servo;
// -------------------------
// ------ METHODS --------
bool detects () {
    if (duration > 0) {
      return true;
    } else {
      return false;
    }
  }
void temCoisaDosLados(){
  bool temNaDireita=false;
  bool temNaEsquerda=false;
  myservo.write(45);
  if (distance <= 10) {
    temNaDireita=true;
  }
  myservo.write(90);
  myservo.write(135);
  if (distance <= 10) {
    temNaEsquerda=true;
  }
  myservo.write(90);
  }
//-----------------------------
}

void loop(){

  digitalWrite(triggerPin, LOW);
  millis(2);

  digitalWrite(triggerPin, HIGH);
  millis(10);

  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;
  detects();

  while (detects() = false || distance >= 5) {
    digitalWrite(roda1A, HIGH);
    digitalWrite(roda2A, HIGH);
  }
  digitalWrite(roda1A, LOW);              // SERVO OPERATIONS STILL MISSING, NEEDS TO BE FIXED!
  digitalWrite(roda2A, LOW);
  millis(1000);
  if (detects() = true && distance < 5){
    digitalWrite(roda1H, HIGH);
    digitalWrite(roda2H, HIGH);
    millis(500);
    digitalWrite(roda1H, LOW);
    digitalWrite(roda2H, LOW);
    millis(500);
    digitalWrite(roda1H, HIGH);
    digitalWrite(roda2A, HIGH);
  }
  digitalWrite(roda1H, LOW);
  digitalWrite(roda2A, LOW);
  millis(1000);
}
