#include <NewPing.h>

// Definição do sentido de rotação dos motores
#define D 2
#define R 3

// Definição dos pinos dos motores
#define M1D 7
#define M1R 8
#define M2D 9
#define M2R 4
#define PwmM1 5
#define PwmM2 6

// Definicao dos pinos da plataforma
#define Up 22
#define Down 23

//Definição dos pinos dos sensores de cor
// Left
#define sensorLeftS0 30; 
#define sensorLeftS1 31; 
#define sensorLeftS2 32; 
#define sensorLeftS3 33; 
#define sensorLeftOUT 34; 

// Right
#define sensorRightS0 35; 
#define sensorRightS1 36; 
#define sensorRightS2 37; 
#define sensorRightS3 38; 
#define sensorRightOUT 39; 

// Variaveis que armazenam o valor das cores
// Left
#define corVermelhoLeft 0;
#define corVerdeLeft 0;
#define corAzulLeft 0;

// Right
#define corVermelhoRight 0;
#define corVerdeRight 0;
#define corAzulRight 0;

// Definição dos pinos do sensor de distancia
#define pinTrigger  30
#define pinEcho 31
#define maxDistance 100

// Definição das variaveis para o temp[o de subida da plataforma
bool isUp = false;
char direction = 'f';
long time = 0;

NewPing sonar(pinTrigger,pinEcho,maxDistance);

void setup() {
  Serial.begin(9600);
  setupEngine();
  setupSensors();
}

void loop() {
  // testEngines();
  CheckObstacle();

  CheckColor();

corVermelhoLeft = leitorVermelho(sensorLeftS2, sensorLeftS3, sensorLeftOUT); 
corVermelhoRight = leitorVermelho(sensorRightS2, sensorRightS3, sensorRightOUT); 

corVerdeLeft = leitorVerde(sensorLeftS2, sensorLeftS3, sensorLeftOUT); 
corVerdeRight = leitorVerde(sensorRightS2, sensorRightS3, sensorRightOUT); 

corAzulLeft = leitorAzul(sensorLeftS2, sensorLeftS3, sensorLeftOUT); 
corAzulRight = leitorAzul(sensorRightS2, sensorRightS3, sensorRightOUT); 


 if(corVermelho>185 && corVerde>185 && corAzul>145){Serial.println("preto");}//SE PRETO

 if(corVermelho<40 && corVerde<40 && corAzul<40){Serial.println("branco");}//SE BRANCO

 if(corVerde>corAzul && corAzul>corVermelho && corVermelho<60){Serial.println("vermelho");}// SE VERMELHO

 if(corVermelho>corVerde && corVerde>corAzul && corAzul<60){Serial.println("azul");}// SE AZUL

}
}

void MoveFront() {
  engineON(2,2); // Move para frente atravez dos dois parametros definidos como 2
}

void MoveBack() {
  engineON(3,3); // Move para frente atravez dos dois parametros definidos como 2
}

void Move(){
  if((SensorLeft == 0) && (SensorRight == 0)){ // Se detectar na extremidade das faixas duas cores brancas
    if(direction == 'f')
      MoveFront();
    else if(direction == 'b')
      MoveBack();
    else{

    }
      // break;
  }
  
  if((SensorLeft == 0) && (SensorRight == 1)){ // Se detectar o lado branco na esquerda e o lado preto na direita
    engineON(2, 3);
  }
  
  if((SensorLeft == 1) && (SensorRight == 0)){ // Se detectar o lado preto na esquerda e o lado branco na direita
    engineON(3, 2);
  }
}

void CheckObstacle(){
  Serial.println(sonar.ping_cm());
  if (sonar.ping_cm() <= 10){
    engineOFF();
  }
  Move();
  // MoveFront();
}

void UpPlatform(){
  digitalWrite(Down, HIGH);
  digitalWrite(Up, LOW);
}

void DownPlatform(){
  digitalWrite(Up, HIGH);
  digitalWrite(Down, LOW);
} 

void CheckColor(){ 
  SensorLeft = 1;
  if (SensorLeft == 1){ //Cor for vermelho 
    if (direction == 'f'){ 
      if (!isUp){
        time = millis() + 5000;   
        isUp = true;
      }
      if (time > millis()){
        UpPlatform();
      } else {
        isUp = false;
        direction = 'b';
      } 

    }else if (direction == 'b'){
      if (!isUp){
        time = millis() + 5000;   
        isUp = true;
      }
      if (time > millis()){
        DownPlatform();
      } else {
        digitalWrite(Down, HIGH);
      }
    }
  }
}


