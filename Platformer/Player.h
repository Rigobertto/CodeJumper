
#ifndef _PLATFORMER_PLAYER_H_
#define _PLATFORMER_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

enum Gravity {NORMAL,INVERTED};         // tipo da gravidade
enum Forma { JUMP, MOVE };
// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet * tileset = nullptr;        // folha de sprites do personagem
    TileSet* tilesetJump = nullptr;
    Animation * anim = nullptr;         // animação do personagem
    Animation * animJump = nullptr;
    Animation * animMove = nullptr;
    uint gravity = NORMAL;              // gravidade atuando sobre o jogador
    bool keyCtrl = false;               // controle do pressionamento da barra de espaço
    uint forma = MOVE;

public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void OnCollision(Object * obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Player::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif