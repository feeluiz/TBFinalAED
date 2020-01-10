#ifndef PRESA_H
#define PRESA_H

#include "olcGE.h"
#include "Agente.h"

class Presa : public Agente {
    private:
        olc::Sprite *DIR;
        olc::Sprite *BAI;
        olc::Sprite *FUG;
        olc::Sprite *MOR;
        int cont = 0;
    public:
        Presa();
        Presa(float posX, float posY,float nspeed ,float narea, float nstate );
        void decidir(Agente P1) ;
        void executar(Agente P1);   
        void fugir(Agente P1);
        int deslocarAleatorio ();
};
#endif // !PRESA_H