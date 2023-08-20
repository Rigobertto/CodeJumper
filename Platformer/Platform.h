

#ifndef _PLATFORMER_PLATFORM_H_
#define _PLATFORMER_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

enum PLATTYPES { SMALL, MEDIUM, LARGE };

// ---------------------------------------------------------------------------------

class Platform : public Object
{
private:
    Sprite * platform1 = nullptr;        // sprite da plataforma
    Sprite * platform2 = nullptr;


    float xF;                       // posição horizontal dos sprites
    Image * imgF1;                       // imagem de fundo frontal
    Image * imgF2;

                          // fundo estático
    Sprite * backgF1;                   // pano de fundo dinâmico (frontal 1)
    Sprite * backgF2;                 // pano de fundo dinâmico (frontal 2)


public:
    Platform(float posX, float posY);    
    ~Platform();

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------
// Função Membro Inline

/*inline void Platform::Draw()
{   
    platform1->Draw(x, y, z); 
    platform2->Draw(x, y, z);
}*/

// ---------------------------------------------------------------------------------

#endif