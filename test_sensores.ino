int flexPin=0;
int valnuevo=0;
int valviejo=140;
int motorPin1 = 3;       // pines del Motor
int motorPin2 = 5;
int motorPin3 = 4;
int motorPin4 = 6;
int delayTime = 1; // Delay que determina la velocidad de giro

void setup(){
Serial.begin(9600);
}
 
 //Dar valor a valviejo
 
void movimientos(){
  if ((valviejo>120) && (valviejo<160)) {
    if ((valnuevo>280) && (valnuevo<300)){
         for (int i=0; i <= 5; i++){
                  digitalWrite(motorPin1, HIGH); // Los pines se activan en secuencia
                  digitalWrite(motorPin2, HIGH);
                  digitalWrite(motorPin3, LOW);
                  digitalWrite(motorPin4, LOW);
                  delay(delayTime);
                  digitalWrite(motorPin1, LOW);
                  digitalWrite(motorPin2, HIGH);
                  digitalWrite(motorPin3, HIGH);
                  digitalWrite(motorPin4, LOW);
                  delay(delayTime);
                  digitalWrite(motorPin1, LOW);
                  digitalWrite(motorPin2, LOW);
                  digitalWrite(motorPin3, HIGH);
                  digitalWrite(motorPin4, HIGH);
                  delay(delayTime);
                  digitalWrite(motorPin1, HIGH);
                  digitalWrite(motorPin2, LOW);
                  digitalWrite(motorPin3, LOW);
                  digitalWrite(motorPin4, HIGH);
                  delay(delayTime);  

      }
    }
      else {
        digitalWrite(motorPin1, LOW); // Los pines se activan en secuencia
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(delayTime);
      
    }
  }
  
  if ((valviejo>20) && (valviejo<50)) {
    
          if ((valnuevo>150) && (valnuevo<180)){
            for (int i=0; i <= 5; i++){
                digitalWrite(motorPin1, LOW); // Los pines se activan en secuencia
                digitalWrite(motorPin2, LOW);
                digitalWrite(motorPin3, HIGH);
                digitalWrite(motorPin4, HIGH);
                delay(delayTime);
                digitalWrite(motorPin1, HIGH);
                digitalWrite(motorPin2, LOW);
                digitalWrite(motorPin3, LOW);
                digitalWrite(motorPin4, HIGH);
                delay(delayTime);
                digitalWrite(motorPin1, HIGH);
                digitalWrite(motorPin2, HIGH);
                digitalWrite(motorPin3, LOW);
                digitalWrite(motorPin4, LOW);
                delay(delayTime);
                digitalWrite(motorPin1, LOW);
                digitalWrite(motorPin2, HIGH);
                digitalWrite(motorPin3, HIGH);
                digitalWrite(motorPin4, LOW);
                delay(delayTime);  
              }
          }
    else {
        digitalWrite(motorPin1, LOW); // Los pines se activan en secuencia
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(delayTime);
      
    }
  }
  }
void loop(){
  valnuevo =analogRead(flexPin);
  Serial.print("valviejo = ");
  Serial.print(valviejo);
  Serial.print(" valnuevo = ");
  Serial.println(valnuevo);
  delay(500);
  movimientos();
  delay(500);
  valviejo=valnuevo;
  
  
  
  
  
}
