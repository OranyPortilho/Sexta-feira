#include<robo_hardware2.h>
#include "Movimento.h"
#include"Estrategia.h"
#include "Logica.h"

#define DIVISOR_BRANCO_PRETO 51


Movimento movimento;
Logica logica;


float BBBB;
float PPPP;
float PPBB;
float BBPP;
float BPBB;
float BBPB;
float PBBB;
float BBBP;
float PPPB;
float BPPP;
float BPPB;
float PBBP;
float BPBP;
float PBPB;
float PPBP;

float brancoEsq;
float brancoDir;
float brancoMaisDir;
float brancoMaisEsq;

float pretoEsq;
float pretoDir;
float pretoMaisDir;
float pretoMaisEsq;

float valorSensorMaisEsq;
float valorSensorMaisDir;
float valorSensorEsq;
float valorSensorDir;

float ValorSonarFrontal;
float ValorSonarDireito;
float ValorSonarEsquerdo;

bool RAMPA;
bool OBSTACULO;

void Estrategia:: SeguirLinha()
{
  logica.ValorSensoresRef();
  
  brancoMaisEsq = (valorSensorMaisEsq > DIVISOR_BRANCO_PRETO);    
  brancoEsq =  (valorSensorEsq > DIVISOR_BRANCO_PRETO);        
  brancoDir =  (valorSensorDir > DIVISOR_BRANCO_PRETO);
  brancoMaisDir = (valorSensorMaisDir > DIVISOR_BRANCO_PRETO);

  pretoMaisEsq = (valorSensorMaisEsq < DIVISOR_BRANCO_PRETO);
  pretoEsq =  (valorSensorEsq < DIVISOR_BRANCO_PRETO);
  pretoDir =  (valorSensorDir < DIVISOR_BRANCO_PRETO);
  pretoMaisDir = (valorSensorMaisDir < DIVISOR_BRANCO_PRETO);
  

  BBBB = (brancoMaisEsq && brancoEsq && brancoDir && brancoMaisDir);
  BPBB=(brancoMaisEsq && pretoEsq && brancoDir && brancoMaisDir);
  BBPB=(brancoMaisEsq && brancoEsq && pretoDir && brancoMaisDir);
  BBPP=(brancoMaisEsq && brancoEsq && pretoDir && pretoMaisDir);
  PPBB=(pretoMaisEsq && pretoEsq && brancoDir && brancoMaisDir );
  PPPB=(pretoMaisEsq &&  pretoEsq && pretoDir && brancoMaisDir);
  BPPP=(brancoMaisEsq && pretoEsq && pretoDir && pretoMaisDir);
  BBBP=(brancoMaisEsq && brancoEsq && brancoDir && pretoMaisEsq);
  PBBB=(pretoMaisEsq && brancoEsq && brancoDir && brancoMaisDir);
  BPPB=(brancoMaisEsq && pretoEsq && pretoDir && brancoMaisDir);
  PBBP=(pretoMaisEsq && brancoEsq && brancoDir && pretoMaisDir);
  BPBP=(brancoMaisEsq && pretoEsq && brancoDir && pretoMaisDir);
  PBPB=(pretoMaisEsq && brancoEsq && pretoDir && brancoMaisDir );
  PPBP=(pretoMaisEsq && pretoEsq  &&  brancoDir &&  pretoMaisDir );
  PPPP=(pretoMaisEsq && pretoEsq  &&  pretoDir &&  pretoMaisDir );

  if(BBBB)
  {
    movimento.fren();
  }
  else if(PPPP)
  {
    movimento.fren();
  }
  else if(BBPP)
  {
    movimento.girarEsq90();
  }
  else if(PPBB)
  {
      movimento.girarDir90();
  }
  else if(BPBB)
  {
    movimento.dir();
  }
  else if(BBPB)
  {
    movimento.esq();
  }
  else(BBBB);
  
}

void Estrategia :: Rampa()
{
logica.ValorSonares();

RAMPA=(ValorSonarDireito > 10 && ValorSonarEsquerdo>10);

while(RAMPA)
{
 if(BBBB)
 {
   movimento.Sfren();
 }
 else if(BPBB)
 {
  movimento.Sdir();
 }
 else if(BBPB)
 {
  movimento.Sesq();
 }
 else(BBBB);
}

  
}

void Estrategia :: DesviarObstaculo()
{
  logica.ValorSonares();
  OBSTACULO=(ValorSonarDireito>20);
  
  if(OBSTACULO)
  {
    movimento.parar();
    delay(200);
    movimento.voltar();
    delay(300);
    movimento.girarObsE();
    delay(100);
    movimento.fren();
    delay(500);
    movimento.girarObsD();
    delay(100);
    movimento.fren();
    delay(400);
    movimento.girarObsD();
    delay(100);
    movimento.fren();
    delay(500);
    movimento.girarObsE();
    delay(100);
    movimento.parar();
    delay(100);
    movimento.voltar();
    delay(200);
    SeguirLinha();
    
  }
  else
  {
    SeguirLinha();
  }
  
}

void Estrategia :: Executar()
{
  if(ValorSonarDireito > 10 && ValorSonarEsquerdo>10)
  {
    Rampa();
  }
  else{
   SeguirLinha();
  }
}
