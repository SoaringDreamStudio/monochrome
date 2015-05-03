
#include "walls.h"

Wall::Wall(float* passed_CameraX,
           float* passed_CameraY,
           float* passed_MovingCameraX,
           float* passed_MovingCameraY,
           CSDL_Setup* passed_csdl_setup)
{
    csdl_setup = passed_csdl_setup;
    CameraX = passed_CameraX;
    CameraY = passed_CameraY;
    MovingCameraX = passed_MovingCameraX;
    MovingCameraY = passed_MovingCameraY;
    X = 0;
    Y = 0;
    W = 30;
    H = 30;


    texture = new CSprite(csdl_setup->GetRenderer(), "data/img/wall.jpg", X, Y, W, H, CameraX, CameraY, MovingCameraX, MovingCameraY,
                              CCollisionRectangle(0, 0, W, H), csdl_setup);

}

Wall::Wall(int x,
           int y,
           float* passed_CameraX,
           float* passed_CameraY,
           float* passed_MovingCameraX,
           float* passed_MovingCameraY,
           CSDL_Setup* passed_csdl_setup)
{
    csdl_setup = passed_csdl_setup;
    CameraX = passed_CameraX;
    CameraY = passed_CameraY;
    MovingCameraX = passed_MovingCameraX;
    MovingCameraY = passed_MovingCameraY;
    X = x;
    Y = y;
    W = 30;
    H = 30;


    texture = new CSprite(csdl_setup->GetRenderer(), "data/img/wall.jpg", X, Y, W, H, CameraX, CameraY, MovingCameraX, MovingCameraY,
                              CCollisionRectangle(0, 0, W, H), csdl_setup);

}

Wall::~Wall()
{

}


void Wall::Update()
{
    //anim
}
void Wall::Draw()
{
    Update();
    texture->Draw();
}
