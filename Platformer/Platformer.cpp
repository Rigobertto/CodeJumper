#include "Engine.h"
#include "Platformer.h"
#include "Resources.h"
#include "Obstacle.h"

// -----------------------------------------------------------------------------

Scene * Platformer::scene = nullptr;
Image * virus = nullptr;
Obstacle* obj = nullptr;                // um obst�culo do jogo
list<Obstacle*> objects;                      // lista de obst�culos em movimento

// -----------------------------------------------------------------------------

void Platformer::Init()
{
    // cria cena do jogo
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background();
    scene->Add(backg, STATIC);

    player = new Player();
    scene->Add(player, MOVING);

    Platform * plat = new Platform(683, 707);
    scene->Add(plat, STATIC);

   // plat = new Platform(400, 200);
   // scene->Add(plat, STATIC);

    virus = new Image("Resources/spritesVirus/virus_1.png");

    obj = new Obstacle(virus, 650);
    obj->MoveTo(1000, 650);
    objects.push_back(obj);

    obj = new Obstacle(virus, 650);
    obj->MoveTo(2000, 650);
    objects.push_back(obj);
}

// ------------------------------------------------------------------------------

void Platformer::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena do jogo
    scene->Update();
    scene->CollisionDetection();

    // move objetos
    for (auto obj : objects)
        obj->Update();
} 

// ------------------------------------------------------------------------------

void Platformer::Draw()
{
   scene->Draw();
   scene->DrawBBox();

   // desenha obst�culos
   for (auto obj : objects)
       obj->Draw();
} 

// ------------------------------------------------------------------------------

void Platformer::Finalize()
{
    delete scene;
    // remove obst�culos
    for (auto obj : objects)
        delete obj;

    delete virus;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria engine
    Engine * engine = new Engine();

    // configura o motor do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(1366, 768);
    engine->window->Color(150, 200, 230);
    engine->window->Title("Code Jumper");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    engine->Start(new Platformer());

    // destr�i engine e jogo
    delete engine;
}

// ----------------------------------------------------------------------------

