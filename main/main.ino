
// Definição dos pinos dos motores
#define D 2
#define R 3
#define M1D 7
#define M1R 8
#define M2D 9
#define M2R 4
#define PwmM1 5
#define PwmM2 6

//Definição dos pinos dos sensores
#define pinS1 7
#define pinS2 6
bool Sensor1 = 0;
bool Sensor2 = 0;
#define pinTrigger 
#define pinEcho
#define maxDistance 

bool direction = 0;
int time = 0;


void MoveFront() {


}

void MoveBack() {


}

void Move(){

  Sensor1 = digitalRead(pinS1);
  Sensor2 = digitalRead(pinS2);

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

  setupEngine();
  // put your setup code here, to run once:

  pinMode(pinS1, INPUT);
  pinMode(pinS2, INPUT);
}

void UpPlatform(){
  
}
void CheckColor(){
    if(){ //Cor for vermelho 

    }
}

void loop() {
  engineON(2, 2);
  delay(5000);

  // put your main code here, to run repeatedly:
  CheckObstacle();
  Move();
  CheckColor();
}
