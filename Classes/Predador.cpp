#include "../Headers/Predador.h"

Predador::Predador(){
        estado = STATE_DEFAULT;

        x = 1.0f;
        y = 1.0f;

        area = 30.0f;
        veloc = 30.0f;

        SP_AB = new olc::Sprite("./Resources/Sprites02/AB.png");
        SP_AS = new olc::Sprite("./Resources/Sprites02/AS.png");
        SP_AD = new olc::Sprite("./Resources/Sprites02/AD.png");
        SP_AV = new olc::Sprite("./Resources/Sprites02/AV.png");
        SP_FC = new olc::Sprite("./Resources/Sprites02/FC.png");

        SPRITE_ATUAL = SP_FC;
}
Predador::Predador(float posX, float posY,float nspeed ,float narea, float nstate ){
        x = posX;
        y = posY;

        veloc = nspeed;
        area = narea;

        estado =  nstate ;

        SP_AB = new olc::Sprite("./Resources/Sprites02/AB.png");
        SP_AS = new olc::Sprite("./Resources/Sprites02/AS.png");
        SP_AD = new olc::Sprite("./Resources/Sprites02/AD.png");
        SP_AV = new olc::Sprite("./Resources/Sprites02/AV.png");
        SP_FC = new olc::Sprite("./Resources/Sprites02/FC.png");

        SPRITE_ATUAL = SP_FC;
    }

void Predador::decidir(Agente P2) {
        int distancia = Distancia(P2,x, y);
        //cout<< distancia << endl;
        //Visao do PREDADOR distancia de 3 quadros persegue
        if( distancia <= VISAO_PREDADOR)
            estado = STATE_CACA;
        else
            estado = STATE_ALEATORIO; // caso contrario Anda aletoriamente
}
//inicia a perseguicao  Impacavel
void Predador::perseguir(Agente P2) {
    estado = STATE_CACA;
    int newX = x ; 
    int newY = y ;          
    //calcular a distancia total
    int dist = Distancia(P2,newX, newY);
    //verifica qual das rotas irá diminuir a discancia e nao ira sair do mundo
    if(dist > Distancia(P2,newX+veloc,newY) && podeMover(newX+veloc,newY))
    {
        mover(newX+veloc,newY);
        SPRITE_ATUAL = SPRITE_ATUAL == SP_FC ? SP_AD : SP_AB;
    }
    else if(dist > Distancia(P2,newX,newY-veloc) && podeMover(newX,newY-veloc)) 
    {
        mover(newX,newY-veloc);
        SPRITE_ATUAL = SPRITE_ATUAL == SP_FC ? SP_AD : SP_AS;
    }
    else if(dist > Distancia(P2,newX-veloc,newY) && podeMover(newX-veloc,newY)) 
    {
        SPRITE_ATUAL = SPRITE_ATUAL == SP_FC ? SP_AD : SP_AV;
        mover(newX-veloc,newY);
    }
    else if(dist > Distancia(P2,newX,newY+veloc) && podeMover(newX,newY+veloc)) 
    {
        SPRITE_ATUAL = SPRITE_ATUAL == SP_FC ? SP_AD : SP_AD;
        mover(newX,newY+veloc);
    }   

}
int Predador::deslocarAleatorio(){
    estado = Agente::deslocarAleatorio();
    if(SPRITE_ATUAL == SP_FC)
    {
        if(estado == 2) 
            SPRITE_ATUAL = SP_AD;
        else if(estado == 0) 
            SPRITE_ATUAL = SP_AB;
        else if(estado == 1) 
            SPRITE_ATUAL = SP_AV;
        else if(estado == 3) 
            SPRITE_ATUAL = SP_AS;
    }
    else 
    {SPRITE_ATUAL = SP_FC;}
    return 0;
}
//Executa as decisoes
void  Predador::executar(Agente P2) {     
        if (estado == STATE_CACA) perseguir(P2); 
        else deslocarAleatorio();
}