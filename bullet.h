
#include "libraries.h"
#include "SDL_Setup.h"
#include "Sprite.h"

class Bullet
{
public:
    Bullet(int x, int y, float direction, float* passed_CameraX, float* passed_CameraY, CSDL_Setup* passed_csdl_setup);
    ~Bullet();

    void Draw();

    CSprite* getSprite() {return texture;}
    bool Destroy() {return plsDestroyMe;}
    void setDestroy() {plsDestroyMe = true;}

private:
    void Update();

    int X;
    int Y;
    int W;
    int H;
    int centerX;
    int centerY;

    int lifeTime;
    int speed;

    float direction;

    CSprite* texture;
    int timer;
    bool plsDestroyMe;

    float* CameraX;
    float* CameraY;
    CSDL_Setup* csdl_setup;
};
