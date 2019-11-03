#include "Estrategia.h"
#include "robo_hardware2.h"

void Estrategia::executa() 
{
  ValorSonarFrontal = robo.lerSensorSonarFrontal();
  ValorSonarLateralEsq= robo.lerSensorSonarEsq();
  ValorSonarLateralDir = robo.lerSensorSonarDir();
  
  if(  ValorSonarLateralDir <= 20 && ValorSonarLateralEsq > 50)
  {
    sala3();
  }
  else if (ValorSonarLateralEsq < 20 && ValorSonarLateralDir < 20)
  {
    rampa();
  }
  else(seguirLinha());
  
}


void Estrategia::seguirLinha() 
{

  if (sensores.BBBB()) 
  {
    robo.acionarMotores(50, 50);
  } 
  else if (sensores.BPBB()) 
  {
    robo.acionarMotores(-60, 55);
  } 
  else if (sensores.BBPB()) 
  {
    robo.acionarMotores(45,-50);
  } 
  else if (sensores.BBBP()) 
  {
    robo.acionarMotores(55, -60);
  } 
  else if (sensores.PBBB()) 
  {
    robo.acionarMotores(-60, 55);
  } 
  else if (sensores.PPPP()) {
    robo.acionarMotores(60, 60);
  }
  else if(sensores.PPPB())
  {
    robo.acionarMotores(55, -60);
  }
}
void Estrategia::verde() {}
void Estrategia::sala3() 
{
   robo.ligarTodosLeds();
   
  //Primeira tentativa
   movimento.aberta();
    delay(1000);
    
    movimento.fren();
    delay(500);

    movimento.stopp();
    delay(200);
    
   movimento.fechada();
    delay(1500); 

   movimento.girarDir();

   //Segunda tentativa
   movimento.aberta();
    delay(1000);
    
   movimento.fechada();
    delay(1500); 

   movimento.girarDir(); 

   //Terceira tentativa 
   
   movimento.aberta();
    delay(1000);
    
   movimento.fechada();
    delay(1500); 

   movimento.girarDir(); 

//Final
   robo.acionarMotores(-60,-60);
   delay(600);
   
   movimento.stopp();
     
  robo.desligarTodosLeds();  
}

void Estrategia::desviarObstaculo() {}
void Estrategia :: rampa()
{
   movimento.GarraRampa();
   
   robo.ligarTodosLeds();
   
   ValorSonarLateralDir = robo.lerSensorSonarDir();
   ValorSonarLateralEsq = robo.lerSensorSonarEsq();

   delay(500);
   
   while(ValorSonarLateralEsq < 20 && ValorSonarLateralDir < 20 )
 {
     if (sensores.BBBB()) 
 {      
       movimento.FastFren();
 }
     else if (sensores.BPBB()) 
 {
       movimento.ESQ();
 }
     else if (sensores.BBPB()) 
 {
       movimento.DIR();
 }  
 }
     sala3();
}
