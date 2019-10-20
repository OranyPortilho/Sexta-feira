#ifndef MOVIMENTO_H
#define MOVIEMNTO_H


class Movimento
{
  public:

    void fren();
    void parar();
    void girarEsq90();
    void girarDir90();
    void dir();
    void esq();

    
    //Movimento rampa
    void Sfren();
    void Sdir();
    void Sesq();


    //Movimento Obstaculo
    void voltar();
    void girarObsE();
    void girarObsD();
    
};
#endif
