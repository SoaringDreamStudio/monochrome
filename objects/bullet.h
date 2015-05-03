
#include "../libraries.h"
#include "../graphics.h"

class Bullet
{
public:
    Bullet(int x,
           int y,
           float direction,
           float* passed_CameraX,
           float* passed_CameraY,
           float* passed_MovingCameraX,
           float* passed_MovingCameraY,
           CSDL_Setup* passed_csdl_setup);
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
    float* MovingCameraX;
    float* MovingCameraY;
    CSDL_Setup* csdl_setup;
};
