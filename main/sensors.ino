void setupSensors(){
  pinMode(sensorLeftS0, OUTPUT); // Pino S0 configurado como saida
  pinMode(sensorLeftS1, OUTPUT); // Pino S1 configurado como saida
  pinMode(sensorLeftS2, OUTPUT); // Pino S2 configurado como saida
  pinMode(sensorLeftS3, OUTPUT); // Pino S3 configurado como saida
  pinMode(sensorLeftOUT, INPUT); // Pino OUT configurado como entrada

  pinMode(sensorRightS0, OUTPUT); // Pino S0 configurado como saida
  pinMode(sensorRightS1, OUTPUT); // Pino S1 configurado como saida
  pinMode(sensorRightS2, OUTPUT); // Pino S2 configurado como saida
  pinMode(sensorRightS3, OUTPUT); // Pino S3 configurado como saida
  pinMode(sensorRightOUT, INPUT); // Pino OUT configurado como entrada

  // CONFIGURA ESCALA DE LEITURA PARA 20%
  digitalWrite(sensorLeftS0,HIGH); // Inicia o codigo com o pino S0 em nivel alto
  digitalWrite(sensorLeftS1,LOW); // Inicia o codigo com o pino S1 em nivel baixo

  digitalWrite(sensorRightS0,HIGH); // Inicia o codigo com o pino S0 em nivel alto
  digitalWrite(sensorRightS1,LOW); // Inicia o codigo com o pino S1 em nivel baixo
}

int leitorVermelho(int sensorS2, int sensorS3, int sensorOUT){
  int cor = 0; 
  int leitorVermelho = 0;

  //CONFIGURA LEITOR PARA VERMELHO
  digitalWrite(sensorS2,LOW);
  digitalWrite(sensorS3,LOW);

  if(digitalRead(sensorOUT) == HIGH){ // Verifica o nivel logico no pino OUT do sensor
    leitorVermelho = pulseIn(sensorOUT, LOW);
    cor = leitorVermelho; // Le duracao do pulso na saida
  } else {
    leitorVermelho = pulseIn(sensorOUT, HIGH);
    cor = leitorVermelho; // Le duracao do pulso na saida
  }   
  return cor; 
}

int leitorVerde(int sensorS2, int sensorS3, int sensorOUT){
  int cor = 0; 
  int leitorVerde = 0;

  //CONFIGURA LEITOR PARA VERDE
  digitalWrite(sensorS2,HIGH);
  digitalWrite(sensorS3,HIGH);

  if(digitalRead(sensorOUT) == HIGH){ // Verifica o nivel logico no pino OUT do sensor
    leitorVerde = pulseIn(sensorOUT, LOW);
    cor = leitorVerde; // Le duracao do pulso na saida
  } else {
    leitorVerde = pulseIn(sensorOUT, HIGH);
    cor = leitorVerde ; // Le duracao do pulso na saida
  }   
  return cor;
}

int leitorAzul(int sensorS2, int sensorS3, int sensorOUT){
  int cor = 0; 
  int leitorAzul = 0;

  //CONFIGURA LEITOR PARA AZUL
  digitalWrite(sensorS2,LOW);
  digitalWrite(sensorS3,HIGH);

  if(digitalRead(sensorOUT) == HIGH){ // Verifica o nivel logico no pino OUT do sensor
    leitorAzul = pulseIn(sensorOUT, LOW);
    cor = leitorAzul; // Le duracao do pulso na saida
  } else {
    leitorAzul = pulseIn(sensorOUT, HIGH);
    cor = leitorAzul; // Le duracao do pulso na saida
  }   
  return cor;
}