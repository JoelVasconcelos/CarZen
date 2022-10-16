#include <NewPing.h>
#define D 2
#define R 3
#define M1D 7
#define M1R 8
#define M2D 9
#define M2R 4
#define PwmM1 5
#define pwmM2 6

#define triggerPin 10
#define echoPin 11

#define maxDistance 200 //Em cm

int inApin[2] = {7, 9}; // INA: Sentido Horário Motor0 e Motor1 (Consulte:"1.2) Hardware Monster Motor Shield").
int inBpin[2] = {8, 4}; // INB: Sentido Anti-Horário Motor0 e Motor1 (Consulte: "1.2) Hardware Monster Motor Shield").
int pwmpin[2] = {5, 6}; // Entrada do PWM

NewPing sonar(triggerPin, echoPin, maxDistance);

void setup(){  // Faz as configuração para a utilização das funções no Sketch
  Serial.begin(9600); // Iniciar a serial para fazer o monitoramento

      pinMode(M1D, OUTPUT);
      pinMode(M1R, OUTPUT);
      pinMode(M2D, OUTPUT);
      pinMode(M2R, OUTPUT);
      pinMode(PwmM1, OUTPUT);
      pinMode(PwmM2, OUTPUT);


      digitalWrite(M1D, LOW);
      digitalWrite(M1R, LOW);
      digitalWrite(M2D, LOW);
      digitalWrite(M2R, LOW);
}

void loop(){
   Serial.print(sonar.ping_cm());
   Serial.println(" CM");

  //Indo para a frente 
  engineON(0, D, 255); 
  engineON(1, D, 255); 

  delay(2000);
  engineOFF(0);
  engineOFF(1);
  delay(2000);

}                  

void startEngine(uint8_t motor, uint8_t pwm){
  int i = pwm*.3;
  while (i <= pwm) {
    analogWrite(motor, i);
    delay(200);
    Serial.println(i);
    i = i + pwm*.2;
  }
}

void engineOFF(int motor){ 
  for(int i=0; i<2; i++) {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
  analogWrite(pwmpin[motor], 0);
}

void engineON(uint8_t motor, uint8_t direct, uint8_t pwm) {         //Função que controla as variáveis: motor(0 ou 1), sentido (D ou R) e pwm (entra 0 e 255)
  if(motor <= 1) { // identifica qual motor será movido 0 - motor esquerdo e 1 - motor direito
        if(direct == 2) 
            digitalWrite(inApin[motor], HIGH);
        else
            digitalWrite(inApin[motor], LOW);

        if(direct == 3)
            digitalWrite(inBpin[motor], HIGH);
        else
            digitalWrite(inBpin[motor], LOW);

      startEngine(pwmpin[motor], pwm);
  }
}

void engine(uint8_t directM1, uint8_t directM2) {
        if(directM1 == 2) {
            digitalWrite(M1D, HIGH);
            analogWrite(M1D, 255);
        } else
            digitalWrite(M1D, LOW);

        if(directM1 == 3) {
            digitalWrite(M1R, HIGH);
            analogWrite(M1R, 255);
        } else
            digitalWrite(M1R, LOW);


        if(directM2 == 2) {
            digitalWrite(M2D, HIGH);
            analogWrite(M2D, 255);
        }
 

        else
            digitalWrite(M2D, LOW);

        if(directM2 == 3) 
            digitalWrite(M2R, HIGH);
            analogWrite(M1D, 255);

        else
            digitalWrite(M2R, LOW);

        

}