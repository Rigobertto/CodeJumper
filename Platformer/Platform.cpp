/**********************************************************************************
// Platform (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 12 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType)
{
    switch (platType) {
    case SMALL: platform = new Sprite("Resources/SmallGray.png");
    case MEDIUM: platform = new Sprite("Resources/MediumGray.png");
    case LARGE: platform = new Sprite("Resources/LongGray.png");
    }
    
    MoveTo(posX, posY);

    BBox(new Rect(-platform->Width()/2, -platform->Height()/2, platform->Width()/2, platform->Height()/2));
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
  
    Translate(-200.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------
