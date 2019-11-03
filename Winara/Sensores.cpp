#include "robo_hardware2.h"
#include "Sensores.h"
#define dPB 51

void Sensores:: valores()
  {
	valorMaisEsq = robo.lerSensorLinhaMaisEsq();
	valorEsq = robo.lerSensorLinhaEsq();
	valorDir = robo.lerSensorLinhaDir();
	valorMaisDir = robo.lerSensorLinhaMaisDir();
  }

  bool Sensores:: BBBB()
  {

	valores();

	return (valorMaisEsq > dPB && valorEsq > dPB && valorDir > dPB&& valorMaisDir > dPB);

  }

  bool Sensores:: BBBP()
  {

	valores();

	return (valorMaisEsq > dPB && valorEsq > dPB && valorDir > dPB && valorMaisDir <= dPB);

  }

  bool Sensores:: BBPB()
  {

	valores();

	return (valorMaisEsq > dPB && valorEsq > dPB && valorDir <= dPB&& valorMaisDir > dPB);

  }

  bool Sensores:: BBPP()
  {

	valores();

	return (valorMaisEsq > dPB && valorEsq > dPB && valorDir <= dPB && valorMaisDir <= dPB);

  }

  bool Sensores:: BPBB()
  {

	valores();

	return (valorMaisEsq > dPB && valorEsq <= dPB && valorDir > dPB && valorMaisDir > dPB);

  }

  bool Sensores:: BPPB()
  {

	valores();

	return (valorMaisEsq > dPB && valorEsq <= dPB && valorDir <= dPB && valorMaisDir > dPB);

  }

  bool Sensores:: PBBB()
  {

	  valores();

	return (valorMaisEsq <= dPB && valorEsq > dPB&& valorDir > dPB && valorMaisDir > dPB);

  }

  bool Sensores:: PPPP()
  {

  valores();

  return(valorMaisEsq <= dPB && valorEsq <= dPB && valorDir <= dPB && valorMaisDir <= dPB);
  
  }

  bool Sensores:: PPPB()
  {

  valores();

  return(valorMaisEsq <= dPB && valorEsq <= dPB && valorDir <= dPB && valorMaisDir > dPB);
  
  }
   bool Sensores:: BPPP()
  {

  valores();

  return(valorMaisEsq > dPB && valorEsq <= dPB && valorDir <= dPB && valorMaisDir <= dPB);
  
  }
 
  
  
