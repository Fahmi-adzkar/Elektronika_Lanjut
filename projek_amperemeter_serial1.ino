//sensor arus
int sensor = A0;
float R = 10;
void setup()
{
Serial.begin(9600);
pinMode(sensor, INPUT);
}
void loop()
{
//mengukur arus
float adc1 = analogRead(sensor); // outputadc 0 -1023
float Vadc1 = 5 * adc1 / 1023; //volt
float I_ukur = Vadc1 / R; //arus dlm ampere
float I_mili = I_ukur * 1000; // arus dlm mili ampere
//menampilkan arus dalam serial
Serial.print("I ukur: ");
Serial.print(I_mili);
Serial.println(" mA");
delay(1000);
}