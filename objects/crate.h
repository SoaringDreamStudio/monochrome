
#include "../libraries.h"
#include "../graphics.h"

class Crate
{
public:
    Crate(float* passed_CameraX,
          float* passed_CameraY,
          float* passed_MovingCameraX,
          float* passed_MovingCameraY,
          CSDL_Setup* passed_csdl_setup);
    Crate(int x,
          int y,
          float* passed_CameraX,
          float* passed_CameraY,
          float* passed_MovingCameraX,
          float* passed_MovingCameraY,
          CSDL_Setup* passed_csdl_setup);
    ~Crate();

    void Draw();

    CSprite* getSprite() {return texture;}

private:
    void Update();


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
