#include <Servo.h>                                      //servo library
Servo topServo;                                         //first servo
Servo bottomServo;                                      //second servo
const int s2=6;                                         //setting s2 to pwm pin 6
const int s3=7;                                         //setting s3 to pwm pin 7
const int sensor_output=8;                              //the sensor output will be recieved at digital pin 8
void setup()                                            //initializing pin configration
{
topServo.attach(10);                           
bottomServo.attach(11);
pinMode(s2,OUTPUT);
pinMode(s3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,HIGH);                                        //s0 is set to high voltage and
pinMode(5,LOW);                                         //s1 is set to low voltage for 20% frequency scaling
Serial.begin(9600);
topServo.write(70);
}
void loop() 
{
Serial.println("START");
int colorNumber=0;                                      //stores a numerical value corresponding to the color read by the sensor
//Serial.println("MOVING TOP SERVO TO 90");
//Serial.println("MOVED TOP SERVO TO 90, noy DELAYING FOR 500MS");
delay(500);
//Serial.println("DELAYED FOR 500MS, NOW MOVING TOPSERVO TO THE SENSOR");
for(int i=70; i>35; i--)                                //moving the gem to the sensor
{
topServo.write(i);
delay(3);
}
//Serial.println("MOVED TOP SERVO TO THE SENSOR, NOW READING THE COLOR");
delay(3000);
colorNumber=readColor();                                //calling a function to read the color of the gem
delay(3000);
//Serial.println("MOVING BOTTOMSERVO");
switch(colorNumber)                                     //switch case to set bottomServo to appropriate position
{
case 1:                                                 //red color
bottomServo.write(0);
break; 
case 2:                                                 //green color
bottomServo.write(60);
break;
case 3:                                                 //yellow color
bottomServo.write(120);
break;
case 4:                                                 //purple color
bottomServo.write(90);
break;
case 0:                                                 //unrequired color
bottomServo.write(180);
Serial.println("UNREQUIRED COLOR");
break;
}
//Serial.println("MOVED BOTTOMSERVO, NOW DROPPING THE GEM BY MOVING TOPSERVO");
//delay(300);                                             
for(int i=35; i>=17; i--)                              //dropping the gem into the corresponding hopper
{
topServo.write(i);
delay(2);
}
//Serial.println("DROPPED THE GEM, NOW RETURNING TOP SERVO TO ITS OG POSITION");
delay(3000);                    
for(int i=17; i<=70; i++)
{
topServo.write(i);                                     //returning topServo to its initial position                             
delay(3);
}
delay(1000);
//Serial.println("END");
Serial.println();
}
int readColor()                                         //function to read the color of the gem below the color sensro and return a value
{
int r=0; int g=0; int b=0;                              //the frequency value of each color will be stored in these variables

for(int i=0; i<15; i++)
{
  
digitalWrite(s2,LOW);                                   //reading frequency of red color
digitalWrite(s3,LOW);
r=((r+(pulseIn(sensor_output,LOW)))/2);

digitalWrite(s2,HIGH);                                  //reading frequency of green color
digitalWrite(s3,HIGH);
g=((g+(pulseIn(sensor_output,LOW)))/2);

digitalWrite(s2,LOW);                                   //reading frequency of blue color
digitalWrite(s3,HIGH);
b=((b+(pulseIn(sensor_output,LOW)))/2);
}
Serial.print("r=");
Serial.print(r);
Serial.print(" g=");
Serial.print(g);
Serial.print(" b=");
Serial.println(b);
Serial.println("THE COLOR HAS BEEN READ");
if((r>189&&r<199)&&(g>220&&g<230))
return 1;                                               //the color is red
else if((r>211&&r<221)&&(g>220&&g<230))
return 2;                                               //the color is green
else if((r>182&&r<192)&&(g>237&&g<247))
return 3;                                               //the color is yellow
else if((r>210&&r<220)&&(g>235&&g<245))
return 4;                                               //the color is purple
else
return 0;                                               
}
