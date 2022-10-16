void setupEngine(){  // Faz as configuração para a utilização das funções no Sketch
      pinMode(M1D, OUTPUT);
      pinMode(M1R, OUTPUT);
      pinMode(M2D, OUTPUT);
      pinMode(M2R, OUTPUT);
      pinMode(PwmM1, OUTPUT);
      pinMode(PwmM2, OUTPUT);
      pinMode(Up, OUTPUT);
      pinMode(Down, OUTPUT);

      digitalWrite(M1D, LOW);
      digitalWrite(M1R, LOW);
      digitalWrite(M2D, LOW);
      digitalWrite(M2R, LOW);
      digitalWrite(Up, LOW);
      digitalWrite(Down, LOW);
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

void engineOFF(){ 

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

void testEngines() {

  digitalWrite(Up, LOW);
  delay(1500);
  digitalWrite(Up, HIGH);
  delay(1500);
  digitalWrite(Down, LOW);
  delay(1500);
  digitalWrite(Down, HIGH);
  delay(1500);

  // // Move para frente
  // MoveFront();
  // delay(1500);
  // engineOFF();

  // delay(2000);

  // // Move para tras
  // MoveBack();
  // delay(1500);
  // engineOFF();

  // delay(2000);

  // // Move para o lado direito 
  // engineON(2, 3);
  // delay(1500);
  // engineOFF();

  // delay(2000);

  // // Move para o lado esquerdo
  // engineON(3, 2);
  // delay(1500);
  // engineOFF();

  // delay(2000);
}