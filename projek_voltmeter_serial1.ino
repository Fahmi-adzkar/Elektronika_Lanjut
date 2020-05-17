//sensor tegangan
int sensor = A0;
float R1 = 100000;
float R2 = 1000;
void setup()
{
Serial.begin(9600);
pinMode(sensor, INPUT);
}
void loop()
{
//mengukur tegangan
float adc = analogRead(sensor);
float Vadc = 5 * adc / 1023;
float V_ukur = Vadc * (R1 + R2) / R2;
//menampilkan tegangan dalam serial
Serial.print("V ukur: ");
Serial.print(V_ukur);
Serial.println(" Volt");
delay(1000);
}