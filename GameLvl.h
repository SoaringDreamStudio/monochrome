
#include "libraries.h"
#include "objects.h"
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
    void UpdateControls();
    void UpdateCamera();
    bool pointInTR(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3);
    float GetDistance(int X1, int Y1, int X2, int Y2);

    MainCharacter* MainHero;

    int* MouseX;
    int* MouseY;

    int controlTimer;
    int timerCamera;

    float* CameraX;
    float* CameraY;

    float MovingCameraX;
    float MovingCameraY;
    CSDL_Setup* csdl_setup;
    std::vector<Crate*> crates;
    std::vector<Bullet*> bullets;
    std::vector<Wall*> walls;
};
