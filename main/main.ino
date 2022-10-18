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


// Definicao dos pinos do motor da plataforma
#define Up 40
#define Down 41


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


// Sensor de distancia
// Definição dos pinos
#define pinTrigger  30
#define pinEcho 31
// Definição da distancia maxima lida pelo sensor 
#define maxDistance 100


// Definição das variaveis para o tempo de subida da plataforma
bool isUp = false;
char direction = 'f';
long time = 0;


// Definição da variavel de estado da manobra
bool maneuver = false;


// Inicialização do sonar para o sensor de distancia
NewPing sonar(pinTrigger,pinEcho,maxDistance);

void setup() {
  Serial.begin(9600);
  setupEngine();
  setupSensors();
}

void loop() {
  // testEngines();
  checkObstacle();
}

void checkColor() {
  corVermelhoLeft = leitorVermelho(sensorLeftS2, sensorLeftS3, sensorLeftOUT); 
  corVermelhoRight = leitorVermelho(sensorRightS2, sensorRightS3, sensorRightOUT); 

  corVerdeLeft = leitorVerde(sensorLeftS2, sensorLeftS3, sensorLeftOUT); 
  corVerdeRight = leitorVerde(sensorRightS2, sensorRightS3, sensorRightOUT); 

  corAzulLeft = leitorAzul(sensorLeftS2, sensorLeftS3, sensorLeftOUT); 
  corAzulRight = leitorAzul(sensorRightS2, sensorRightS3, sensorRightOUT); 

  if (!maneuver) {
    engineON(2, 2);
  }

  if(corVermelhoLeft<185 && corVerdeLeft<185 && corAzulLeft<145){ // Se detectar o lado preto na esquerda e o lado branco na direita
    engineON(3, 2);
  }
  
  if(corVermelhoRight<185 && corVerdeRight<185 && corAzulRight<145){ // Se detectar o lado branco na esquerda e o lado preto na direita
    engineON(2, 3);
  }

  if((corVerdeLeft>corAzulLeft && corAzulLeft>corVermelhoLeft && corVermelhoLeft<60) && (corVerdeRight>corAzulRight && corAzulRight>corVermelhoRight && corVermelhoRight<60)){ // Se detectar o vermelho nos dois sensores
    engineOFF(); 
    maneuver = true;
    platform();
  }

  if (maneuver) {
    if (corVermelhoRight<185 && corVerdeRight<185 && corAzulRight<145) {
      maneuver == false;
    }
    engineON(3, 2);
  }
}

void checkObstacle(){
  Serial.println(sonar.ping_cm());
  if (sonar.ping_cm() <= 10){
    engineOFF();
  }
  checkColor();
}

void platform(){ 
  if (direction == 'f'){ 
    if (!isUp){
      time = millis() + 5000;   
      isUp = true;
    }
    if (time > millis()){
      digitalWrite(Down, HIGH);
      digitalWrite(Up, LOW);
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
      digitalWrite(Up, HIGH);
      digitalWrite(Down, LOW);
    } else {
      digitalWrite(Down, HIGH);
    }
  }
}