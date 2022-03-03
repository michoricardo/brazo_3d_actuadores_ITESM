
#include <Keypad.h>
#include <Password.h> 
#include <Servo.h> 
#include <LiquidCrystal.h>
int d=0;
LiquidCrystal lcd(35,34,33,32,31,30);

Servo myservo;
const int analogInPin = A1;
const int Pin = A0;
int sensorValue = 0; 
int sensor = 0; 
const int OutPin = 41;





Password password = Password( "2" );

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4};



Keypad teclado = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  pinMode(45, OUTPUT);
  pinMode(47, OUTPUT);
  myservo.attach(11); 
  Serial.begin(9600);
  teclado.addEventListener(keypadEvent);
  lcd.begin(16,2);
}

void loop(){
  lcd.begin(16, 2);
  int x=0;
   sensorValue = analogRead(analogInPin); 
   sensor = analogRead(Pin); 
     
  
   if(sensor> 800)
   { 
          // goes from 180 degrees to 0 degrees 
    
 // Encendido de led.
 

 digitalWrite(45, HIGH);
 delay(200);
digitalWrite(45, LOW);

 delay(700);
 digitalWrite(47, HIGH);
 delay(200);
 digitalWrite(47, LOW);
 
 delay(700);
 
 
 
 

 

 Serial.print(Pin );
 
                  // waits 15ms for the servo to reach the position 
  
     
  
  
}
  
  
  
  if(sensorValue > 50)
  {
 
lcd.setCursor(0,0);
lcd.print("FALTA_COMIDA");
Serial.print("FALTA_COMIDA ");

 digitalWrite(OutPin, HIGH);
   
     
    
    
   
  }
  
  else
  {
    teclado.getKey();
    digitalWrite(OutPin, LOW);
  }
  
   
  
  
}

 
void keypadEvent(KeypadEvent eKey){
  
  switch (teclado.getState()){
    
  
    
    case PRESSED:
	Serial.print("EDAD: ");
delay(100);
	Serial.println(eKey);
delay(100);
	switch (eKey){

case '#': checkPassword1(); break;
case 'B': checkPassword(); break;
case 'C': checkPasswor(); break;
case 'F': checkPasswo(); break;
case 'D': checkPassw(); break;

	  case '*': password.reset(); break;
        
	  default: password.append(eKey);
     }

}

}


void checkPassword1(){
  if (password.evaluate()){
    Serial.println("CARGE LA CATEGORIA:");
    lcd.write("CARGE LA CATEGORIA: ");
    
   
  myservo.write(0); 
  delay (5000);
  myservo.write(180);                  
  
    
 }
 
 
}


void checkPassword(){
  if (password.evaluate()){
    lcd.setCursor(0,1);
      lcd.write("MENOR DE 3  KILOS  ");
    Serial.println("MENOR DE 3  KILOS  ");
    lcd.setCursor(0,0);
    
     digitalWrite(45, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(400);              // wait for a second
  digitalWrite(45, LOW);    // turn the LED off by making the voltage LOW
  delay(400); 
 digitalWrite(45, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(400);              // wait for a second
  digitalWrite(45, LOW);
 delay(400);  
   digitalWrite(45, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(400);              // wait for a second
  digitalWrite(45, LOW);    // turn the LED off by making the voltage LOW
  delay(400); 
 
  
    
  }
   
}

void checkPasswor(){
  if (password.evaluate()){
    lcd.setCursor(0,1);
      lcd.write("ENTRE 3 Y 4.5 KILOS ");
    Serial.println("ENTRE 3 Y 4.5 KILOS: ");
     digitalWrite(45, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(750);              // wait for a second
  digitalWrite(45, LOW);    // turn the LED off by making the voltage LOW
  delay(750); 
 digitalWrite(45, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(750);              // wait for a second
  digitalWrite(45, LOW);
 delay(750); 
 
    
    
    
  }
   
}
void checkPasswo(){
  if (password.evaluate()){
    Serial.println("MAYOR A 9 KILOS ");
  }
  
  
  
  
}

void checkPassw(){
  if (password.evaluate()){
    Serial.println("MAYOR A 4.5 KILOS ");
    lcd.setCursor(0,1);
      lcd.write("MAYOR A 4.5 KILOS ");
    
     digitalWrite(45, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1100);              // wait for a second
  digitalWrite(45, LOW);    // turn the LED off by making the voltage LOW
  delay(1100); 
 digitalWrite(45, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1100);              // wait for a second
  digitalWrite(45, LOW);
  delay(1100);


  }
  
  
   
  
}

