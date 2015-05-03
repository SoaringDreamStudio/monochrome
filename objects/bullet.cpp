
#include "bullet.h"

Bullet::Bullet(int x, int y, float passed_direction, float* passed_CameraX, float* passed_CameraY, CSDL_Setup* passed_csdl_setup)
{
    csdl_setup = passed_csdl_setup;
    direction = passed_direction;
    CameraX = passed_CameraX;
    CameraY = passed_CameraY;
    X = x;
    Y = y;
    W = 5;
    H = 5;

    speed = 10;

    texture = new CSprite(csdl_setup->GetRenderer(), "data/img/bullet.png", X, Y, W, H, CameraX, CameraY,
                              CCollisionRectangle(0, 0, W, H), csdl_setup);

    lifeTime = SDL_GetTicks();
    timer = SDL_GetTicks();

    plsDestroyMe = false;

}

Bullet::~Bullet()
{

}


void Bullet::Update()
{
    if(lifeTime+1000 < SDL_GetTicks())
    {
        plsDestroyMe = true;
    }
    else if(timer+16 < SDL_GetTicks())
    {
        float tempX = speed * cos(direction);
        float tempY = speed * sin(direction);
        texture->SetX(texture->GetX() + tempX);
        texture->SetY(texture->GetY() + tempY);
        timer = SDL_GetTicks();
    }
    //anim
}
void Bullet::Draw()
{
    Update();
    texture->Draw();
}
