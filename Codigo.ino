#include <Servo.h>
#include <HCSR04.h>

#define roda1H 4 // esquerdo dianteiro
#define roda1A 5 // esquerdo traseiro
#define roda2A 6 // direito traseiro
#define roda2H 7 // direito dianteiro

UltraSonicDistanceSensor distanceSensor(12, 13);

Servo myservo;

unsigned long tempomudanca = 0;

int distancia;



void setup() {

  Serial.begin(9600); //Inicia a comunicação do arduino com o sensor

  pinMode(roda1H, OUTPUT); 
  pinMode(roda1A, OUTPUT);
  pinMode(roda2H, OUTPUT);
  pinMode(roda2A, OUTPUT);
  myservo.attach(11);

  myservo.write(90);

}



void loop() {

  distancia = distanceSensor.measureDistanceCm();
  Serial.println("Primeira medição: ";
  Serial.println(distancia);

  if (distancia >= 10) {

    digitalWrite(roda1A, HIGH);
    digitalWrite(roda2A, HIGH);
    

  } else {

    digitalWrite(roda1A, LOW);
    digitalWrite(roda2A, LOW);

    temCoisaDosLados();

  }

}

void temCoisaDosLados() {

  bool temNaDireita = false;
  bool temNaEsquerda = false;

  myservo.write(45);
  delay(300);

  distancia = distanceSensor.measureDistanceCm();

  Serial.print("Direita: ");
  Serial.println(distancia);

  if (distancia <= 10) {
    temNaDireita = true;
  }

  myservo.write(90);
  delay(200);

  distancia = distanceSensor.measureDistanceCm();

  Serial.print("Centro: ");
  Serial.println(distancia);

  myservo.write(135);
  delay(300);

  distancia = distanceSensor.measureDistanceCm();

  Serial.print("Esquerda: ");
  Serial.println(distancia);

  if (distancia <= 10) {
    temNaEsquerda = true;
  }

  myservo.write(90);
  delay(200);

  gire(temNaDireita, temNaEsquerda);
}

void gire(bool temNaDireita, bool temNaEsquerda) {

  if (temNaDireita && temNaEsquerda) {

    digitalWrite(roda1H, HIGH);
    digitalWrite(roda2H, HIGH);
    delay(1000);

    digitalWrite(roda1H, LOW);
    digitalWrite(roda2H, LOW);

  }

  else if (temNaDireita) {

    digitalWrite(roda2H, HIGH);
    digitalWrite(roda1A, HIGH);
    delay(700);

    digitalWrite(roda2H, LOW);
    digitalWrite(roda1A, LOW);

  }

  else if (temNaEsquerda) {

    digitalWrite(roda1H, HIGH);
    digitalWrite(roda2A, HIGH);
    delay(700);

    digitalWrite(roda1H, LOW);
    digitalWrite(roda2A, LOW);

  }

  }

