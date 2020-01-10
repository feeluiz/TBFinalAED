#ifndef AGENTE_H
#define AGENTE_H

#include "olcGE.h"
#include <iostream>
#include "const.h"


class Agente {
    public:
        //Posicao
        float x, y;
        // Velocidade e Area do objeto
        float veloc, area;
        //estado do objeto - ultima escolha  - limite de decisoes aleatorias por x Vezes
        int estado = 0, escolha = 0, limiteAleatorio = 3;

        olc::Sprite *SPRITE_ATUAL;

        bool podeMover(float newX, float newY);
        void mover(float newX, float newY);

        void decidir();
        void executar();

        int Distancia(Agente agente, int newX, int newY);
        int deslocarAleatorio();
};
#endif