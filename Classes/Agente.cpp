#include "../Headers/Agente.h"

using namespace std;
// * Retorna true se o movimento desejado for posivel
bool Agente::podeMover(float newX, float newY){
    if(newX  > (screenWidth - area) ||  newX  < 1.0f ||newY > (screenHeight - area) || newY < 1.0f  ) return false;
    return true;
}
// * Move para as coordenadas pedidas caso seja posivel
void Agente::mover(float newX, float newY){
    if(podeMover(newX,newY)){   
        x = newX;
        y = newY;
    }
}
// * Calcula a distancia de manhatan entre dois pontos
int Agente::Distancia(Agente agente, int newX, int newY){
    return abs((abs(newX - agente.x) + abs( newY - agente.y))/area);
}
// * Movimenta aleatoriamente
int Agente::deslocarAleatorio() 
{
    //Sem seed pois cada Agente deve ter um Seed aletorio diferente para ter uma dinamicidade maior
    int  posicoes[4] = {x + area, x - area, y + area, y - area};
    int newX = x, newY = y;
    
    if(escolha < 2 ){
        newY = y;
        newX = posicoes[escolha];
    }
    else if(escolha > 1 ){
        newX = x;
        newY = posicoes[escolha];
    }

    if(limiteAleatorio++ <= 3 && podeMover(newX, newY)){
            mover(newX, newY);
            return escolha;
    }else {
        do{
            newX = x;
            newY = y;  
            escolha = rand() % 4;
            if(escolha < 2 ){
                newY = y;
                newX = posicoes[escolha];
            }else if(escolha > 1 ){
                newX = x;
                newY = posicoes[escolha];
            }
        } while(!podeMover(newX, newY));
        limiteAleatorio = 0;
    }
    mover(newX, newY);
    return escolha;
}

