#include <Servo.h> 
#include <LiquidCrystal.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards 
const int trigPin = A1;
const int echoPin = A0;
int pos = 0; 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() { 
  Serial.begin(9600);
  myservo.attach(10); 
  myservo.write(0);
   // set up the LCD's number of columns and rows:lcd.begin(16,2);
   
}

void loop(){ 
  
    long duration,inches, cm; 
    pinMode(trigPin, OUTPUT); 
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW); 
    pinMode(echoPin, INPUT); 
    duration = pulseIn(echoPin, HIGH); 
    cm=microsecondsToCentimeters(duration); 
    //lcd program
    lcd.clear();
   lcd.setCursor(0,0); 
    lcd.print("JARAK"); 
     lcd.setCursor(0, 1); 
    lcd.print(cm); //print d lcd 
    Serial.println(cm); 
    
    delay(1000); 
    
     if(cm<=40){ 
       myservo.write(180); 
       
     }
     else if (cm<=100){ 
       for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
       // in steps of 1 degree
      myservo.write(pos); //tell servo go to position in variable 'pos'
      delay(15);
       }
     }
     else
     {
       myservo.write(0);
       delay(0);
     }
}
long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;
}
       
    