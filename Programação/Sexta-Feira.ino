#include <robo_hardware2.h>

#include "Estrategia.h"
#include"Logica.h"

Estrategia estrategia;


float mme;
float me;
float md;
float mmd;

float preto ;
float branco ; 
float divisorBrancoPreto;


void setup()
{
 Serial.begin(9600);
  robo.configurar(false);
 
  while (!robo.botao1Pressionado())
{
  mme = robo.lerSensorLinhaMaisEsq();
  me = robo.lerSensorLinhaEsq();
  md = robo.lerSensorLinhaDir();
  mmd = robo.lerSensorLinhaMaisDir();
  
   if (robo.botao2Pressionado())
{
    robo.ligarLed(1);
    branco = (mme + me + md + mmd) /4;
}
   else if (robo.botao3Pressionado())
{
    robo.ligarLed(2);
    preto = (mme + me + md + mmd) / 4;
    robo.acionarMotores(0,0);
    delay(1000);

    divisorBrancoPreto = (branco + preto) / 2;
}
   robo.acionarMotores(0,0);
}   
   robo.ligarLed(3);
   robo.acionarMotores(0,0);
   delay(3000);
   robo.desligarTodosLeds();

}

void loop()
{ 
  estrategia.Executar();
}
