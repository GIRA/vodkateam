#include <SoftwareSerial.h>

#include "AFMotor.h"

int solePIN = 8;

AF_DCMotor motor1(1); // create motor #1
AF_DCMotor motor2(2); // create motor #2
SoftwareSerial BT(10,9);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth       
char estado;

void setup()  { 
  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado
  pinMode(solePIN , OUTPUT); //Solenoide
  Serial.begin(9600);   // Inicializamos  el puerto serie   
  motor1.setSpeed(255);     // set the speed to 200/255
  motor2.setSpeed(255);     // set the speed to 200/255
 } 
 
void loop()  { 
  
      if (BT.available() > 0) 
      {
        estado = BT.read();
        Serial.println(estado);
      }
 if(estado=='S')//
  {
  motor1.run(RELEASE);     
  motor2.run(RELEASE);
  }
  if(estado=='K')//
  {
  motor1.run(RELEASE);     
  motor2.run(RELEASE);
  }
  if(estado=='A'){  //Acelera
            
  motor1.run(FORWARD);      // turn it on going forward
  motor2.run(FORWARD);      // turn it on going forward   
  //Serial.println("algo"); 
    
  }
  if(estado=='E'){  //Retrocede
  motor1.run(BACKWARD);     // RETROCEDE
  motor2.run(BACKWARD);     // RETROCEDE
  //Serial.println("algo");     
  }
  if(estado=='D'){  //Derecha
  motor1.run(RELEASE);      // IZQUIERDA
  motor2.run(FORWARD);      // IZQUIERDA
  
//  Serial.println("algo"); 
  }
  if(estado=='C'){  //Izquierda
  motor1.run(FORWARD);      // DERECHA
  motor2.run(RELEASE);      // DERECHA
  //Serial.println("izquierda"); 
  }
  if(estado=='B'){  //Frenar     
  motor1.run(RELEASE);      // stopped
  motor2.run(RELEASE);      // stopped
  //Serial.println("algo"); 
  } 
  if(estado=='P')//Solenoide
  {
  digitalWrite(solePIN , HIGH); 
  digitalWrite(solePIN , LOW); 
  } 
}
