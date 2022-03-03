
/*
  Proyecto de actuadores 
  1 de Mayo del 2015
*/

//Imported libraries
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#define PIN_TRIG 30
#define PIN_ECO  31

//Declare objects
          // Set the pins on the I2C chip used for LCD connections:
          // addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
  LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

// Constantes no cambiaran. Son usada aqui para poner los numeros de los pines:
const int vel=3; //El numero del pin de la velocidad
const int dir=12; //El numero del pin de ladireccion del motor (izquierda o derecha) low or high
const int brake=9; //El numero del pin del freno del motor
const int corriente=A0; //
const int buttonPin=2; //El numero del pin del pushbutton

float volt_per_amp = 1.65;

//Variables que cambiaran:
int buttonState=0; //Variable for reading the pushbutton status
int corr=0;  //Variable for reading the actual current

float currentRaw; //The raw analogRead ranging to hard
float currentVolts; //Raw reading changed to volts
float currentAmps; //Voltage reading changed to Amps

long duracion, distancia;


void setup (){
  pinMode(brake, OUTPUT); //Initiates Brake Channel A pin
  pinMode(dir, OUTPUT); //Inititates Motor Channel A pin (Motor Shield)
  pinMode(buttonPin, INPUT); //Initialize the pushbutton pin as an input.
  Serial.begin(9600);
  
  //Initialize the lcd for 20 chars 4 lines and turn on backlight  
  lcd.begin(20,4);
  
  //Initialize the digitals pines
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECO, INPUT);
}

void loop (){

  
  /* Hacer el disparo */
  digitalWrite(PIN_TRIG, LOW);  
  delayMicroseconds(2); 
  digitalWrite(PIN_TRIG, HIGH);  // Flanco ascendente
  delayMicroseconds(10);        // Duracion del pulso
  digitalWrite(PIN_TRIG, LOW);  // Flanco descendente
  
  /* Recepcion del eco de respuesta */
  duracion = pulseIn(PIN_ECO, HIGH);
  
  /* Calculo de la distancia efectiva */
  distancia = (duracion/2) / 29;
  
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH) //if(buttonState == HIGH && sensorState == HIGH){
    if(distancia >= 15 || distancia <= 0){
      Serial.println("Fuera de rango: ");
      Serial.print(distancia);
    }
    else{
       corr=(analogRead(corriente));//Corriente
       
       if (corr <= 15){
          digitalWrite(brake,HIGH);
          digitalWrite(vel,LOW);  
         }
         
       else{
         
         delay(1000);
         
         if(corr <= 25){
           digitalWrite(brake,HIGH);
           digitalWrite(vel,LOW);  
          }
          
          else{
            delay(1000);
            if(corr <= 36){
               digitalWrite(brake,HIGH);
               digitalWrite(vel,LOW);
             }    
            else{
              delay(1000);
             digitalWrite(dir,HIGH); //Establishes forward direction fo Channel A
             digitalWrite(brake,LOW); //Disengage the brake for Channel A
             analogWrite(vel,255); //Spins the motor on Channel A at full speed
             
             corr=(analogRead(corriente)); // tiempo que va a durar el motor girand o para la prubea de corriente
             currentRaw = corr;
             currentVolts = currentRaw *(5.0/1024.0);
             currentAmps = currentVolts/volt_per_amp;
       
            /* while(currentAmps >= 0.4){
               delay(500);
               corr=(analogRead(corriente)); // tiempo que va a durar el motor girand o para la prubea de corriente
               currentRaw = corr;
               currentVolts = currentRaw *(5.0/1024.0);
               currentAmps = currentVolts/volt_per_amp;
               } */
               
             lcd.clear();   
             lcd.print("Botella abierta.");
             delay(1000);
             lcd.clear();
             
             lcd.print(corr);
        }       
      }
    }
  }
  
  else {
     digitalWrite(brake,HIGH);
     digitalWrite(vel,LOW);  
  }
}


