#ifndef _PLATFORMER_OBSTACLE_H_
#define _PLATFORMER_OBSTACLE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"         // interface de object
#include "Sprite.h"           // interface de sprites
#include "Image.h"                     // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h" 
// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
    TileSet * tileset = nullptr;        // folha de sprites do personagem
    Animation * anim = nullptr;
    Sprite * sprite;
    float vel;
    //bool isObstacle = true;

public:
    Obstacle();
    ~Obstacle();

    void OnCollision(Object * obj);
    void Update();
    void Draw();
    //bool isObstacle();
};

// ---------------------------------------------------------------------------------
// Funções Membro Inline

inline void Obstacle::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
