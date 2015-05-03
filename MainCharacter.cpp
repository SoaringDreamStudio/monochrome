
#include "MainCharacter.h"

MainCharacter::MainCharacter(int* passed_mouseX, int* passed_mouseY, float* passed_CameraX, float* passed_CameraY, CSDL_Setup* passed_csdl_setup)
{
    csdl_setup = passed_csdl_setup;
    CameraX = passed_CameraX;
    CameraY = passed_CameraY;
    sizeX = 35;
    sizeY = 80;
    mainX = csdl_setup->GetScreenWidth()/2 - sizeX/2;
    mainY = csdl_setup->GetScreenHeight()/2 - sizeY/2;

    speed = 1;

    mouseX = passed_mouseX;
    mouseY = passed_mouseY;
    centerX = mainX + sizeX/2;
    centerY = mainY + sizeY/2;

    texture = new CSprite(csdl_setup->GetRenderer(), "data/img/hero.png", mainX, mainY, sizeX, sizeY, CameraX, CameraY,
                              CCollisionRectangle(0, 26, sizeX, 26), csdl_setup);
    n = 0;//градус
    rad = 0;

    MoveLeft = false;
    MoveDown = false;
    MoveRight = false;
    MoveUp = false;

    timeCheckMoving = SDL_GetTicks();
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
    UpdateControls();
}
void MainCharacter::Draw()
{
    Update();
    texture->DrawWithRotate(n);
}

void MainCharacter::UpdateControls()
{

    //если происходит какое-то событие
    switch (csdl_setup->GetMainEvent()->type)
    {
        //если нажата клавиша
        case SDL_KEYDOWN:
            switch (csdl_setup->GetMainEvent()->key.keysym.sym)
            {
                //если нажата клавиша A
                case SDLK_a:
                    //включить триггер передвижения налево
                    MoveLeft = true;
                    break;
                //если нажата клавиша S
                case SDLK_s:
                    //включить триггер передвижения вниз
                    MoveDown = true;
                    break;
                //если нажата клавиша D
                case SDLK_d:
                    //включить триггер передвижения направо
                    MoveRight = true;
                    break;
                //если нажата клавиша W
                case SDLK_w:
                    //включить триггер передвижения вверх
                    MoveUp = true;
                    break;
                default:
                    break;
            }

            break;

        //если отпущена клавиша (отдельный блок для считывания движения)
        case SDL_KEYUP:
            switch (csdl_setup->GetMainEvent()->key.keysym.sym)
            {
                //если нажата клавиша A
                case SDLK_a:
                    //выключить триггер передвижения влево
                    MoveLeft = false;

                    break;

                //если нажата клавиша S
                case SDLK_s:
                    //выключить триггер передвижения вниз
                    MoveDown = false;

                    break;

                //если нажата клавиша D
                case SDLK_d:
                    //выключить триггер передвижения вправо
                    MoveRight = false;

                    break;

                //если нажата клавиша W
                case SDLK_w:
                    //выключить триггер передвижения вверх
                    MoveUp = false;

                    break;

                default:
                    break;
            }

            break;

        default:
            break;


        break;
    }

    //просчет движения каждые 0,1 сек
    if (timeCheckMoving+16 < SDL_GetTicks() )
    {
        //просчет движения при нажатии клавиш
        if (MoveLeft)
        {
            *CameraX = *CameraX + speed;
        }
        if (MoveDown)
        {
            *CameraY = *CameraY - speed;
        }
        if (MoveRight)
        {
            *CameraX = *CameraX - speed;
        }
        if (MoveUp)
        {
            *CameraY = *CameraY + speed;
        }
        timeCheckMoving = SDL_GetTicks();
    }
}

int MainCharacter::getDirection()
{
    if ((!MoveLeft &&  !MoveDown && !MoveRight && MoveUp) ||
        (MoveLeft &&  !MoveDown && MoveRight && MoveUp))
    {
        return 0;
    }
    else if (!MoveLeft &&  !MoveDown && MoveRight && MoveUp)
    {
        return 1;
    }
    else if ((!MoveLeft &&  !MoveDown && MoveRight && !MoveUp) ||
            (!MoveLeft &&  MoveDown && MoveRight && MoveUp))
    {
        return 2;
    }
    else if (!MoveLeft &&  MoveDown && MoveRight && !MoveUp)
    {
        return 3;
    }
    else if ((!MoveLeft &&  MoveDown && !MoveRight && !MoveUp) ||
            (MoveLeft &&  MoveDown && MoveRight && !MoveUp))
    {
        return 4;
    }
    else if (MoveLeft &&  MoveDown && !MoveRight && !MoveUp)
    {
        return 5;
    }
    else if ((MoveLeft &&  !MoveDown && !MoveRight && !MoveUp) ||
            (MoveLeft &&  MoveDown && !MoveRight && MoveUp))
    {
        return 6;
    }
    else if (MoveLeft &&  !MoveDown && !MoveRight && MoveUp)
    {
        return 7;
    }
}

