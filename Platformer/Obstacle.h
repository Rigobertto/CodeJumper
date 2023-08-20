#ifndef _PLATFORMER_OBSTACLE_H_
#define _PLATFORMER_OBSTACLE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"            // tipos espec�ficos da engine
#include "Object.h"           // interface de object
#include "Sprite.h"           // interface de sprites
#include "Image.h"            // interface de image

// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
    Sprite* sprite;
    float vel;

public:
    Obstacle(Image* img, float speed);
    ~Obstacle();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline

inline void Obstacle::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
