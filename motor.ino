int motorPin1 = 3;       // pines del Motor
int motorPin2 = 5;
int motorPin3 = 4;
int motorPin4 = 6;
int delayTime = 1; // Delay que determina la velocidad de giro
int sensor = 8;
int sensoreversa = 9;
//

void setup() { 
pinMode(motorPin1, OUTPUT); // Configuración de los PINes como salida digital
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
pinMode(sensor, INPUT);
pinMode(sensoreversa, INPUT);
}

void loop() { 
    if (digitalRead(sensor) == HIGH){ //Dependiendo del valor del contador entrara a la condicion para escribir en el display
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
  if (digitalRead(sensoreversa) == HIGH){ //Dependiendo del valor del contador entrara a la condicion para escribir en el display  
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
   
   else {  
    digitalWrite(motorPin1, LOW); 
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);


    } 
   
}
