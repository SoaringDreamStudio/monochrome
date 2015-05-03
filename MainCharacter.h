
#include "libraries.h"
#include "SDL_Setup.h"
#include "Sprite.h"

class MainCharacter
{
public:
    MainCharacter(int* mouseX, int* mouseY, float* passed_CameraX, float* passed_CameraY, CSDL_Setup* passed_csdl_setup);
    ~MainCharacter();

    void Draw();
    CSprite* getSprite() {return texture;}
    int getDirection();
    int getSpeed() {return speed;}
private:
    void Update();
    void UpdateControls();

    int* mouseX;
    int* mouseY;

    bool MoveLeft;
    bool MoveDown;
    bool MoveRight;
    bool MoveUp;

    int speed;

    int mainX;
    int mainY;
    int sizeX;
    int sizeY;
    int centerX;
    int centerY;

    CSprite* texture;
    double n;//������
    double rad;
    int delX, delY;

    float* CameraX;
    float* CameraY;
    CSDL_Setup* csdl_setup;

    int timeCheckMoving;
};