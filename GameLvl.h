
#include "libraries.h"
#include "SDL_Setup.h"
#include "Sprite.h"
#include "crate.h"
#include "MainCharacter.h"

class GameLvl
{
public:
    GameLvl(int* MouseX,
            int* MouseY,
            float* passed_CameraX,
            float* passed_CameraY,
            CSDL_Setup* passed_csdl_setup);
    ~GameLvl();

    void Draw();
private:
    void Update();
    void UpdateCollide();

    MainCharacter* MainHero;

    int* MouseX;
    int* MouseY;

    float* CameraX;
    float* CameraY;
    CSDL_Setup* csdl_setup;
    std::vector<Crate*> crates;
};
