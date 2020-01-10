#ifndef WALLS_H
#define WALLS_H

#include "olcGE.h"
#include "Agente.h"

class Walls : public Agente {
    private:
        olc::Sprite *SP_INDO;
        olc::Sprite *SP_CAINDO;
        olc::Sprite *SP_VOLTANDO;
        olc::Sprite *SP_SUBINDO;
    public:
        Walls();
        Walls(float posX, float posY,float nspeed ,float narea, int nstate );
        void decidir();
        void executar();
};
#endif