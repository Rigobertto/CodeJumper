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
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

    MoveTo(window->CenterX(), 24.0f, 0.0f);

    uint normal[4] = { 1,2,3,4 };
    uint invertido[4] = { 6, 7, 8, 9 };
    
    anim->Add(INVERTED, invertido, 4);
    anim->Add(NORMAL, normal, 4);

    BBox(new Rect(-16, -24, +16, +24));
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
        MoveTo(window->CenterX(), obj->Y() - 32);
    else
        MoveTo(window->CenterX(), obj->Y() + 32);
    
    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    anim->NextFrame();

    // ação da gravidade sobre o personagem
    if (gravity == NORMAL)
        Translate(0, 300 * gameTime);
    else
        Translate(0, -300 * gameTime);

    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        keyCtrl = false;
        gravity = !gravity;

        if (gravity == NORMAL) {
            Translate(0, 12);
            anim->Select(NORMAL);

        }
        else {
            Translate(0, -12);
            anim->Select(NORMAL);
        }
    }
    else if (window->KeyUp(VK_SPACE))
    {
        keyCtrl = true;
    }
    


}

// ---------------------------------------------------------------------------------