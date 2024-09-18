#include <Wire.h>
#include <Adafruit_PCA9685.h>


Adafruit_PCA9685 pwm = Adafruit_PCA9685();

const int NUM_SERVOS=3;
const int SERVOMIN= 900 ;
const int SERVOMax=2100 ;

int standingPosition[NUM_SERVOS] ={ 100, 100 , 100};

uint16_t servoAngleToPWM( int angle)
{
  return map(angle,0,200, SERVOMIN, SERVOMAX);
}

float easeOutCubic(float x)
{
  return pow(x-1,3)+1;
}



void setServoPosition(float t)
{
  float easeValue= easeOutCubic(t);

  for(int i=0;i<NUM8SERVOS;i++)
   {
     int position =ma( easeValue,0,200, SERVOMIN,SERVOMAX);
      pwm.setPWM(i,0,position);
   }
}

void setup ()
{ 
  pwm.begin();
  pwm.setPWMFreq(60);

}

void loop ()
{
  //easing motion from 0 to 1
  // 0 for the starting transition and 1 for the end 
   for(float angle=0;angle<=1;angle+=1)
     {
       setSeroPosition(angle);
       delay(1000);
     }
  //from 1 to 0 
   for(float angle=1;angle>=0;t-=1)
     {
       setSeroPosition(angle);
       delay(1000);
     }
}




