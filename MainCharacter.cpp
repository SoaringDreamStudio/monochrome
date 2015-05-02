
#include "MainCharacter.h"

MainCharacter::MainCharacter(int* passed_mouseX, int* passed_mouseY, float* passed_CameraX, float* passed_CameraY, CSDL_Setup* passed_csdl_setup)
{
    csdl_setup = passed_csdl_setup;
    CameraX = passed_CameraX;
    CameraY = passed_CameraY;
    mainX = 400;
    mainY = 300;
    sizeX = 35;
    sizeY = 53;

    mouseX = passed_mouseX;
    mouseY = passed_mouseY;
    centerX = mainX + sizeX/2;
    centerY = mainY + sizeY/2;

    texture = new CSprite(csdl_setup->GetRenderer(), "data/img/hero.png", mainX, mainY, sizeX, sizeY, CameraX, CameraY,
                              CCollisionRectangle(0, 0, 0, 0), csdl_setup);
    n = 0;//градус
    rad = 0;
}
MainCharacter::~MainCharacter()
{

}


void MainCharacter::Update()
{
    delX = *mouseX - centerX;
    delY = *mouseY - centerY;
    rad = acos(delX/(sqrt(delX*delX+delY*delY)));
    if(*mouseY < centerY)
        rad = M_PI + (M_PI - rad);
    n = 180/M_PI * rad;
    n = n + 90;
}
void MainCharacter::Draw()
{
    Update();
    texture->DrawWithRotate(n);
}
