#include<Servo.h>
#define trigPin 7
#define echoPin 6
Servo servo;
int sound = 250;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
servo.attach(8);
}

void loop() {
  // put your main code here, to run repeatedly:
long duration, distance;
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration = pulseIn(echoPin,HIGH);
distance = (duration/2)/29.1;

if(distance<5) {
  Serial.println("the distance is less than 5");
  servo.write(90);
}
else{
  servo.write(0);
  }

if(distance>10) {
  Serial.println("the distance is more than 10");
}
else{
Serial.print(distance);
Serial.println("cm");
}
delay(500);
}
