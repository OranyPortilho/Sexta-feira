#include<robo_hardware2.h>

#include"Logica.h"
#define DIVISOR_BRANCO_PRETO 51


void Logica :: ValorSensoresRef()
{
  valorSensorMaisEsq= robo.lerSensorLinhaMaisEsq();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
  valorSensorEsq = robo.lerSensorLinhaEsq();
  valorSensorDir = robo.lerSensorLinhaDir();
}

void Logica :: ValorSonares()
{
  ValorSonarFrontal= robo.lerSensorSonarFrontal();
  ValorSonarDireito= robo.lerSensorSonarEsq();
  ValorSonarEsquerdo= robo.lerSensorSonarDir();
}

void Logica:: VariaveisSensores()
{

}
