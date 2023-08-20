#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background()
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    yF = yB = y;

    // carrega imagens
    imgF = new Image("");
    imgB = new Image("");

    // cria sprites do plano de fundo
    sky     = new Sprite("Resources/spritesbg/bg_binario.png");    
    backgF1 = new Sprite(imgF);
    backgF2 = new Sprite(imgF);
    backgB1 = new Sprite(imgB);
    backgB2 = new Sprite(imgB);
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete imgF;
    delete imgB;    
    delete backgF1;
    delete backgF2;
    delete backgB1;
    delete backgB2;
    delete sky;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    // move sprites com velocidades diferentes
    yF += 200 * gameTime;
    yB += 200 * gameTime;
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    // desenha pano de fundo
    sky->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

    // desenha prédios mais distantes
    backgB1->Draw(x, yB, Layer::LOWER);
    backgB2->Draw(x + imgB->Width(), yB, Layer::LOWER);
    
    // traz pano de fundo de volta para dentro da tela
    if (yB + imgB->Width()/2.0f < 0)
        yB += imgB->Width();

    // desenha prédios mais próximos
    backgF1->Draw(x, yF, Layer::MIDDLE);
    backgF2->Draw(x + imgF->Width(), window->Height()/2.0f, Layer::MIDDLE);

    // traz pano de fundo de volta para dentro da tela
    if (yF + imgF->Width()/2.0f < 0)
        yF += imgF->Width();
}

// -------------------------------------------------------------------------------
