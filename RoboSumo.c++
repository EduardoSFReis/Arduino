//    Autor: Eduardo S. F. Reis
//    E-mail: edufrancoreis@hotmail.com
#include <Ultrasonic.h>

#define sensor1  2
#define sensor2  3
#define pino_trigger 4
#define pino_echo 5

int ma1 = 8;
int ma2 = 9;
int mb1 = 10;
int mb2 = 11;

int valor1 = 0;
int valor2 = 0;
float distancia1;

 Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup(){
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
   Serial.begin(9600);
   delay(6000);
  }

/// começa comandos basicos de direção
void frente(){
  digitalWrite(ma2,LOW);
  digitalWrite(mb2,LOW);
  digitalWrite(ma1,HIGH);
  digitalWrite(mb1,HIGH);
}

void tras(){
  digitalWrite(ma1,LOW);
  digitalWrite(mb1,LOW);
  digitalWrite(ma2,HIGH);
  digitalWrite(mb2,HIGH);
}

void g1(){
  digitalWrite(ma1,LOW);
  digitalWrite(mb1,HIGH);
  digitalWrite(ma2,HIGH);
  digitalWrite(mb2,LOW);
}
void g2(){
  digitalWrite(ma2,LOW);
  digitalWrite(mb2,LOW);
  digitalWrite(ma1,HIGH);
  digitalWrite(mb1,LOW);
}
void parar(){
  digitalWrite(ma1,LOW);
  digitalWrite(mb1,LOW);
  digitalWrite(ma2,LOW);
  digitalWrite(mb2,LOW);
}  
/// acabou comandos basicos de direção
/// começou oq fazer quando escosta na linha
void L1(){
 tras();
 delay(1000);
 g1();
 delay(200);
}
void L2(){
 frente();
 delay(1000);
 g2();
 delay(500);
 frente();
}
/// acabou oq fazer quando escosta na linha

void loop() {  
valor1 = analogRead(sensor1);
valor2 = analogRead(sensor2);
float cmMsec;
long microsec = ultrasonic.timing();
distancia1 = ultrasonic.convert(microsec, Ultrasonic::CM);
if (distancia1 <= 20 && distancia1 >= 1 ){
  frente();
}
if (valor1 > 300 && valor2 > 300){
  frente();
}
if (valor1 < 300 && valor2 > 300){
  L1();
}
if (valor1 > 300 && valor2 < 300){
  L2();
  
}

 }