
#include "enemy.h"

Enemy::Enemy(int x,
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
    W = 60;
    H = 60;


    texture = new CSprite(csdl_setup->GetRenderer(), "data/img/enemy.png", X, Y, W, H, CameraX, CameraY, MovingCameraX, MovingCameraY,
                              CCollisionRectangle(0, 0, W, H), csdl_setup);
    texture->SetUpAnimation(2,1);

    HP = 100;
    timerDamaged = SDL_GetTicks() -500;

}

Enemy::~Enemy()
{

}

bool Enemy::Damage(int damage)
{
    HP -= damage;
    timerDamaged = SDL_GetTicks();
    if(HP <= 0)
        return 0;
    else
        return 1;
}

void Enemy::Update()
{
    //anim
    if(timerDamaged+500 < SDL_GetTicks())
        texture->PlayAnimation(0, 0, 0, 250);
    else
        texture->PlayAnimation(1, 1, 0, 250);
}
void Enemy::Draw()
{
    Update();
    texture->Draw();
}
