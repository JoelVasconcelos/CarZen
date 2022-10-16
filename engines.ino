#include <NewPing.h>
#define D 2
#define R 3
#define M1D 7
#define M1R 8
#define M2D 9
#define M2R 4
#define PwmM1 5
#define PwmM2 6

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
  //  Serial.print(sonar.ping_cm());
  //  Serial.println(" CM");

  //Indo para a frente 
  // engineON(0, D, 255); 
  // engineON(1, D, 255); 

  // delay(2000);
  // engineOFF(0);
  // engineOFF(1);
  // delay(2000);
engine(2, 2);
delay(5000);
engine(3, 2);
delay(5000);

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

      digitalWrite(M1D, LOW);
      digitalWrite(M1R, LOW);
      digitalWrite(M2D, LOW);
      digitalWrite(M2R, LOW);

  analogWrite(PwmM1, 0);
  analogWrite(PwmM2, 0);
}

void engine(uint8_t directM1, uint8_t directM2) {
int pwm = 255;
        if(directM1 == 2) {
            digitalWrite(M1D, HIGH);
            analogWrite(PwmM1, pwm);
            // startEngine(PwmM1, pwm);
        } else {
            digitalWrite(M1D, LOW);
        }

        if(directM1 == 3) {
            digitalWrite(M1R, HIGH);
            analogWrite(PwmM1, pwm);            
            // startEngine(PwmM1, pwm);
        } else{
            digitalWrite(M1R, LOW);
        }
// ---------------------------------------
        if(directM2 == 2) {
            digitalWrite(M2D, HIGH);
            analogWrite(PwmM2, pwm);
            // startEngine(PwmM2, pwm);
        } else {
            digitalWrite(M2D, LOW);
        }

        if(directM2 == 3) {
            digitalWrite(M2R, HIGH);
            analogWrite(PwmM2, pwm);
            // startEngine(PwmM2, pwm);
        } else {
            digitalWrite(M2R, LOW);
        }
}