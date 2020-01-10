#ifndef  OLC_PGE_APPLICATION
    #define OLC_PGE_APPLICATION
    #include "./Headers/olcGE.h"
    #include "./Headers/Walls.h"
    #include "./Headers/Presa.h"
    #include "./Headers/Predador.h"

    //Bibliotecas
        #include <iostream>
        #include <string>
        #include <algorithm>
        #include <cstdlib>
    //Constantes
        #include "./Headers/const.h"


    using namespace std;

    class Game : public olc::PixelGameEngine{
        public:
            Game(string Name) {
                sAppName = Name;
            }
        private:
            Walls Peter;
            Predador P1;
            Presa P2;
            int game = 0;
            bool GameOver = false;
            bool pause = false;
            int Contador = 0;
        public:
            bool OnUserCreate(){
                P2.y = 510.0f;
                return true;
            }
            bool OnUserUpdate(float fElapsedTime){
                if (GetKey(olc::Key::P).bReleased){
                    pause = pause ? False: True;
                    Contador = 0;
                } 
                if(game == 0)
                {
                    FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(246, 222, 179));
                    DrawString((float)(60),(float)(screenHeight/10 * 3) ,"Aperte Z para Walls",olc::DARK_CYAN,2.0f);
                    DrawString((float)(60),(float)(screenHeight/10 * 4) ,"Aperte X para Presa Predador",olc::DARK_CYAN,2.0f);
                    DrawString((float)(60),(float)(screenHeight/10 * 5) ,"Aperte R para Voltar ao Menu",olc::DARK_CYAN,2.0f);
                }
                if (GetKey(olc::Key::R).bReleased){

                    P1 = Predador();
                    P2 = Presa();

                    P2.y = screenHeight - P2.area;

                    game = 0;
                }

                if (GetKey(olc::Key::Z).bReleased) game = 1;
                if (GetKey(olc::Key::X).bReleased) game = 2;

                if(game == 1) startWalls();
                if(game == 2) startPP();

                return true;
            }
            void startWalls(){
                //Limpa o Pixel Alpha Anterior
                Clear(olc::DARK_CYAN);
                
                //habilita o modo Alpha para tirar o fundo das imagens
                SetPixelMode(olc::Pixel::ALPHA);

                //Peter Decide Caminho
                Peter.decidir();
                
                // Peter Movimenta
                Peter.executar();
                
                // Clear Screen
                FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(255, 255, 255));

                // Draw Sprite
                DrawSprite(Peter.x, Peter.y, Peter.SPRITE_ATUAL, 1.0f); 

                //Define o Modo de Pixel para normal
                SetPixelMode(olc::Pixel::NORMAL);
            }
            void DrawPacMan(){
                olc::Pixel p = P1.SPRITE_ATUAL->GetPixel(P1.x,P1.y);

                for (int x = 0; x < P1.SPRITE_ATUAL->width; x++)
                {
                    for (int y = 0; y < P1.SPRITE_ATUAL->height; y++)
                    {
                        olc::Pixel p = P1.SPRITE_ATUAL->GetPixel(x, y);
                        if(P1.estado == STATE_CACA) {
                            p.r = 255;
                            p.g = 0;
                            p.b = 0;
                        }
                        Draw((int32_t)P1.x +x-1,(int32_t) P1.y+y-1, p);
                    }
                }
            }
            void DrawMap(){
                std:string  dist = std::to_string(P1.Distancia(P2,P1.x,P1.y)) + " Quadros";
                if(P1.Distancia(P2,P1.x,P1.y)<= 3){
                    pause = True;
                    Contador = 0;
                
                }
                DrawString((float)screenWidth - 100.0f,5.0f,dist,olc::VERY_DARK_RED);
                if(P2.estado == STATE_MORTO) 
                    DrawString((float)(90),(float)(screenHeight/2) ,"GAME OVER",olc::DARK_RED,5.0f);
                for (int i = 0; i < 18; i++)
                {
                    DrawLine(0.0f,(i+1)*30.0f,(float)screenWidth,(i+1)*30.0f,olc::BLACK);
                    DrawLine((i+1)*30.0f,0.0f,(i+1)*30.0f,(float)screenWidth,olc::BLACK);
                }
            }
            void startPP(){
                this->sAppName = "Presa x Predador";
                if((Contador == 0 || Contador++ == 350) && pause == 0){
                    Contador = 1;
                    Clear(olc::DARK_CYAN);
                    
                    SetPixelMode(olc::Pixel::ALPHA);

                    P1.decidir(P2);
                    P2.decidir(P1);

                    P1.executar(P2);
                    P2.executar(P1);

                    // Clear Screen
                    FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(246, 222, 179));
                    //FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(255, 255, 255));
                    DrawMap();
                    DrawPacMan();

                    //Desenha a Presa
                    DrawSprite(P2.x, P2.y, P2.SPRITE_ATUAL, 1.0f); 

                    SetPixelMode(olc::Pixel::NORMAL);
                }

            } 
    };

    int main(){
        Game PxP("TP");
        if(PxP.Construct(screenWidth, screenHeight, M, N)) 
            PxP.Start();
        return 0;
    }
#endif // * OLC_PGE_APPLICATION