#include "../Headers/Presa.h"
using namespace std;

Presa::Presa(){
    estado = STATE_DEFAULT;

    x = screenWidth - area;
    y = 1.0f;

    area = 30.0f;
    veloc = 30.0f;

    DIR = new olc::Sprite("./Resources/Sprites02/DIR.png");
    BAI = new olc::Sprite("./Resources/Sprites02/BAI.png");
    FUG = new olc::Sprite("./Resources/Sprites02/FUG.png");
    MOR = new olc::Sprite("./Resources/Sprites02/MOR.png");

    SPRITE_ATUAL = DIR;
}
Presa::Presa(float posX, float posY,float nVeloc ,float nArea, float nEstado ){
    estado =  nEstado ;

    x = posX;
    y = posY;

    area = nArea;
    veloc = nVeloc;

    DIR = new olc::Sprite("./Resources/Sprites02/DIR.png");
    BAI = new olc::Sprite("./Resources/Sprites02/BAI.png");
    FUG = new olc::Sprite("./Resources/Sprites02/FUG.png");
    MOR = new olc::Sprite("./Resources/Sprites02/MOR.png");

    SPRITE_ATUAL = DIR;
}
void Presa::decidir(Agente P1) {
    int distancia = Distancia(P1,x, y);

    if(distancia <= 1 ) cont++;
    //Visao do PRESA de ate 2 quadros
    if( distancia <= VISAO_PRESA && cont < 3)
        estado = STATE_FUGA;
    else if(cont >= 3){
        estado = STATE_MORTO;
        SPRITE_ATUAL = MOR;
    }else
        estado = STATE_ALEATORIO;// caso nao esteja perto anda aletoriamente
}
void Presa::fugir(Agente P1) {
    SPRITE_ATUAL = FUG;

    int newX = x ; 
    int newY = y ;

    //calcular a distancia total
    int dist = Distancia(P1,newX, newY);
    
    //verifica qual das rotas irá aumentar a discancia
    //e nao ira sair do mundo
    int  posicoes[4] = {x + area, x - area, y + area, y - area};
    int novasDistancias[4] = {
        Distancia(P1,newX+area,newY), 
        Distancia(P1,newX-area,newY), 
        Distancia(P1,newX,newY + area),
        Distancia(P1,newX,newY-area)
    };
    int maiorDistancia = 0;
    int index = 0;
    for (int i = 0; i < 4; i++){
        if(i < 2 ){
            newY = y;
            newX = posicoes[i];
        }
        else if(i > 1 ){
            newX = x;
            newY = posicoes[i];
        }
        if(dist < novasDistancias[i] && maiorDistancia < novasDistancias[i] && podeMover(newX, newY)){     
            maiorDistancia = novasDistancias[i];
            index = i;
        }
    }
    if(index < 2){
        newY = y;
        newX = posicoes[index];
    }
    else if(index > 1 ){
        newX = x;
        newY = posicoes[index];
    }
    mover(newX, newY);
        std::cout<<"novo X: " << newX << " novo Y: "<< newY <<endl;
}

int Presa::deslocarAleatorio () {
    //para o PRESA ter um seed aleatorio diferente do PREDADOR e moverem diferente
    srand(time(NULL));

    int r = Agente::deslocarAleatorio();
    if(r == 0) SPRITE_ATUAL = DIR;
    if(r == 3) SPRITE_ATUAL = BAI;
}
//Executar as decisoes
void Presa::executar(Agente P1) {
    //se estado for Aletorio Desloca aletoriametne
    if (estado == STATE_ALEATORIO) 
        deslocarAleatorio();
    else if (estado == STATE_FUGA)
        fugir(P1);  // caso estado for FUGIR foge
    else {
        SPRITE_ATUAL = MOR;
    }
}  