#include "sbus.h" // Include the SBUS library

using bfs::SbusRx;    // Bring SbusRx into the current scope
using bfs::SbusData;  // Bring SbusData into the current scope

// Define your RX and TX pins
const int8_t RX_PIN = 16; // Replace with your actual RX pin


/* SBUS object for reading SBUS */
SbusRx sbus_rx(&Serial2, RX_PIN,-1, true, false); // Adjust the last two bools as needed
/* SBUS object for writing SBUS */
SbusData data;

//////////////////////////////////////////

#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

long timer = 0;

//////////////////////////////////////////

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> // Include the PWM driver library

// Define addresses for the two PCA9685 modules
Adafruit_PWMServoDriver pwm_R = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pwm_L = Adafruit_PWMServoDriver(0x42);

// Define pulse values for each servo

// Module 1 Servos/////////////////////////////////////////////////////////////////////

#define SERVO1_A1_MIN_PULSE 600 // Minimum pulse width for Servo 1 on Module 1
#define SERVO1_A1_MAX_PULSE 2600 // Maximum pulse width for Servo 1 on Module 1

#define SERVO1_A2_MIN_PULSE 600 // Minimum pulse width for Servo 2 on Module 1
#define SERVO1_A2_MAX_PULSE 2600 // Maximum pulse width for Servo 2 on Module 1

#define SERVO1_A3_MIN_PULSE 600 // Minimum pulse width for Servo 3 on Module 1
#define SERVO1_A3_MAX_PULSE 2600 // Maximum pulse width for Servo 3 on Module 1

#define SERVO1_B1_MIN_PULSE 600 // Minimum pulse width for Servo 4 on Module 1
#define SERVO1_B1_MAX_PULSE 2600 // Maximum pulse width for Servo 4 on Module 1

#define SERVO1_B2_MIN_PULSE 600 // Minimum pulse width for Servo 5 on Module 1
#define SERVO1_B2_MAX_PULSE 2600 // Maximum pulse width for Servo 5 on Module 1

#define SERVO1_B3_MIN_PULSE 600 // Minimum pulse width for Servo 6 on Module 1
#define SERVO1_B3_MAX_PULSE 2600 // Maximum pulse width for Servo 6 on Module 1

#define SERVO1_C1_MIN_PULSE 600 // Minimum pulse width for Servo 7 on Module 1
#define SERVO1_C1_MAX_PULSE 2600 // Maximum pulse width for Servo 7 on Module 1

#define SERVO1_C2_MIN_PULSE 600 // Minimum pulse width for Servo 8 on Module 1
#define SERVO1_C2_MAX_PULSE 2600 // Maximum pulse width for Servo 8 on Module 1

#define SERVO1_C3_MIN_PULSE 800 // Minimum pulse width for Servo 9 on Module 1
#define SERVO1_C3_MAX_PULSE 2700 // Maximum pulse width for Servo 9 on Module 1

// Module 2 Servos //////////////////////////////////////////////////////////////////////////

#define SERVO2_D1_MIN_PULSE 500 // Minimum pulse width for Servo 1 on Module 2
#define SERVO2_D1_MAX_PULSE 2500 // Maximum pulse width for Servo 1 on Module 2

#define SERVO2_D2_MIN_PULSE 700 // Minimum pulse width for Servo 2 on Module 2
#define SERVO2_D2_MAX_PULSE 2600 // Maximum pulse width for Servo 2 on Module 2

#define SERVO2_D3_MIN_PULSE 700 // Minimum pulse width for Servo 3 on Module 2
#define SERVO2_D3_MAX_PULSE 2600 // Maximum pulse width for Servo 3 on Module 2

#define SERVO2_E1_MIN_PULSE 600 // Minimum pulse width for Servo 4 on Module 2
#define SERVO2_E1_MAX_PULSE 2600 // Maximum pulse width for Servo 4 on Module 2

#define SERVO2_E2_MIN_PULSE 600 // Minimum pulse width for Servo 5 on Module 2
#define SERVO2_E2_MAX_PULSE 2600 // Maximum pulse width for Servo 5 on Module 2

#define SERVO2_E3_MIN_PULSE 600 // Minimum pulse width for Servo 6 on Module 2
#define SERVO2_E3_MAX_PULSE 2600 // Maximum pulse width for Servo 6 on Module 2

#define SERVO2_F1_MIN_PULSE 600 // Minimum pulse width for Servo 7 on Module 2
#define SERVO2_F1_MAX_PULSE 2600 // Maximum pulse width for Servo 7 on Module 2

#define SERVO2_F2_MIN_PULSE 600 // Minimum pulse width for Servo 8 on Module 2
#define SERVO2_F2_MAX_PULSE 2600 // Maximum pulse width for Servo 8 on Module 2

#define SERVO2_F3_MIN_PULSE 600 // Minimum pulse width for Servo 9 on Module 2
#define SERVO2_F3_MAX_PULSE 2600 // Maximum pulse width for Servo 9 on Module 2

////////////////////////////////

const int ledPinB = 4;
const int ledPinR = 25;
const int ledPinG = 2;


void setup()
{
    Serial.begin(115200);    /* Serial to display data */

    pwm_R.begin();
    pwm_R.setPWMFreq(50); // Set frequency to 50 Hz for servos

    pwm_L.begin();
    pwm_L.setPWMFreq(50); // Set frequency to 50 Hz for servos

      /* Begin the SBUS communication */
    sbus_rx.Begin(); // Initialize SBUS receiver


    Wire.begin();
    byte status = mpu.begin();
    mpu.calcOffsets(true, true);

    pinMode(ledPinB, OUTPUT);
    pinMode(ledPinR, OUTPUT);
    pinMode(ledPinG, OUTPUT);
    pinMode(26, OUTPUT); 
   
    digitalWrite(ledPinB, LOW);
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinG, LOW);

    tone (26, 600); 
    delay(200);
    tone (26, 1000);
    delay(200);
    noTone(26);
    delay(3000);
}

//////////////////////////////////////////////////////////

void loop ()
{
int f=90;
int a=30;
int i;
int j;
        
/*
    
     if (sbus_rx.Read()) 
     {
        digitalWrite(ledPinB, HIGH);
        data = sbus_rx.data(); // Retrieve the received SBUS data

        
       if (data.ch[4] == 1694) // value to check and Channel  
        {
              digitalWrite(ledPinG, HIGH);
              home();  
        }
        else if (data.ch[4] == 306) 
        {
              digitalWrite(ledPinG, HIGH);         
              stand();
        }
        else if (data.ch[8] == 306)
        {
          digitalWrite(ledPinG,HIGH);
          UP_DW();
        }
        
        else if (data.ch[10] == 306)
        {
          digitalWrite(ledPinG,HIGH);
          Tilt();
          setServoPosition(pwm_L, 2, 90);      // A1
          setServoPosition(pwm_L, 6, 85);      // B1
          setServoPosition(pwm_L, 15, 90);     // C1
          setServoPosition(pwm_R, 15, 80);     // D1
          setServoPosition(pwm_R, 6, 85);      // E1
          setServoPosition(pwm_R, 2, 100);     // F1
          
        } 
        else if (data.ch[10] == 1694)
        {
          digitalWrite(ledPinG,HIGH);
          kabrage();
          setServoPosition(pwm_L, 2, 90);      // A1
          setServoPosition(pwm_L, 6, 85);      // B1
          setServoPosition(pwm_L, 15, 90);     // C1
          setServoPosition(pwm_R, 15, 80);     // D1
          setServoPosition(pwm_R, 6, 85);      // E1
          setServoPosition(pwm_R, 2, 100);     // F1
          
        } 
        
        else if (data.ch[9] == 306)
        {
          digitalWrite(ledPinG,HIGH);
          D_G();
         
          setServoPosition(pwm_L, 2, 90);      // A1
          setServoPosition(pwm_L, 6, 85);      // B1
          setServoPosition(pwm_L, 15, 90);     // C1
          setServoPosition(pwm_R, 15, 80);     // D1
          setServoPosition(pwm_R, 6, 85);      // E1
          setServoPosition(pwm_R, 2, 100);     // F1
        }
        

     } */

      for( int f=50,  a=135;f<=120,a>=45 ;f++,a--)
      {
        
       
           setServoPosition(pwm_L, 1, f);     // A2
            setServoPosition(pwm_L, 0, f);     // A3
            setServoPosition(pwm_L, 14, f);    // C2
            setServoPosition(pwm_L, 13, f);    // C3
            setServoPosition(pwm_R, 5, a);      // E2
            setServoPosition(pwm_R, 4, a);       // E3
            
           /* setServoPosition(pwm_R, 14, f);     // D2
            setServoPosition(pwm_R, 13, f);     // D3
            setServoPosition(pwm_L, 5, f);     // B2
            setServoPosition(pwm_L, 4, f);     // B3
            setServoPosition(pwm_R, 1, f);      // F2
            setServoPosition(pwm_R, 0, f);       // F3*/
    
            
            
       }
delay(500);

  /*  for ( int i= 120 , j=60; j<=120 , i>= 60; j++ ,i--)
    {
                   setServoPosition(pwm_L, 2, i);      // A1
                   setServoPosition(pwm_L, 15, i);     // C1
                   setServoPosition(pwm_R, 6, j);      // E1
                   
                /*   setServoPosition(pwm_L, 6, j);      // B1
                   setServoPosition(pwm_R, 15, i);     // D1
                   setServoPosition(pwm_R, 2, i);     // F1*/
    
    
    

    
   for( int f=120, a=50 ; f>=50,a<=120 ; f--, a++){
        
       
            setServoPosition(pwm_L, 1, f);     // A2  
            setServoPosition(pwm_L, 0, f);     // A3
             setServoPosition(pwm_L, 14, f);    // C2
             setServoPosition(pwm_L, 13, f);    // C3
             setServoPosition(pwm_R, 5, a);      // E2
             setServoPosition(pwm_R, 4, a);       // E3
             
        /*     setServoPosition(pwm_R, 14, a);     // D2
             setServoPosition(pwm_R, 13, a);     // D3
             setServoPosition(pwm_L, 5, f);     // B2
              setServoPosition(pwm_L, 4, f);     // B3
             setServoPosition(pwm_R, 1, a);      // F2
             setServoPosition(pwm_R, 0, a);       // F3*/
             
       }
       delay(500);

       /*   for ( int i= 30 , j=120; j>=30 , i<= 120 ; j-- ,i++)
    {
                   setServoPosition(pwm_L, 2, i);      // A1
                   setServoPosition(pwm_L, 15, i);     // C1
                   setServoPosition(pwm_R, 6, j);      // E1
                   
              /*     setServoPosition(pwm_L, 6, j);      // B1
                   setServoPosition(pwm_R, 15, i);     // D1
                   setServoPosition(pwm_R, 2, i);     // F1
    }
    delay(500);*/
     
}
     


////////////////////////////////////////////////////////////

void setServoPosition(Adafruit_PWMServoDriver &pwm, int channel, int angle) 
{
    int pulseWidth;

    // Determine pulseWidth based on the angle
    switch (channel) 
    {
        case 0: // A1
            pulseWidth = map(angle, 0, 180, SERVO1_A1_MIN_PULSE, SERVO1_A1_MAX_PULSE);
            break;
        case 1: // A2
            pulseWidth = map(angle, 0, 180, SERVO1_A2_MIN_PULSE, SERVO1_A2_MAX_PULSE);
            break;
        case 2: // A3
            pulseWidth = map(angle, 0, 180, SERVO1_A3_MIN_PULSE, SERVO1_A3_MAX_PULSE);
            break;
        case 3: // B1
            pulseWidth = map(angle, 0, 180, SERVO1_B1_MIN_PULSE, SERVO1_B1_MAX_PULSE);
            break;
        case 4: // B2
            pulseWidth = map(angle, 0, 180, SERVO1_B2_MIN_PULSE, SERVO1_B2_MAX_PULSE);
            break;
        case 5: // B3
            pulseWidth = map(angle, 0, 180, SERVO1_B3_MIN_PULSE, SERVO1_B3_MAX_PULSE);
            break;
        case 6: // C1
            pulseWidth = map(angle, 0, 180, SERVO1_C1_MIN_PULSE, SERVO1_C1_MAX_PULSE);
            break;
        case 7: // C2
            pulseWidth = map(angle, 0, 180, SERVO1_C2_MIN_PULSE, SERVO1_C2_MAX_PULSE);
            break;
        case 8: // C3
            pulseWidth = map(angle, 0, 180, SERVO1_C3_MIN_PULSE, SERVO1_C3_MAX_PULSE);
            break;
        case 9: // D1
            pulseWidth = map(angle, 0, 180, SERVO2_D1_MIN_PULSE, SERVO2_D1_MAX_PULSE);
            break;
        case 10: // D2
            pulseWidth = map(angle, 0, 180, SERVO2_D2_MIN_PULSE, SERVO2_D2_MAX_PULSE);
            break;
        case 11: // D3
            pulseWidth = map(angle, 0, 180, SERVO2_D3_MIN_PULSE, SERVO2_D3_MAX_PULSE);
            break;
        case 12: // E1
            pulseWidth = map(angle, 0, 180, SERVO2_E1_MIN_PULSE, SERVO2_E1_MAX_PULSE);
            break;
        case 13: // E2
            pulseWidth = map(angle, 0, 180, SERVO2_E2_MIN_PULSE, SERVO2_E2_MAX_PULSE);
            break;
        case 14: // E3
            pulseWidth = map(angle, 0, 180, SERVO2_E3_MIN_PULSE, SERVO2_E3_MAX_PULSE);
            break;
        case 15: // F1
            pulseWidth = map(angle, 0, 180, SERVO2_F1_MIN_PULSE, SERVO2_F1_MAX_PULSE);
            break;
        case 16: // F2
            pulseWidth = map(angle, 0, 180, SERVO2_F2_MIN_PULSE, SERVO2_F2_MAX_PULSE);
            break;
        case 17: // F3
            pulseWidth = map(angle, 0, 180, SERVO2_F3_MIN_PULSE, SERVO2_F3_MAX_PULSE);
            break;
        default:
            pulseWidth = SERVO1_A1_MIN_PULSE; // Default case if channel is not recognized
            break;
    }

    // Calculate the PWM value
    int pulseValue = int(float(pulseWidth) / 1000000 * 50 * 4096);
    
    // Set the PWM on the specified channel
    pwm.setPWM(channel, 0, pulseValue);
}

void stand() 
{  

   int f=50;
   int a=120;
   
    setServoPosition(pwm_L, 2, 90);      // A1
    setServoPosition(pwm_L, 1, f);     // A2
    setServoPosition(pwm_L, 0, f);     // A3
    
    setServoPosition(pwm_L, 6, 85);      // B1
    setServoPosition(pwm_L, 5, f);     // B2
    setServoPosition(pwm_L, 4, f);     // B3
    
    setServoPosition(pwm_L, 15, 90);     // C1
    setServoPosition(pwm_L, 14, f);    // C2
    setServoPosition(pwm_L, 13, f);    // C3
   
    setServoPosition(pwm_R, 15, 80);     // D1
    setServoPosition(pwm_R, 14, a);     // D2
    setServoPosition(pwm_R, 13, a);     // D3
   
    setServoPosition(pwm_R, 6, 85);      // E1
    setServoPosition(pwm_R, 5, a);      // E2
    setServoPosition(pwm_R, 4, a);       // E3
   
    setServoPosition(pwm_R, 2, 100);     // F1
    setServoPosition(pwm_R, 1, a);      // F2
    setServoPosition(pwm_R, 0, a);       // F3
}

void home() 
{  
    int f=120;
    int a= 50;
    
    setServoPosition(pwm_L, 2, 90);      // A1
    setServoPosition(pwm_L, 1, f);     // A2
    setServoPosition(pwm_L, 0, f);     // A3
    
    setServoPosition(pwm_L, 6, 85);      // B1
    setServoPosition(pwm_L, 5, f);     // B2
    setServoPosition(pwm_L, 4, f);     // B3
    
    setServoPosition(pwm_L, 15, 90);     // C1
    setServoPosition(pwm_L, 14, f);    // C2
    setServoPosition(pwm_L, 13, f);    // C3
   
    setServoPosition(pwm_R, 15, 80);     // D1
    setServoPosition(pwm_R, 14, a);     // D2
    setServoPosition(pwm_R, 13, a);     // D3
   
    setServoPosition(pwm_R, 6, 85);      // E1
    setServoPosition(pwm_R, 5, a);      // E2
    setServoPosition(pwm_R, 4, a);       // E3
   
    setServoPosition(pwm_R, 2, 100);     // F1
    setServoPosition(pwm_R, 1, a);      // F2
    setServoPosition(pwm_R, 0, a);       // F3
}

void forward() 
{

  
       setServoPosition(pwm_L, 1, 105);     // A2
       setServoPosition(pwm_R, 5, 60);      // E2
       setServoPosition(pwm_L, 14, 120);    // C2
       ////
       setServoPosition(pwm_L, 0, 160);     // A3
       setServoPosition(pwm_R, 4, 5);       // E3
       setServoPosition(pwm_L, 13, 185);    // C3

        delay(300);

       setServoPosition(pwm_L, 2, 90);      // A1
       setServoPosition(pwm_R, 6, 85);      // E1
       setServoPosition(pwm_L, 15, 90);     // C1
       //// 
       setServoPosition(pwm_R, 15, 80);     // D1
       setServoPosition(pwm_L, 6, 85);      // B1
       setServoPosition(pwm_R, 2, 100);     // F1

        delay(300);  

       setServoPosition(pwm_L, 1, 105);     // A2
       setServoPosition(pwm_R, 5, 60);      // E2
       setServoPosition(pwm_L, 14, 120);    // C2
       ////
       setServoPosition(pwm_L, 0, 160);     // A3
       setServoPosition(pwm_R, 4, 5);       // E3
       setServoPosition(pwm_L, 13, 185);    // C3

        delay(1000);

       //////////////////////////////////////////////////////////

       setServoPosition(pwm_R, 14, 65);     // D2
       setServoPosition(pwm_L, 5, 120);     // B2
       setServoPosition(pwm_L, 5, 120);     // B2
       ////
       setServoPosition(pwm_R, 13, 25);     // D3
       setServoPosition(pwm_L, 4, 170);     // B3
       setServoPosition(pwm_R, 0, 0);       // F3

        delay(300);

       setServoPosition(pwm_R, 15, 80);     // D1
       setServoPosition(pwm_L, 6, 85);      // B1
       setServoPosition(pwm_R, 2, 100);     // F1
       ////
       setServoPosition(pwm_L, 2, 90);      // A1
       setServoPosition(pwm_R, 6, 85);      // E1
       setServoPosition(pwm_L, 15, 90);     // C1

        delay(300);
       setServoPosition(pwm_R, 14, 65);     // D2
       setServoPosition(pwm_L, 5, 120);     // B2
       setServoPosition(pwm_L, 5, 120);     // B2
       ////
       setServoPosition(pwm_R, 13, 25);     // D3
       setServoPosition(pwm_L, 4, 170);     // B3
       setServoPosition(pwm_R, 0, 0);       // F3

        delay(1000);

}

void backward() 
{
       setServoPosition(pwm_L, 1, 105);     // A2
       setServoPosition(pwm_R, 5, 60);      // E2
       setServoPosition(pwm_L, 14, 120);    // C2
       ////
       setServoPosition(pwm_L, 0, 160);     // A3
       setServoPosition(pwm_R, 4, 5);       // E3
       setServoPosition(pwm_L, 13, 185);    // C3

        delay(300);

       setServoPosition(pwm_L, 2, 90);      // A1
       setServoPosition(pwm_R, 6, 85);      // E1
       setServoPosition(pwm_L, 15, 90);     // C1
       //// 
       setServoPosition(pwm_R, 15, 80);     // D1
       setServoPosition(pwm_L, 6, 85);      // B1
       setServoPosition(pwm_R, 2, 100);     // F1

        delay(300);  

       setServoPosition(pwm_L, 1, 105);     // A2
       setServoPosition(pwm_R, 5, 60);      // E2
       setServoPosition(pwm_L, 14, 120);    // C2
       ////
       setServoPosition(pwm_L, 0, 160);     // A3
       setServoPosition(pwm_R, 4, 5);       // E3
       setServoPosition(pwm_L, 13, 185);    // C3

        delay(1000);

       //////////////////////////////////////////////////////////

       setServoPosition(pwm_R, 14, 65);     // D2
       setServoPosition(pwm_L, 5, 120);     // B2
       setServoPosition(pwm_L, 5, 120);     // B2
       ////
       setServoPosition(pwm_R, 13, 25);     // D3
       setServoPosition(pwm_L, 4, 170);     // B3
       setServoPosition(pwm_R, 0, 0);       // F3

        delay(300);

       setServoPosition(pwm_R, 15, 80);     // D1
       setServoPosition(pwm_L, 6, 85);      // B1
       setServoPosition(pwm_R, 2, 100);     // F1
       ////
       setServoPosition(pwm_L, 2, 90);      // A1
       setServoPosition(pwm_R, 6, 85);      // E1
       setServoPosition(pwm_L, 15, 90);     // C1

        delay(300);
       setServoPosition(pwm_R, 14, 65);     // D2
       setServoPosition(pwm_L, 5, 120);     // B2
       setServoPosition(pwm_L, 5, 120);     // B2
       ////
       setServoPosition(pwm_R, 13, 25);     // D3
       setServoPosition(pwm_L, 4, 170);     // B3
       setServoPosition(pwm_R, 0, 0);       // F3

        delay(1000);

}

void Tilt() // this is the code for up and down no tilt 
{
   int f ;
   int a ;


  for ( f=50,a=120 ;a>=50, f<= 120;f++,a--)
  {
       setServoPosition(pwm_L, 1, f);     // A2
       setServoPosition(pwm_L, 0, f);     // A3

       setServoPosition(pwm_L, 5, f);     // B2
       setServoPosition(pwm_L, 4, f);     // B3

       setServoPosition(pwm_L, 14, f);    // C2
       setServoPosition(pwm_L, 13, f);    // C3

       setServoPosition(pwm_R, 14, f);     // D2
       setServoPosition(pwm_R, 13, f);     // D3

       setServoPosition(pwm_R, 1, f);      // F2
       setServoPosition(pwm_R, 0, f);       // F3

       setServoPosition(pwm_R, 5, f);      // E2
       setServoPosition(pwm_R, 4, f);       // E3
       delay(15);
   }

      for ( f=120,a=50 ;a<=120, f>= 50;a++,f--)
      {
       setServoPosition(pwm_L, 1, f);     // A2
       setServoPosition(pwm_L, 0, f);     // A3

       setServoPosition(pwm_L, 5, f);     // B2
       setServoPosition(pwm_L, 4, f);     // B3

       setServoPosition(pwm_L, 14, f);    // C2
       setServoPosition(pwm_L, 13, f);    // C3

       setServoPosition(pwm_R, 14, f);     // D2
       setServoPosition(pwm_R, 13, f);     // D3

       setServoPosition(pwm_R, 1, f);      // F2
       setServoPosition(pwm_R, 0, f);       // F3

       setServoPosition(pwm_R, 5, f);      // E2
       setServoPosition(pwm_R, 4, f);       // E3
       delay(15);
   }
}


void UP_DW() 
{  

   float F = map(data.ch[11], 306, 1694, 50, 120);
   float A = map(data.ch[11], 306, 1694, 120, 50);
   
    setServoPosition(pwm_L, 2, 90);      // A1
    setServoPosition(pwm_L, 1, F);     // A2
    setServoPosition(pwm_L, 0, F);     // A3
    
    setServoPosition(pwm_L, 6, 85);      // B1
    setServoPosition(pwm_L, 5, F);     // B2
    setServoPosition(pwm_L, 4, F);     // B3
    
    setServoPosition(pwm_L, 15, 90);     // C1
    setServoPosition(pwm_L, 14, F);    // C2
    setServoPosition(pwm_L, 13, F);    // C3
   
    setServoPosition(pwm_R, 15, 80);     // D1
    setServoPosition(pwm_R, 14, A);     // D2
    setServoPosition(pwm_R, 13, A);     // D3
   
    setServoPosition(pwm_R, 6, 85);      // E1
    setServoPosition(pwm_R, 5, A);      // E2
    setServoPosition(pwm_R, 4, A);       // E3
   
    setServoPosition(pwm_R, 2, 100);     // F1
    setServoPosition(pwm_R, 1, A);      // F2
    setServoPosition(pwm_R, 0, A);       // F3
}


void D_G()
{
     int T = map(data.ch[0], 306, 1694, 120, 50);
       
    setServoPosition(pwm_L, 2, 90);      // A1
    setServoPosition(pwm_L, 1, T);     // A2
    setServoPosition(pwm_L, 0, T);     // A3
    
    setServoPosition(pwm_L, 6, 85);      // B1
    setServoPosition(pwm_L, 5, T);     // B2
    setServoPosition(pwm_L, 4, T);     // B3
    
    setServoPosition(pwm_L, 15, 90);     // C1
    setServoPosition(pwm_L, 14, T);    // C2
    setServoPosition(pwm_L, 13, T);    // C3
   
    setServoPosition(pwm_R, 15, 80);     // D1
    setServoPosition(pwm_R, 14, T);     // D2
    setServoPosition(pwm_R, 13, T);     // D3
   
    setServoPosition(pwm_R, 6, 85);      // E1
    setServoPosition(pwm_R, 5, T);      // E2
    setServoPosition(pwm_R, 4, T);       // E3
   
    setServoPosition(pwm_R, 2, 100);     // F1
    setServoPosition(pwm_R, 1, T);      // F2
    setServoPosition(pwm_R, 0, T);       // F3
  
}

void kabrage()
{

   float F = map(data.ch[1], 306, 1694, 50, 120);
   float A = map(data.ch[1], 306, 1694, 120, 50);

    
    setServoPosition(pwm_L, 2, 90);      // A1
    setServoPosition(pwm_L, 1, A);      // A2
    setServoPosition(pwm_L, 0, A);     // A3
    
    setServoPosition(pwm_L, 6, 85);      // B1
    setServoPosition(pwm_L, 5, 110);     // B2
    setServoPosition(pwm_L, 4, 110);     // B3
    
    setServoPosition(pwm_L, 15, 90);     // C1
    setServoPosition(pwm_L, 14, F);    // C2
    setServoPosition(pwm_L, 13, F);    // C3
   
    setServoPosition(pwm_R, 15, 80);     // D1
    setServoPosition(pwm_R, 14, F);     // D2
    setServoPosition(pwm_R, 13, F);     // D3
   
    setServoPosition(pwm_R, 6, 85);      // E1
    setServoPosition(pwm_R, 5, 60);      // E2
    setServoPosition(pwm_R, 4, 60);       // E3
   
    setServoPosition(pwm_R, 2, 100);     // F1
    setServoPosition(pwm_R, 1, A);      // F2
    setServoPosition(pwm_R, 0, A);       // F3
}