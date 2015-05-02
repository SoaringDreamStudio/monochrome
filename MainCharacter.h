
#include "libraries.h"
#include "SDL_Setup.h"
#include "Sprite.h"

class MainCharacter
{
public:
    MainCharacter(int* mouseX, int* mouseY, float* passed_CameraX, float* passed_CameraY, CSDL_Setup* passed_csdl_setup);
    ~MainCharacter();

    void Draw();
private:
    void Update();

    int* mouseX;
    int* mouseY;

    int mainX;
    int mainY;
    int sizeX;
    int sizeY;
    int centerX;
    int centerY;

    CSprite* texture;
    double n;//градус
    double rad;
    int delX, delY;

    float* CameraX;
    float* CameraY;
    CSDL_Setup* csdl_setup;
};
