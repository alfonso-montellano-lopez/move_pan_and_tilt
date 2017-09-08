#include <Servo.h>

#define IN1 12 //DSF
#define IN2 13 //P&T

const int tilt = 3;       // first servo
const int pan = 5;       // second servo

float servoDelta; //amount to change the servo position
int servoVal;  // variable to read the value from the analog pin
unsigned long wait = 0.1;         //time to wait between loops
unsigned long nextTime;
float pan_pos = 95.0;
float tilt_pos = 145.0;

float FIXED_PAN_POS = 95.0;//deg:: range 0 (70 anticlockwise), 95 (mid), (140 clockwise) 270
float FIXED_TILT_POS = 125.0;//deg:: range 55(up), 145(hor)//some looseness makes it show no motion between 145 and 125 (16082017)
Servo tiltservo;  // create servo object to control a servo
Servo panservo;  // create servo object to control a servo



void setup() {

  //Relay:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  // Servo  
  tiltservo.attach(tilt);  // attaches the servo
  panservo.attach(pan);  // attaches the servo

  // Inizialize Serial
  Serial.begin(9600);
  nextTime = millis() + wait;
}


void loop(){

//if ((long)(millis() - nextTime) >= 0){  //sets the loop frequency, ? hz in this case

pan_pos = FIXED_PAN_POS;

if (pan_pos > 140){
  pan_pos = 140;
}
if (pan_pos < 70){
  pan_pos = 70;
}
panservo.write(pan_pos);                         // sets the servo position according to the scaled value

tilt_pos = FIXED_TILT_POS;

if (tilt_pos > 145){
  tilt_pos = 145;
}
if (tilt_pos < 55){
  tilt_pos = 55;
}
tiltservo.write(tilt_pos);                           // sets the servo position according to the scaled value
//}
}
