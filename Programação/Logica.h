#ifndef LOGICA_H
#define LOGICA_H

class Logica
{
  private:
  
float valorSensorMaisEsq;
float valorSensorMaisDir;
float valorSensorEsq;
float valorSensorDir;

float ValorSonarFrontal;
float ValorSonarDireito;
float ValorSonarEsquerdo;

float BBBB;
float PPPP;
float PPBB;
float BBPP;
float BPBB;
float BBPB;
float PBBB;
float BBBP;

float BrancoEsq;
float BrancoDir;
float BrancoMaisDir;
float BrancoMaisEsq;

float PretoEsq;
float PretoDir;
float PretoMaisDir;
float PretoMaisEsq;

  public:

 void ValorSonares();
 void ValorSensoresRef();
 void VariaveisSensores();
  
};
#endif
