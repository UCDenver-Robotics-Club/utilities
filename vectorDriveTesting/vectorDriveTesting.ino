//#include <vmove.h>
//#include <vectordrive.h>
//#include <stdint.h>
#include <PRIZM.h>
#define VERSION 1

PRIZM prizm;



// SUPER IMPORTANT: make sure that the robot is lined up on the X Y axis when 
// it starts 

void setup() 
{
  // init prizm and reset encoders 
  prizm.PrizmBegin();
  prizm.resetEncoders();
  prizm.setMotorInvert(2,1); // invert the motor control on the second motor

  
  Serial.begin(9600);

  //driveTo(prizm,mtest);

  
  //Serial.println(angle);
}

void loop() 
{
  // put your main code here, to run repeatedly:
//  Serial.print("encoder 1:");
//  Serial.println(prizm.readEncoderCount(1));
//  Serial.print("encoder 2:");
//  Serial.println(prizm.readEncoderCount(2));
}

void serialEvent()
{
//  if(Serial.readBytes() > 0) // if there's data in the serial bus
//  {
//    
//  }
  
//   get values 1 value at a time  
//
   char buff = Serial.read();

   if(buff == 'w')
   {
      prizm.setMotorSpeeds(80,80);
   }
   if(buff == 's')
   {
      prizm.setMotorSpeeds(-80,-80);
      //prizm.setMotorSpeeds(0,0); // stop both motors 
   }
   if(buff == 'a')
   {  
      prizm.setMotorSpeeds(80,-80);
      prizm.resetEncoders();
   }
   if(buff == 'd')
   {
      prizm.setMotorSpeeds(-80,80);
      prizm.resetEncoders();
   }
   if(buff == 'x')
   {
      prizm.setMotorSpeeds(0,0);
   }
   if(buff == 'r')
   {
      prizm.resetEncoders();
   }
   if(buff == 'v')
   {
      Serial.print(VERSION);
   }
   // send back the status of the encoders 
   if(buff == 'i')
   {
      Serial.println("encoder data");
      Serial.print("encoder 1:");
      Serial.println(prizm.readEncoderCount(1));
      Serial.print("encoder 2:");
      Serial.println(prizm.readEncoderCount(2));
   }
}


