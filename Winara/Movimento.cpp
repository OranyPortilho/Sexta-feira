#include "robo_hardware2.h"
#include "Movimento.h"

 void Movimento :: fren()
 {
  robo.acionarMotores(60,60);
 }


             //Garra
 void Movimento :: aberta()
 {
     robo.acionarServoGarra1(180); //BRAÇO
     robo.acionarServoGarra2(180); //GARRA
 }

 void Movimento :: fechada()
 {
    robo.acionarServoGarra1(40); //BRAÇO
    robo.acionarServoGarra2(30); //GARRA
 }

 
             //RAMPA
 void Movimento:: GarraRampa()
 {
  robo.acionarServoGarra1(140); //BRAÇO
   robo.acionarServoGarra2(75); //GARRA
 }
 
void Movimento :: FastFren()
{
  robo.acionarMotores(70,75);
}
void Movimento :: ESQ()
{
  robo.acionarMotores(66,50);
}
void Movimento :: DIR()
{
  robo.acionarMotores(56,60);
}
void Movimento :: girarDir()
{
   robo.acionarMotores(-60, 65);
    delay(550);
}
void Movimento :: stopp()
{
   robo.acionarMotores(0, 0);
  
}



 

 
