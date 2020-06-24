
int sensor = 2;

irrecv(sensor);

decode_results data;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&data))
  {Serial.println(data.value);
   irrecv.resume();}
}
