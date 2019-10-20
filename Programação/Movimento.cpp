#include"Movimento.h"
#include <robo_hardware2.h>


void Movimento:: fren()
{
  robo.acionarMotores(40,43);
}
void Movimento:: parar()
{
  robo.acionarMotores(0,0);
}
void Movimento:: girarEsq90()
{
  robo.acionarMotores(45,-40);
}
void Movimento:: girarDir90()
{
  robo.acionarMotores(-40,45);
}
void Movimento:: dir()
{
  robo.acionarMotores(-30,34);
}
void Movimento:: esq()
{
  robo.acionarMotores(34,-30);
}
void Movimento:: Sfren()
{
  robo.acionarMotores(60,63);
}
void Movimento:: Sdir()
{
  robo.acionarMotores(60,55);
}
void Movimento::Sesq() 
{
  robo.acionarMotores(55,60);
}

void Movimento::voltar() 
{
  robo.acionarMotores(-30,-30);
}
void Movimento::girarObsE() 
{
  robo.acionarMotores(30,-30);
}
void Movimento::girarObsD() 
{
  robo.acionarMotores(-30,30);
}
