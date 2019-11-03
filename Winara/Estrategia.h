#include"Sensores.h"
#include "Movimento.h"

class Estrategia
{

Sensores sensores;
Movimento movimento;


double ValorSonarFrontal;
double ValorSonarLateralEsq;
double ValorSonarLateralDir;


public:

void executa();
void seguirLinha();
void verde();
void sala3();
void desviarObstaculo();
void rampa();


 

};
