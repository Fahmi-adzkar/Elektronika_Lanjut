//sensor resistansi
int sensor = A0;
float Vcc = 5;
float R = 1000; //resistor sensor 1 kohm
void setup()
{
Serial.begin(9600);
pinMode(sensor, INPUT);
}
void loop()
{
//mengukur resistansi
float adc = analogRead(sensor);
float Vadc = 5 * adc / 1023;
float buffer = (Vcc / Vadc) - 1;
float R_ukur = R / buffer;
//menampilkan resistansi dalam serial
Serial.print("R ukur: ");
Serial.print(R_ukur);
Serial.println(" Ohm");
delay(1000);
}