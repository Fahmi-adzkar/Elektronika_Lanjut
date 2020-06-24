#include <IRremote.h>


const int receiver = 11; 
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;

IRrecv ir_receiver(receiver);           
decode_results results;          

void setup()   
{
  Serial.begin(9600);
  ir_receiver.enableIRIn(); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);  
}


void loop() 
{
  if (ir_receiver.decode(&results))

  {
    Serial.println(results.value, HEX);
    translateIR(); 
    ir_receiver.resume(); 
    delay(200); 
  } 
  
}

void translateIR() 

{
  int sensorValue=0;
  sensorValue = digitalRead(led1);
  sensorValue = digitalRead(led2);
  sensorValue = digitalRead(led3);
  sensorValue = digitalRead(led4);
  sensorValue = digitalRead(led5);
  sensorValue = digitalRead(led6);
  
  switch(results.value){

  case 0x2FD807F:
    if (sensorValue==0){
      
      Serial.println(" ON "); 
      digitalWrite(led1, HIGH); 
      break;
    }
    if (sensorValue==1){
      
      Serial.println(" OFF "); 
      digitalWrite(led1, LOW); 
      break;
    }
    case 0x2FD40BF:
    if (sensorValue==0){
      
      Serial.println(" ON "); 
      digitalWrite(led2, HIGH); 
      break;
    }
    if (sensorValue==1){
      
      Serial.println(" OFF "); 
      digitalWrite(led2, LOW); 
      break;
    }
    case 0x2FDC03F:
    if (sensorValue==0){
      
      Serial.println(" ON "); 
      digitalWrite(led3, HIGH); 
      break;
    }
    if (sensorValue==1){
      
      Serial.println(" OFF "); 
      digitalWrite(led3, LOW); 
      break;
    }
    case 0x2FD20DF:
    if (sensorValue==0){
      
      Serial.println(" ON "); 
      digitalWrite(led4, HIGH); 
      break;
    }
    if (sensorValue==1){
      
      Serial.println(" OFF "); 
      digitalWrite(led4, LOW); 
      break;
    }
    case 0x2FDA05F:
    if (sensorValue==0){
      
      Serial.println(" ON "); 
      digitalWrite(led5, HIGH); 
      break;
    }
    if (sensorValue==1){
      
      Serial.println(" OFF "); 
      digitalWrite(led5, LOW); 
      break;
    }
    case 0x2FD609F:
    if (sensorValue==0){
      
      Serial.println(" ON "); 
      digitalWrite(led6, HIGH); 
      break;
    }
    if (sensorValue==1){
      
      Serial.println(" OFF "); 
      digitalWrite(led6, LOW); 
      break;
    }
  }
}
