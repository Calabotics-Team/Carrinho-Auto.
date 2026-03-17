#include <Servo.h>
#include <HCSR04.h>

#define roda1FE 2
#define roda1TE 3

#define roda2FD 4
#define roda2TD 5

#define roda3FE 6
#define roda3TE 7

#define roda4FD 8
#define roda4TD 9

void setup(){
  pinMode(roda1FE,OUTPUT);
  pinMode(roda1TE,OUTPUT);
  pinMode(roda2FD,OUTPUT);
  pinMode(roda2TD,OUTPUT);
  pinMode(roda3FE,OUTPUT);
  pinMode(roda3TE,OUTPUT);
  pinMode(roda4FD,OUTPUT);
  pinMode(roda4TD,OUTPUT);
   Serial.begin(9600);

}  

void loop (){
  Serial.println("rodando a roda dianteira esquerda para frente");
  digitalWrite(roda1FE, HIGH);
  delay(3000);
  Serial.println(" ,parei");
  digitalWrite(roda1FE, LOW);
  delay(1000);
  Serial.println("rodando a roda dianteira esquerda para trás");
  digitalWrite(roda1TE, HIGH);
  delay(3000);
  Serial.println(" ,parei");
  digitalWrite(roda1TE, LOW);
  delay(1000);
  Serial.println("rodando a roda dianteira direita para frente");
  digitalWrite(roda2FD, HIGH);
  delay(3000);
  Serial.println(" ,parei");
  digitalWrite(roda2FD, LOW);
  delay(1000);
  Serial.println("rodando a roda dianteira direita para trás");
  digitalWrite(roda2TD, HIGH);
  delay(3000);
  Serial.println(" ,parei");
  digitalWrite(roda2TD, LOW);
  delay(1000);
  Serial.println("rodando a roda traseira esquerda para frente");
  digitalWrite(roda3FE, HIGH);
  delay(3000);
  Serial.println(" ,parei");
  digitalWrite(roda3FE, LOW);
  delay(1000);
  Serial.println("rodando a roda traseira esquerda para trás");
  digitalWrite(roda3TE, HIGH);
  delay(3000);
  Serial.println(" ,parei");
  digitalWrite(roda3TE, LOW);
  delay(1000);
  Serial.println("rodando a roda traseira direita para frente");
  digitalWrite(roda4FD, HIGH);
  delay(3000);
  Serial.println(" ,parei");
  digitalWrite(roda4FD, LOW);
  delay(1000);
  Serial.println("rodando a roda traseira direita para trás");
  digitalWrite(roda4TD, HIGH);
  delay(3000);
  Serial.println(" ,parei");
  digitalWrite(roda4TD, LOW);
  delay(1000);
}


