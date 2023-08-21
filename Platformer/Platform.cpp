#include "Platform.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY)
{
    /*switch (platType) {
    case SMALL: platform = new Sprite("Resources/SmallGray.png");
    case MEDIUM: platform = new Sprite("Resources/MediumGray.png");
    case LARGE: platform = new Sprite("Resources/LongGray.png");
    }*/
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xF = x;

    imgF1 = new Image("Resources/spritesfloor/floor_1.png");
    imgF2 = new Image("Resources/spritesfloor/floor_2.png");

    backgF1 = new Sprite(imgF1);
    backgF2 = new Sprite(imgF1);

    MoveTo(posX, posY);

    BBox(new Rect(-backgF1->Width()/2, 20, backgF1->Width()/2, backgF1->Height()/2));
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform1;
    delete platform2;
    delete backgF1;
    delete backgF2;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
    xF -= 300 * gameTime;
    //Translate(-200.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------

void Platform::Draw() {
    
    // desenha prédios mais próximos
    backgF1->Draw(xF, y, Layer::MIDDLE);
    backgF2->Draw(xF + imgF1->Width(), 707, Layer::MIDDLE);

    // traz pano de fundo de volta para dentro da tela
    if (xF + imgF1->Width() / 2 < 0) {
        xF += imgF1->Width();
        //img
    }
    
      
    
}
