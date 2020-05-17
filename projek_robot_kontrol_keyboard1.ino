// ROBOT KONTROL KOMPUTER
// Definisi awal
int kiriA = 13;
int kiriB = 12;
int kananA = 9;
int kananB = 8;
int en1 = 11;
int en2 = 10;
void setup()
{
  Serial.begin(9600);
  pinMode(kiriA,OUTPUT);
  pinMode(kiriB,OUTPUT);
  pinMode(kananA,OUTPUT);
  pinMode(kananB,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
}
void loop()
{
  if(Serial.available()>0)
  {
    byte dataku=Serial.read();
    analogWrite(en1,255);
    analogWrite(en2,255);
    
    if (dataku=='M')
    {
      digitalWrite(kiriA,HIGH);
      digitalWrite(kiriB,LOW);
      digitalWrite(kananA,HIGH);
      digitalWrite(kananB,LOW);
      Serial.println("ROBOT MUNDUR");
    }
    else if (dataku=='K')
    {
      digitalWrite(kiriA,LOW);
      digitalWrite(kiriB,HIGH);
      digitalWrite(kananA,LOW);
      digitalWrite(kananB,HIGH);
      Serial.println("ROBOT MAJU");
    }
    else if (dataku=='Z')
    {
      digitalWrite(kiriA,HIGH);
      digitalWrite(kiriB,LOW);
      digitalWrite(kananA,LOW);
      digitalWrite(kananB,HIGH);
      Serial.println("ROBOT BELOK KIRI");
    }
    else if (dataku=='A')
    {
      digitalWrite(kiriA,LOW);
      digitalWrite(kiriB,HIGH);
      digitalWrite(kananA,HIGH);
      digitalWrite(kananB,LOW);
      Serial.println("ROBOT BELOK KANAN");
    }
    else
    {
      digitalWrite(kiriA,LOW);
      digitalWrite(kiriB,LOW);
      digitalWrite(kananA,LOW);
      digitalWrite(kananB,LOW);
      Serial.println("ROBOT DIAM");
    }
  }
}
