#include <PID_v1.h>
const int photores = A0;  //port photoresistor
const int pot = A1;  //port potensiometer
const int led = 2;  //port Led
double lightLevel;
float Kp = 0;  //Kp = konstanta Proporsional
float Ki = 10;  //Ti = konstanta Integral
float Kd = 0;  //Td = konstanta Derivatif
double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
const int sampleRate = 1;
const long serialPing = 500;
unsigned long now = 0;
unsigned long lastMessage = 0;
void setup()
{
lightLevel = analogRead(photores);
Input = map(lightLevel, 0, 1023, 0, 255);
Setpoint = map(analogRead(pot), 0, 1023, 0, 255);
Serial.begin(9600);
myPID.SetMode(AUTOMATIC);
myPID.SetSampleTime(sampleRate);
Serial.println("Begin");
lastMessage = millis();
}
void loop()
{
Setpoint = map(analogRead(pot), 0, 1023, 0, 255);
lightLevel = analogRead(photores);
Input = map(lightLevel, 0, 1023, 0, 255);
myPID.Compute();
analogWrite(led, Output);
now = millis();
if(now - lastMessage > serialPing)
{
Serial.print("Setpoint = ");
Serial.print(Setpoint);
Serial.print(" Input = ");
Serial.print(Input);
Serial.print(" Output = ");
Serial.print(Output);
Serial.print("\n");
if (Serial.available() > 0)
{
for (int x = 0; x < 4; x++)
{
switch(x)
{
case 0:
Kp = Serial.parseFloat();
break;
case 1:
Ki = Serial.parseFloat();
break;
case 2:
Kd = Serial.parseFloat();
break;
case 3:
for (int y = Serial.available(); y == 0; y--)
{
Serial.read();
}
break;
}
}
Serial.print(" Kp,Ki,Kd = ");
Serial.print(Kp);  //Kp = konstanta Proporsional
Serial.print(",");
Serial.print(Ki);  //Ti = konstanta Integral
Serial.print(",");
Serial.print(Kd);  //Td = konstanta Derivatif
myPID.SetTunings(Kp, Ki, Kd);
}
lastMessage = now;
}
}
