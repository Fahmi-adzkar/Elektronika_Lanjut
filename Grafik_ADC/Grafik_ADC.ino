int nilaiSen;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
nilaiSen = analogRead(A2);

Serial.println(nilaiSen);
delay(100);
}
