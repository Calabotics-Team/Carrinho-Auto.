#include <HCSR04.h>
#include <Servo.h>
#define echoPin 12 // recebedor do ultrassom
#define triggerPin 13 // gatilho de som ultrassônico
#define roda1H 4 //esquerdo dianteiro
#define roda1A 5 //esquerdo traseiro
#define roda2A 6 //direito traseiro
#define roda2H 7 //direito dianteiro

// -------- OBJECTS ----------
Servo myservo;
float duration;
float distance;
unsigned long currentMillis;
unsigned long startMillis = 0;
const unsigned long gap = 2;
// ------ METHODS --------
bool detects () {
    if (duration > 0) {
      return true;
    } else {
      return false;
    }
  }
bool temCoisaDosLados(){

 bool temNaDireita=false;
 bool temNaEsquerda=false;

 myservo.write(45);
  if (distance <= 10) {
    temNaDireita=true;
    myservo.write(90);
    myservo.write(135);
      if (distance <= 10) {
      temNaEsquerda=true;
     }
    return true;
  }
    myservo.write(90);
    return false;
  }

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
myservo.attach(11);
//----------------------------
//----- TIME COUNTER ---------
startMillis = millis();
}

void loop(){

  currentMillis = millis();

  digitalWrite(triggerPin, LOW);

  if (currentMillis - startMillis >= gap) {
    digitalWrite(triggerPin, HIGH);
    startMillis = currentMillis;
    startMillis = 0;
      if (currentMillis >= 1000) {
        digitalWrite(triggerPin, LOW);
        duration = pulseIn(echoPin, HIGH);
        distance = (duration * 0.0343) / 2;
        temCoisaDosLados();

      while (temCoisaDosLados() == false) {
        digitalWrite(roda1A, HIGH);
        digitalWrite(roda2A, HIGH);
      }

      digitalWrite(roda1A, LOW);
      digitalWrite(roda2A, LOW);

      temCoisaDosLados();

      if (temCoisaDosLados() == true && distance < 5){
        startMillis = currentMillis;
        digitalWrite(roda1H, HIGH);
        digitalWrite(roda2H, HIGH);
          if (currentMillis - startMillis >= 500) {
            digitalWrite(roda1H, LOW);
            digitalWrite(roda2H, LOW);
          }
        startMillis = currentMillis;
        digitalWrite(roda1H, HIGH);
        digitalWrite(roda2A, HIGH);
      }
    if (currentMillis - startMillis >= 1000) {
      digitalWrite(roda1H, LOW);
      digitalWrite(roda2A, LOW);
    }
    startMillis = currentMillis;
    }
  }
}