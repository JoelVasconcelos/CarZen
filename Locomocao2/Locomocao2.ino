#include <NewPing.h>

//Definição dos pinos dos sensores
#define pin_S1 7
#define pin_S2 6
bool Sensor1 = 0;
bool Sensor2 = 0;

#define pin_trigger 
#define pin_echo
#define max_distance 

bool direction = 0;
int time = 0;

NewPing sonar(pin_trigger,pin_echo,max_distance);

void MoveFront() {


}

void MoveBack() {


}

void Move(){

  Sensor1 = digitalRead(pin_S1);
  Sensor2 = digitalRead(pin_S2);

  if((Sensor1 == 0) && (Sensor2 == 0)){ // Se detectar na extremidade das faixas duas cores brancas
    
    
  }
  if((Sensor1 == 1) && (Sensor2 == 0)){ // Se detectar um lado preto e o outro branco

  }
  if((Sensor1 == 0) && (Sensor2 == 1)){ // Se detectar um lado branco e o outro preto

  }
  

}
CheckObstacle(){
  while(sonar.ping_cm() == 10){
    //Parar
  }

}

void setup() {
  // put your setup code here, to run once:

  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);
}

void UpPlatform(){
  
}
void CheckColor(){
    if(){ //Cor for vermelho 

    }
}

void loop() {
  // put your main code here, to run repeatedly:
  CheckObstacle();
  Move();
  CheckColor();


}
