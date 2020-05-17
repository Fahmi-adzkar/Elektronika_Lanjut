#include <LiquidCrystal.h>

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

//sensor resistansi
int sensor= A0;
float Vcc= 5;
float R= 1000; //resistor sensor 1 kohm

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16, 2);
pinMode (sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//mengukur resistensi
float adc= analogRead (sensor);
float Vadc= 5*adc/ 1024;
float buffer= (Vcc/Vadc)-1;
float R_ukur= R/buffer;

//menampilkan resistensi dalam serial

Serial.print("R ukur:");
Serial.print(R_ukur);
Serial.println("Ohm");

//menampilkan resistansi dalam LCD
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("R ukur:");
lcd.print(R_ukur);
lcd.print("Ohm");
delay(1000);
}
