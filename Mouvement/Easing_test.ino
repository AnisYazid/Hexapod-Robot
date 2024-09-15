#include <Wire.h>
#include <Adafruit_PCA9685.h>


Adafruit_PCA9685 pwm = Adafruit_PCA9685();

const int NUM_SERVOS=3;
const int SERVOMIN= 900 ;
const int SERVOMax=2100 ;

int standingPosition[NUM_SERVOS] ={ 100, 100 , 100};

uint16_t servoAngleToPWM( int angle){
  return map(angle,0,180, SERVOMIN, SERVOMAX);
}

float easeOutCubic(float x){
  return pow(x-1,3)+1;
}

void home(){
  for (int i=0;i<NUM_SERVOS;i++){

pwm.setPWM(i,0,servoAngleToPWM(standingPosition[i]));
  }
}


void setServoPosition(float t){
 float easeValue= easeOutCubic(t);
for(int i=0;i<NUM8SERVOS;i++){
int position =ma( easeValue,0,1, SERVOMIN,SERVOMAX);
pwm.setPWM(i,0,position);
}
}

void setup { 
  pwm.begin();
pwm.setPWMFreq(60);
home();
}

void loop {
  for(float t=0;t<=1; t+=0.01){
setServoPosition(t);
delay();
  }
delay();
for(float t=1;t>=0; t-=0.01){
setServoPosition(t);
delay();
  }




