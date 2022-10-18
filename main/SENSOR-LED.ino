
const int PINO_SENSOR_S0 = 10; 
const int PINO_SENSOR_S1 = 11; 
const int PINO_SENSOR_S2 = 12; 
const int PINO_SENSOR_S3 = 13; 
const int PINO_SENSOR_OUT = 9; 


// Variaveis que armazenam o valor das cores
int corVermelho = 0;
int corVerde = 0;
int corAzul = 0;





void setup(){

  Serial.begin(9600);//inicia serial
 
  pinMode(PINO_SENSOR_S0, OUTPUT); // Pino S0 configurado como saida
  pinMode(PINO_SENSOR_S1, OUTPUT); // Pino S1 configurado como saida
  pinMode(PINO_SENSOR_S2, OUTPUT); // Pino S2 configurado como saida
  pinMode(PINO_SENSOR_S3, OUTPUT); // Pino S3 configurado como saida
  pinMode(PINO_SENSOR_OUT, INPUT); // Pino OUT configurado como entrada

  // CONFIGURA ESCALA DE LEITURA PARA 20%

  digitalWrite(PINO_SENSOR_S0,HIGH); // Inicia o codigo com o pino S0 em nivel alto
  digitalWrite(PINO_SENSOR_S1,LOW); // Inicia o codigo com o pino S1 em nivel baixo

}

void loop(){

corVermelho = leitorVermelho(); 
corVerde = leitorVerde(); 
corAzul = leitorAzul(); 

//  Serial.print("R:");
//  Serial.print(corVermelho);
//  Serial.print("--");
//  Serial.print("G:");
//  Serial.print(corVerde); 
//  Serial.print("--");
//  Serial.print("B:");
//  Serial.println(corAzul);  


 if(corVermelho>185 && corVerde>185 && corAzul>145){Serial.println("preto");}//SE PRETO

 if(corVermelho<40 && corVerde<40 && corAzul<40){Serial.println("branco");}//SE BRANCO

 if(corVerde>corAzul && corAzul>corVermelho && corVermelho<60){Serial.println("vermelho");}// SE VERMELHO

 if(corVermelho>corVerde && corVerde>corAzul && corAzul<60){Serial.println("azul");}// SE AZUL

}


int leitorVermelho(){
  int cor = 0; 
  int sensorVermelho = 0;

  //CONFIGURA LEITOR PARA VERMELHO
  digitalWrite(PINO_SENSOR_S2,LOW);
  digitalWrite(PINO_SENSOR_S3,LOW);

  if(digitalRead(PINO_SENSOR_OUT) == HIGH){ // Verifica o nivel logico no pino OUT do sensor
    sensorVermelho = pulseIn(PINO_SENSOR_OUT, LOW);
    cor = sensorVermelho; // Le duracao do pulso na saida
  } else {
    sensorVermelho = pulseIn(PINO_SENSOR_OUT, HIGH);
    cor = sensorVermelho; // Le duracao do pulso na saida
  }   
 
  return cor; 

}

int leitorVerde(){
  int cor = 0; 
  int sensorVerde = 0;

  //CONFIGURA LEITOR PARA VERDE
  digitalWrite(PINO_SENSOR_S2,HIGH);
  digitalWrite(PINO_SENSOR_S3,HIGH);


  if(digitalRead(PINO_SENSOR_OUT) == HIGH){ // Verifica o nivel logico no pino OUT do sensor
    sensorVerde = pulseIn(PINO_SENSOR_OUT, LOW);
    cor = sensorVerde; // Le duracao do pulso na saida
  } else {
    sensorVerde = pulseIn(PINO_SENSOR_OUT, HIGH);
    cor = sensorVerde ; // Le duracao do pulso na saida
  }   
 
  return cor;

}

int leitorAzul(){
  int cor = 0; 
  int sensorAzul = 0;

  //CONFIGURA LEITOR PARA AZUL
  digitalWrite(PINO_SENSOR_S2,LOW);
  digitalWrite(PINO_SENSOR_S3,HIGH);

  
  if(digitalRead(PINO_SENSOR_OUT) == HIGH){ // Verifica o nivel logico no pino OUT do sensor
    sensorAzul = pulseIn(PINO_SENSOR_OUT, LOW);
    cor = sensorAzul; // Le duracao do pulso na saida
  } else {
    sensorAzul = pulseIn(PINO_SENSOR_OUT, HIGH);
    cor = sensorAzul; // Le duracao do pulso na saida
  }   
 
  return cor;

}





