#include "../Headers/Walls.h"
// * definicao padrao de um objeto Walls
Walls::Walls(){
        estado = STATE_DEFAULT;
        x = 10.0f;
        y = 10.0f;

        veloc = 4.0f;
        area = 26.0f;
        
        SP_CAINDO = new olc::Sprite("./Resources/Sprites01/CAINDO.png");
        SP_INDO = new olc::Sprite("./Resources/Sprites01/INDO.png");
        SP_SUBINDO = new olc::Sprite("./Resources/Sprites01/SUBINDO.png");
        SP_VOLTANDO = new olc::Sprite("./Resources/Sprites01/VOLTANDO.png");

        SPRITE_ATUAL = SP_CAINDO;
    }
// * Definicao com parametros de um objeto walls
Walls::Walls(float posX, float posY,float nSpeed ,float nArea, int nEstado ){
        estado = STATE_DEFAULT;
        x = posX;
        y = posY;

        veloc = nSpeed;
        area = nArea;

        estado = nEstado ;

        SP_CAINDO = new olc::Sprite("./Resources/Sprites01/CAINDO.png");
        SP_INDO = new olc::Sprite("./Resources/Sprites01/INDO.png");
        SP_SUBINDO = new olc::Sprite("./Resources/Sprites01/SUBINDO.png");
        SP_VOLTANDO = new olc::Sprite("./Resources/Sprites01/VOLTANDO.png");

        SPRITE_ATUAL = SP_SUBINDO;
    }
// * Objeto Walls Decide o proximo movimento 
void Walls::decidir(){
    if (estado == STATE_DEFAULT) estado = STATE_CAINDO;

    if(estado == STATE_CAINDO && !podeMover(x,y+veloc )) estado = STATE_INDO;
    else if(estado == STATE_INDO && !podeMover(x+veloc,y )) estado = STATE_SUBINDO;
    else if(estado == STATE_SUBINDO && !podeMover(x,y-veloc )) estado = STATE_VOLTANDO;
    else if(estado == STATE_VOLTANDO && !podeMover(x-veloc,y )) estado = STATE_CAINDO;

}
// * Objeto Wall Executa o movimento decidido
void Walls::executar(){
    if(estado== STATE_CAINDO){
        SPRITE_ATUAL = SP_CAINDO;
        mover(x, y+veloc);
    }else if(estado== STATE_INDO){
        SPRITE_ATUAL = SP_INDO;
        mover(x + veloc, y);
    }else if(estado== STATE_SUBINDO){
        SPRITE_ATUAL = SP_SUBINDO;
        mover(x, y - veloc);
    }else if(estado== STATE_VOLTANDO){
        SPRITE_ATUAL = SP_VOLTANDO;
        mover(x - veloc, y );
    }
}
