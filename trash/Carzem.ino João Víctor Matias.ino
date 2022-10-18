#include <NewPing.h>
/*DECLARAÇÃO DE VARIAVEIS*/
#define MotorA_sentido1 2
#define MotorA_sentido2 4
#define MotorB_sentido1 8
#define MotorB_sentido2 9
#define MotorA_PWM 3  
#define MotorB_PWM 10  
#define veloc0 0
#define veloc1 80
#define veloc2 180
#define veloc3 255
#define Sensor_direita 6
#define Sensor_esquerda 7

#define Trigger_pin 
#define Echo_pin
#define Distancia_maxima //Em cm

NewPing sonar(Trigger_pin, Echo_pin, Distancia_maxima);

bool direita, esquerda;
void setup() {
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  
}

void andarFrente() {
  //Define o sentido de rotação dos motores
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);
}

void lerSensor() {
  //Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);
  Serial.print(direita);
  Serial.print(" || ");
  Serial.println(esquerda);
}

void ajustarMotor() {
  //Rodando os motores dependendo das leituras
  if(direita == false && esquerda == false){
    analogWrite(MotorA_PWM, veloc2);
    analogWrite(MotorB_PWM, veloc2);
  } else if(direita == false && esquerda == true){
    delay(400);
    analogWrite(MotorA_PWM, veloc2);
    analogWrite(MotorB_PWM, veloc1);
    delay(400);
 }else if(direita == true && esquerda == false){
    delay(400);
    analogWrite(MotorA_PWM, veloc1);
    analogWrite(MotorB_PWM, veloc2);
    delay(400);
 }else if(direita == true && esquerda == true){
    analogWrite(MotorA_PWM, veloc0);
    analogWrite(MotorB_PWM, veloc0);
 }
}

bool verificaObstaculo(){
  if(sonar.ping_cm() == 10){
    return true;
  }
  return false;
}
void loop() {
  andarFrente();
  lerSensor();
  ajustarMotor();
  
  
}
