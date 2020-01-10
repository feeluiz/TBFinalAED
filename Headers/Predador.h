#ifndef PREDADOR_H
#define PREDADOR_H

#include "olcGE.h"
#include "Agente.h"

class Predador : public Agente {
    private:
        olc::Sprite *SP_AB;
        olc::Sprite *SP_AS;
        olc::Sprite *SP_AD;
        olc::Sprite *SP_AV;
        olc::Sprite *SP_FC;
    public:
        Predador();
        Predador(float posX, float posY,float nspeed ,float narea, float nstate );
        void decidir(Agente P2);
        void  executar(Agente P2);
        void perseguir(Agente P2);        
        int deslocarAleatorio();
};

#endif // * PREDADOR_H