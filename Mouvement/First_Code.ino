#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "IRremote.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)


int IrReceiverPin = 8; 
uint8_t servonum = 0;
/////////////////////////////////// 
const int pinX = A0 ;
const int pinY = A1 ;
const int pinBouton = 9 ;
int prev;

/////////////////////////////////////


decode_results results;

 IRrecv irrecv(IrReceiverPin);


/////////////////////////////////////
int Ta7wila(int ang)  /////// Function for the map of the angles  
{
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX); // map angle of 0 to 180 to Servo min and Servo max 
   return pulse;

   // CHECK THE BLOCKNOTE FOR THE MAX AND MIN ANGELS FOR EACH SIDE OF THE SPIDER

    ///////////  F E D  //////////////////////// min ang 0  max 90
    //////////   C B A  ///////////////////////  max ang 140  min 50
}



  void S()
  {
////////////////////////////////////////////////////////
  pwm.setPWM(0, 0, Ta7wila(100) );  //A2 
  pwm.setPWM(12, 0, Ta7wila(100) ); //B2     
  pwm.setPWM(1, 0, Ta7wila(100) );  //C2
  
  pwm.setPWM(2, 0, Ta7wila(60) );  //F2
  pwm.setPWM(3, 0, Ta7wila(55) );  //D2
  pwm.setPWM(13, 0, Ta7wila(52) ); //E2
  ///////////////////////////////////////////////////////

  pwm.setPWM(4, 0, Ta7wila(50) ); //F3/D3
  pwm.setPWM(6, 0, Ta7wila(100) ); //A3/C3
  pwm.setPWM(7, 0, Ta7wila(106) ); //B3
  pwm.setPWM(5, 0, Ta7wila(45) ); //E3


////////////////////////////////////////////////////////// 
  pwm.setPWM(8, 0, Ta7wila(73) );  //A1
  pwm.setPWM(11, 0, Ta7wila(98) ); //D1

  pwm.setPWM(14, 0, Ta7wila(75) ); //B1
  pwm.setPWM(15, 0, Ta7wila(80) ); //E1
  
  pwm.setPWM(9, 0, Ta7wila(100) );  //C1
  pwm.setPWM(10, 0, Ta7wila(70));  //F1

  /*delay(5000);
  pwm.setPWM(1, 0, Ta7wila(30) );  //C2
  delay(300);
   pwm.setPWM(9, 0, Ta7wila(160) );  //C1
   delay(300);
    pwm.setPWM(9, 0, Ta7wila(100) );  //C1
    delay(300);
    pwm.setPWM(1, 0, Ta7wila(100) );  //C2
    delay(300);*/
    
  
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void For()
{


 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////


  pwm.setPWM(2, 0, Ta7wila(80) );  // F2
  pwm.setPWM(12, 0, Ta7wila(80) );  // B2
  pwm.setPWM(3, 0, Ta7wila(80) );  // D2


 delay(300);

  pwm.setPWM(10, 0, Ta7wila(55) );  // F1
  pwm.setPWM(14, 0, Ta7wila(85) );  // B1
  pwm.setPWM(11, 0, Ta7wila(78) );  // D1
  
  pwm.setPWM(4, 0, Ta7wila(60) ); //F3/D3
  


//////////////////////////////////

   pwm.setPWM(9, 0, Ta7wila(80) );  // C1
   pwm.setPWM(15, 0, Ta7wila(90) ); // E1
   pwm.setPWM(8, 0, Ta7wila(53) );  // A1
   
     pwm.setPWM(6, 0, Ta7wila(100) ); //A3/C3
       pwm.setPWM(5, 0, Ta7wila(45) ); //E3



delay(300);

  pwm.setPWM(2, 0, Ta7wila(60) );   // F2
  pwm.setPWM(12, 0, Ta7wila(100) );  // B2
  pwm.setPWM(3, 0, Ta7wila(50) );   // D2


delay(300);

 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////


   pwm.setPWM(1, 0, Ta7wila(70) );  // C2
   pwm.setPWM(13, 0, Ta7wila(77) ); // E2
   pwm.setPWM(0, 0, Ta7wila(80) );  // A2

     pwm.setPWM(5, 0, Ta7wila(55) ); //E3



delay(300);
 
   pwm.setPWM(9, 0, Ta7wila(120) );  // C1
   pwm.setPWM(15, 0, Ta7wila(70) ); // E1
   pwm.setPWM(8, 0, Ta7wila(93) );  // A1
   
     pwm.setPWM(6, 0, Ta7wila(90) ); //A3/C3

  
  pwm.setPWM(10, 0, Ta7wila(90) );  // F1
  pwm.setPWM(14, 0, Ta7wila(65) );  // B1
  pwm.setPWM(11, 0, Ta7wila(118) );  // D1
 
  pwm.setPWM(4, 0, Ta7wila(50) ); //F3/D3

delay(300);

   pwm.setPWM(1, 0, Ta7wila(100) );  // C2
   pwm.setPWM(13, 0, Ta7wila(53) ); // E2 
   pwm.setPWM(0, 0, Ta7wila(105) );  // A2


 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////

delay(300);  


} 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void B()
{
 pwm.setPWM(1, 0, Ta7wila(70) );  // C2
   pwm.setPWM(13, 0, Ta7wila(87) ); // E2
   pwm.setPWM(0, 0, Ta7wila(80) );  // A2

     pwm.setPWM(5, 0, Ta7wila(65) ); //E3

delay(300);

  pwm.setPWM(9, 0, Ta7wila(80) );  // C1
   pwm.setPWM(15, 0, Ta7wila(90) ); // E1
   pwm.setPWM(8, 0, Ta7wila(53) );  // A1
   
     pwm.setPWM(6, 0, Ta7wila(100) ); //A3/C3
       pwm.setPWM(5, 0, Ta7wila(45) ); //E3



 pwm.setPWM(10, 0, Ta7wila(55) );  // F1
  pwm.setPWM(14, 0, Ta7wila(85) );  // B1
  pwm.setPWM(11, 0, Ta7wila(78) );  // D1
  
  pwm.setPWM(4, 0, Ta7wila(60) ); //F3/D3


  delay(300);
 pwm.setPWM(1, 0, Ta7wila(100) );  // C2
   pwm.setPWM(13, 0, Ta7wila(53) ); // E2 
   pwm.setPWM(0, 0, Ta7wila(105) );  // A2
delay(300);

  

  
  pwm.setPWM(2, 0, Ta7wila(80) );  // F2
  pwm.setPWM(12, 0, Ta7wila(80) );  // B2
  pwm.setPWM(3, 0, Ta7wila(80) );  // D2

delay(300);

 pwm.setPWM(10, 0, Ta7wila(90) );  // F1
  pwm.setPWM(14, 0, Ta7wila(65) );  // B1
  pwm.setPWM(11, 0, Ta7wila(118) );  // D1
  
  pwm.setPWM(4, 0, Ta7wila(50) ); //F3/D3


   pwm.setPWM(9, 0, Ta7wila(120) );  // C1
   pwm.setPWM(15, 0, Ta7wila(70) ); // E1
   pwm.setPWM(8, 0, Ta7wila(93) );  // A1
   
     pwm.setPWM(6, 0, Ta7wila(90) ); //A3/C3
     
delay(300);


  pwm.setPWM(2, 0, Ta7wila(60) );   // F2
  pwm.setPWM(12, 0, Ta7wila(100) );  // B2
  pwm.setPWM(3, 0, Ta7wila(50) );   // D2

delay(300);


 
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Rr()
{

  pwm.setPWM(4, 0, Ta7wila(60) ); //F3/D3
  pwm.setPWM(6, 0, Ta7wila(80) ); //A3/C3
  pwm.setPWM(7, 0, Ta7wila(90) ); //B3
  pwm.setPWM(5, 0, Ta7wila(60) ); //E3

  
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////

  
  pwm.setPWM(1, 0, Ta7wila(50) );  //C2
  pwm.setPWM(13, 0, Ta7wila(105) ); //E2
  pwm.setPWM(0, 0, Ta7wila(50) );  //A2

    delay(3000);

  pwm.setPWM(10, 0, Ta7wila(30) );  // F1
  pwm.setPWM(14, 0, Ta7wila(70) );  // B1
  pwm.setPWM(11, 0, Ta7wila(50) );  // D1

//////////////////////////////////

   pwm.setPWM(9, 0, Ta7wila(90) );  // C1
   pwm.setPWM(15, 0, Ta7wila(110) ); // E1
   pwm.setPWM(8, 0, Ta7wila(70) );  // A1

    delay(3000);

  pwm.setPWM(1, 0, Ta7wila(80) );  //C2
  pwm.setPWM(13, 0, Ta7wila(70) ); //E2
  pwm.setPWM(0, 0, Ta7wila(80) );  //A2

    delay(3000);
    
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////

 pwm.setPWM(2, 0, Ta7wila(100) );  //F2
 pwm.setPWM(12, 0, Ta7wila(60) ); //B2
 pwm.setPWM(3, 0, Ta7wila(100) );  //D2

   delay(3000);

  pwm.setPWM(10, 0, Ta7wila(110) );  // F1
  pwm.setPWM(14, 0, Ta7wila(900) );  // B1
  pwm.setPWM(11, 0, Ta7wila(120) );  // D1

//////////////////////////////////

   pwm.setPWM(9, 0, Ta7wila(100) );  // C1
   pwm.setPWM(15, 0, Ta7wila(40) ); // E1
   pwm.setPWM(8, 0, Ta7wila(60) );  // A1

  delay(3000);

 pwm.setPWM(2, 0, Ta7wila(70) );  //F2
 pwm.setPWM(12, 0, Ta7wila(80) ); //B1
 pwm.setPWM(3, 0, Ta7wila(70) );  //D2


 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 ////////////////////////////////////////////////////// 

 delay(3000);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Rl()
{

 pwm.setPWM(2, 0, Ta7wila(70) );  //F2
 pwm.setPWM(12, 0, Ta7wila(70) ); //B2
 pwm.setPWM(3, 0, Ta7wila(70) );  //D2
 
   delay(100);

  pwm.setPWM(10, 0, Ta7wila(70) );  // F1
  pwm.setPWM(14, 0, Ta7wila(70) );  // B1
  pwm.setPWM(11, 0, Ta7wila(70) );  // D1

//////////////////////////////////

   pwm.setPWM(9, 0, Ta7wila(70) );  // C1
   pwm.setPWM(15, 0, Ta7wila(70) ); // E1
   pwm.setPWM(8, 0, Ta7wila(70) );  // A1

   delay(100);
   
 pwm.setPWM(2, 0, Ta7wila(70) );  //F2
 pwm.setPWM(12, 0, Ta7wila(70) ); //B2
 pwm.setPWM(3, 0, Ta7wila(70) );  //D2
 
   delay(100);    

 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 ////////////////////////////////////////////////////// 

 pwm.setPWM(1, 0, Ta7wila(70) );  //C2
 pwm.setPWM(13, 0, Ta7wila(70) ); //E2
 pwm.setPWM(0, 0, Ta7wila(70) );  //A2
 
   delay(100);

  pwm.setPWM(10, 0, Ta7wila(70) );  // F1
  pwm.setPWM(14, 0, Ta7wila(70) );  // B1
  pwm.setPWM(11, 0, Ta7wila(70) );  // D1

//////////////////////////////////

   pwm.setPWM(9, 0, Ta7wila(70) );  // C1
   pwm.setPWM(15, 0, Ta7wila(70) ); // E1
   pwm.setPWM(8, 0, Ta7wila(70) );  // A1

   delay(100);
   
 pwm.setPWM(1, 0, Ta7wila(70) );  //C2
 pwm.setPWM(13, 0, Ta7wila(70) ); //E2
 pwm.setPWM(0, 0, Ta7wila(70) );  //A2

   
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 //////////////////////////////////////////////////////
 ////////////////////////////////////////////////////// 

 
 delay(300);
}









void setup() 
{
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);  
  pinMode(pinBouton , INPUT_PULLUP);
  //yield();

  
  Serial.println("Starting IR-receiver..."); 
  irrecv.enableIRIn();
   Serial.println("IR-receiver active");


}








void loop()
{
  
if (irrecv.decode(&results)) {
 
   // Serial.println(results.value, HEX);
 
     irrecv.resume();
 
    switch (results.value) {

      
         case 0xFF629D:  // button Forrward
            prev=results.value;
               
            break;

         case 0xFFA857:  // button Backword
            prev=results.value;     
                  
              break;
  

         case 0xFF02FD:  // button OK
           prev=results.value;
           
           break;
             
     }




     
/////////////////////////////////////////////////////////////////////////////////

     

   }
   switch (prev) {

      
         case 0xFF629D:  // button Forrward
            For();
       
                Serial.println("forward");
            break;

 
         case 0xFFA857:  // button Backword
              B();
                   Serial.println("backward");
              break;
  

         case 0xFF02FD:  // button OK
           S();
           
                Serial.println("stand");
           break;
             


     } 
 
        
 }