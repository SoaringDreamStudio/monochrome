
#include "../libraries.h"
#include "../graphics.h"

class Enemy
{
public:
    Enemy(int x,
         int y,
         float* passed_CameraX,
         float* passed_CameraY,
         float* passed_MovingCameraX,
         float* passed_MovingCameraY,
         CSDL_Setup* passed_csdl_setup);
    ~Enemy();

    void Draw();

    CSprite* getSprite() {return texture;}

    bool Damage(int);

private:
    void Update();

    int HP;

    int timerDamaged;

    int X;
    int Y;
    int W;
    int H;
    int centerX;
    int centerY;

    CSprite* texture;

    float* CameraX;
    float* CameraY;
    float* MovingCameraX;
    float* MovingCameraY;
    CSDL_Setup* csdl_setup;
};
