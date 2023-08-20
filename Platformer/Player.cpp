/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 12 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/spritesplayer/p_running.png", 86, 214, 5,  10);
    anim = new Animation(tileset, 0.090f, true);

    MoveTo(100.0f, 600.0f, 0.0f);

    uint normal[5] = {0,1,2,3,4 };
    uint invertido[5] = {5, 6, 7, 8, 9 };
    
    //anim->Add(INVERTED, invertido, 4);
    //anim->Add(NORMAL, normal, 4);


    BBox(new Rect(-43, -85, +43, +85));
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tileset;
    delete anim;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // mantém personagem na posição correta em cima da plataforma
   if (gravity == NORMAL)
        MoveTo(100.0f, obj->Y() - 66);
   
    
    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    anim->NextFrame();
    //MoveTo(80.0f, obj->Y() - 50);
    // ação da gravidade sobre o personagem
    if (gravity == NORMAL)
        Translate(0, 200 * gameTime);
    else
        Translate(0, -200 * gameTime);

    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        keyCtrl = false;
       // gravity = !gravity;
        Translate(0, -600 * gameTime);

        if (gravity == NORMAL) {
            Translate(0, 12);
            anim->Select(NORMAL);

        }
       
    }
    else if (window->KeyUp(VK_SPACE))
    {
        keyCtrl = true;
    }

    if (keyCtrl && window->KeyDown(VK_UP)) {
        Translate(0, -1800 * gameTime);
    }
    


}

// ---------------------------------------------------------------------------------