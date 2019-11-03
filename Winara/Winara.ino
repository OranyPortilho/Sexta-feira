#include "Estrategia.h"
#include "robo_hardware2.h"
#include "Servo.h"


Estrategia estrategia;


float branco;
float preto;
float dBP;
float mme;
float mmd;
float me;
float md;

void setup() 
{
  robo.configurar(true);
  
    Serial.begin(9600);
    robo.acionarServoGarra1(160); 
    robo.acionarServoGarra2(20); 
  
 
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

   dBP = (branco + preto) / 2;  
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
  estrategia.executa();
}
