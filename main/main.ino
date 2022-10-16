
#include <NewPing.h>
// Definição dos pinos dos motores
#define D 2
#define R 3
#define M1D 7
#define M1R 8
#define M2D 9
#define M2R 4
#define PwmM1 5
#define PwmM2 6

// Definicao dos pinos da plataforma
#define Up 2
#define Down 3

//Definição dos pinos dos sensores
#define pinS1 10
#define pinS2 11

bool SensorLeft = 0;
bool SensorRight = 0;
#define pinTrigger  12
#define pinEcho 13
#define maxDistance 14

bool isUp = false;
char direction = 'f';
long time = 0;



NewPing sonar(pinTrigger,pinEcho,maxDistance);

void setup() {

  setupEngine();
  // put your setup code here, to run once:

  pinMode(pinS1, INPUT);
  pinMode(pinS2, INPUT);
}

void loop() {

  testEngines();

  // put your main code here, to run repeatedly:
  // CheckObstacle();
  // Move();
  // CheckColor();
}

void MoveFront() {
  engineON(2,2); // Move para frente atravez dos dois parametros definidos como 2
}

void MoveBack() {
  engineON(3,3); // Move para frente atravez dos dois parametros definidos como 2
}

void Move(){

  SensorLeft = digitalRead(pinS1);
  SensorRight = digitalRead(pinS2);

  if((SensorLeft == 0) && (SensorRight == 0)){ // Se detectar na extremidade das faixas duas cores brancas
    if(direction = 'f')
      MoveFront();
    else
      MoveBack();
  }
  
  if((SensorLeft == 0) && (SensorRight == 1)){ // Se detectar o lado branco na esquerda e o lado preto na direita
    engineON(2, 3);
  }
  
  if((SensorLeft == 1) && (SensorRight == 0)){ // Se detectar o lado preto na esquerda e o lado branco na direita
    engineON(3, 2);
  }
}

void CheckObstacle(){
  while(sonar.ping_cm() == 10){
    //Parar
  }

}

void UpPlatform(){
  
}

void DownPlatform(){
  
}

void CheckColor(){
  if(SensorLeft == 1){ //Cor for vermelho 
    if(!isUp){
      time = millis() + 5000;    
    }
    if(time > millis()){
        UpPlatform();

    }else{
      isUp = false;
      direction = 'b';
    } 
  }
}


