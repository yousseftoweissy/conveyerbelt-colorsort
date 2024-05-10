#include <Servo.h> 
Servo servo1,servo2;
const int s0 = 8; 
const int s1 = 9; 
const int s2 = 12; 
const int s3 = 11; 
const int out = 10;  
// Variables 
int red = 0; 
int green = 0; 
int blue = 0; 
   
void setup()  
{ 
  servo1.write(100);
  servo2.write(120);
  servo1.attach(5);
  servo2.attach(6);
  Serial.begin(9600);
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 
  pinMode(out, INPUT); 
  digitalWrite(s0, HIGH); 
  digitalWrite(s1, HIGH); 
} 
   
void loop()
{ 
  color();
  Serial.print("R Intensity:"); 
  Serial.print(red, DEC); 
  Serial.print(" G Intensity: "); 
  Serial.print(green, DEC); 
  Serial.print(" B Intensity : "); 
  Serial.print(blue, DEC); 
  //Serial.println(); 

  if ( red < green && red < blue && red < 20)
  { 
   Serial.println(" - (Red Color)"); 
   delay(1800);
 servo1.write(0);
  delay(1800);
  servo1.write(100);
  } 


  else if (green < red  && green < 20 ) 
  { 
   Serial.println(" - (Green Color)"); 
   delay(3200);
servo2.write(0);
  delay(3200);
  servo2.write(120);
  } 
  else{
  Serial.println(" - (No color detected)"); 
  }
 delay(300);
 } 
   
void color() 
{   
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  //count OUT, pRed, RED 
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  digitalWrite(s3, HIGH); 
  //count OUT, pBLUE, BLUE 
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  digitalWrite(s2, HIGH); 
  //count OUT, pGreen, GREEN 
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
}