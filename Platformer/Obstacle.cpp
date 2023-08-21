#include "Obstacle.h"

// ---------------------------------------------------------------------------------

Obstacle::Obstacle()
{   
    tileset = new TileSet("Resources/spritesVirus/virus_1.png", 70, 70, 4, 4);
    anim = new Animation(tileset, 0.3f, true);

    MoveTo(1200.0f, 690.0f, 0.0f);

    //sprite = new Sprite(img);
    vel = 400;

    BBox(new Rect(-35, -35, +35, +35));
}

// ---------------------------------------------------------------------------------

Obstacle::~Obstacle()
{
    delete anim;
    delete tileset;
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Obstacle::Update()
{
    // objeto caminha no eixo x
    anim->NextFrame();
    Translate(-vel * gameTime, 0.0f);

    // passa objeto de um lado da tela para o outro
    if (int(x) + int(y) < 0)
       MoveTo(float(window->Width()-100.0f), y);
}

// ---------------------------------------------------------------------------------

void Obstacle::OnCollision(Object* obj)
{
    // game over
    
    
}