#define D 2
#define R 3
#define M1D 7
#define M1R 8
#define M2D 9
#define M2R 4
#define PwmM1 5
#define PwmM2 6

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
engineON(2, 2);
delay(5000);
engineON(3, 2);
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

void engineON(uint8_t directM1, uint8_t directM2) {
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