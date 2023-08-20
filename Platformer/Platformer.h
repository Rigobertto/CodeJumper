
#ifndef _PLATFORMER_H_
#define _PLATFORMER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "Platform.h"
#include "Background.h"
#include "Player.h"

// ------------------------------------------------------------------------------

class Platformer : public Game
{
private:
    Player * player = nullptr;      // jogador
    Background * backg = nullptr;   // pano de fundo
    bool img = false;

public:
    static Scene * scene;           // gerenciador de cena

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif