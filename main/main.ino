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

//Definição dos pinos dos sensores de linha
const int plsensorRight = 8;
const int plsensorLeft = 15; //Definir o pino
bool sensorRight = 0;
bool sensorLeft = 0;

  //Definição dos pinos dos sensores de cor
  // Left
const int sensorLeftS0 = 30;
const int sensorLeftS1 = 31;
const int sensorLeftS2 = 32;
const int sensorLeftS3 = 33;
const int sensorLeftOUT = 34;

// Right
const int sensorRightS0 = 35;
const int sensorRightS1 = 36;
const int sensorRightS2 = 37;
const int sensorRightS3 = 38;
const int sensorRightOUT = 39;


// Variaveis que armazenam o valor das cores
// Left
int corVermelhoLeft = 0;
int corVerdeLeft = 0;
int corAzulLeft = 0;

// Right
int corVermelhoRight = 0;
int corVerdeRight = 0;
int corAzulRight = 0;


// Sensor de distancia
// Definição dos pinos
#define ptDianteiro 26
#define peDianteiro 27

#define ptDianteiroEsquedo 30
#define peDianteiroEsquedo 31

#define ptDianteiroDireito 28
#define peDianteiroDireito 29

#define ptLateralDireito 24
#define peLateralDireito 45

#define ptLateralEsquerdo 32
#define peLateralEsquerdo 33

#define ptsonarTraseiro 22
#define pesonarTraseiro 23





// Definição da distancia maxima lida pelo sensor
#define maxDistance 200


// Definição das variaveis para o tempo de subida da plataforma
bool isUp = false;
char direction = 'f';
long time = 0;


// Definição da variavel de estado da manobra
bool maneuver = false;

bool isSpin = false;


// Inicialização do sonar para o sensor de distancia
NewPing sonarDianteiro(ptDianteiro, peDianteiro, maxDistance);
NewPing sonarDianteiroEsquedo(ptDianteiroEsquedo, peDianteiroEsquedo, maxDistance);
NewPing sonarDianteiroDireito(ptDianteiroDireito, peDianteiroDireito, maxDistance);
NewPing sonarLateralDireito(ptLateralDireito, peLateralDireito, maxDistance);
NewPing sonarLateralEsquerdo(ptLateralEsquerdo, peLateralEsquerdo, maxDistance);
NewPing sonarTraseiro(ptsonarTraseiro, pesonarTraseiro, maxDistance);


void setup() {
  Serial.begin(9600);
  setupEngine();
  setupSensors();
  pinMode(plsensorRight, INPUT);
  pinMode(plsensorLeft, INPUT);
}

void loop() {
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

  if (corVermelhoLeft < 185 && corVerdeLeft < 185 && corAzulLeft < 145) {  // Se detectar o lado preto na esquerda e o lado branco na direita

    engineON(3, 2);
  }

  if (corVermelhoRight < 185 && corVerdeRight < 185 && corAzulRight < 145) {  // Se detectar o lado branco na esquerda e o lado preto na direita
    engineON(2, 3);
  }

  if ((corVerdeLeft > corAzulLeft && corAzulLeft > corVermelhoLeft && corVermelhoLeft < 60) && (corVerdeRight > corAzulRight && corAzulRight > corVermelhoRight && corVermelhoRight < 60)) {  // Se detectar o vermelho nos dois sensores
    engineOFF();
    maneuver = true;
    platform();
  }

  if (maneuver) {
    if (corVermelhoRight < 185 && corVerdeRight < 185 && corAzulRight < 145) {
      maneuver = false;
    }
    engineON(3, 2);
  }
}

// bool checkSides(){
//   returun false;
// }



void checkObstacle() {
  // Serial.println((String)"Dianteiro: "+sonarDianteiro.ping_cm());
  // Serial.println((String)"Dianteiro ESQ: "+sonarDianteiroEsquedo.ping_cm());
  // Serial.println((String)"Dianteiro DIR = "+sonarDianteiroDireito.ping_cm());
  // Serial.println((String)"Lateral DIR= "+sonarLateralDireito.ping_cm());
  // Serial.println((String)"Lateral ESQ = "+sonarLateralEsquerdo.ping_cm());
  // Serial.println((String)"Traseiro = "+sonarTraseiro.ping_cm());
  // delay(100);
  // Serial.println(">>>>>");
  // Serial.println((String) "Dianteiro: " + sonarDianteiro.ping_cm());
  if (sonarDianteiro.ping_cm() <= 30 && sonarDianteiro.ping_cm() >= 1) {
    engineOFF();
  }
  //else if (checkSides()){
  //  engineOFF(); //ajustar direcao
  //}
  else {
    // checkColor();
    //Armazena o valor lido pelos sensores
    sensorRight = digitalRead(plsensorRight);
    sensorLeft = digitalRead(plsensorLeft);

    if (direction == 'f') {
      if(isSpin)
      {
        engineON(2, 3);
        if ((sensorRight == 0) && (sensorLeft == 1))
        {
          isSpin = false;
        }
      }
      if ((sensorRight == 0) && (sensorLeft == 0)) {  // Se detectar na extremidade das faixas duas cores brancas
         engineON(2, 2);
      }
      if ((sensorRight == 1) && (sensorLeft == 0)) {  // Se detectar um lado preto e o outro branco
         engineON(3, 2);
      }
      if ((sensorRight == 0) && (sensorLeft == 1)) {  // Se detectar um lado branco e o outro preto
        engineON(2, 3);
      }
      if((sensorRight == 1) && (sensorLeft == 1)){ //Se os dois lados forem preto
        platform();
      } 
    }
    else if (direction == 'b') {
      if ((sensorRight == 0) && (sensorLeft == 0)) {  // Se detectar na extremidade das faixas duas cores brancas
         engineON(2, 2);
      }
      if ((sensorRight == 1) && (sensorLeft == 0)) {  // Se detectar um lado preto e o outro branco
         engineON(2, 3);
      }
      if ((sensorRight == 0) && (sensorLeft == 1)) {  // Se detectar um lado branco e o outro preto
        engineON(3, 2);
      }
      if((sensorRight == 1) && (sensorLeft == 1)){ //Se os dois lados forem preto
        platform();
      } 

    }
 }
}
void platform() {
  if (direction == 'f') {
    if (!isUp) {
      time = millis() + 5000;
      isUp = true;
    }
    if (time > millis()) {
      digitalWrite(Down, HIGH);
      digitalWrite(Up, LOW);
    } else {
      isUp = false;
      direction = 'b';
      isSpin = true;
    }

  } else if (direction == 'b') {
    if (!isUp) {
      time = millis() + 5000;
      isUp = true;
    }
    if (time > millis()) {
      digitalWrite(Up, HIGH);
      digitalWrite(Down, LOW);
    } else {
      digitalWrite(Down, HIGH);
    }
  }
}