import processing.serial.*;
Serial portSerial;
int nilaipSX;
int inByte;
int[] nilaipSY;
int w;
void setup()
{
 size (700,400);
 w = width-10;
 strokeWeight(3);
 smooth();
 nilaipSY = new int[w];
 portSerial = new Serial(this, "COM3", 9600);
}
void draw()
{
 String inString = portSerial.readStringUntil('\n');
 if(inString != null){
 inString = trim(inString);
 inByte = int(inString);
 println(inByte);
 nilaipSX = int(map(inByte, 0, 1023, 0+10, height-50));
 nilaipSX = height-nilaipSX;
 background(0);

 for(int i = 1; i < w; i++) {
 nilaipSY[i-1] = nilaipSY[i];
 }

 nilaipSY[w-1] = nilaipSX;
 textSize(32);
 text(inByte, 10, 30);

 stroke(255);
 line(w, nilaipSX, width, nilaipSX);
 strokeWeight(1);
 line(0, nilaipSX, width, nilaipSX);
 strokeWeight(3);

 for(int i=2; i<w; i++) {
 strokeWeight(3);
 stroke(0, 255, nilaipSY[i]);
 line(i, nilaipSY[i-1], i, nilaipSY[i]);
 }
 }
}
