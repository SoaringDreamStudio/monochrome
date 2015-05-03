
#include "GameLvl.h"

GameLvl::GameLvl(int* passed_MouseX,
                int* passed_MouseY,
                float* passed_CameraX,
                float* passed_CameraY,
                CSDL_Setup* passed_csdl_setup)
{
    csdl_setup = passed_csdl_setup;
    MouseX = passed_MouseX;
    MouseY = passed_MouseY;
    CameraX = passed_CameraX;
    CameraY = passed_CameraY;

    MovingCameraX = 0;
    MovingCameraY = 0;

    controlTimer = SDL_GetTicks();
    timerCamera = SDL_GetTicks();
    for(int i=0; i < 400; i=i+30)
    {
        walls.push_back(new Wall(i+200, 150, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
        walls.push_back(new Wall(i+200, 550, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
        walls.push_back(new Wall(170, i+153, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
        walls.push_back(new Wall(617, i+153, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));

    }

    crates.push_back(new Crate(230, 250, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
    crates.push_back(new Crate(260, 250, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
    crates.push_back(new Crate(230, 280, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
    crates.push_back(new Crate(400, 450, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
    crates.push_back(new Crate(315, 400, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
    crates.push_back(new Crate(387, 240, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
    crates.push_back(new Crate(500, 300, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));
    crates.push_back(new Crate(400, 300, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));

	MainHero = new MainCharacter(MouseX, MouseY, CameraX, CameraY, &MovingCameraX, &MovingCameraY, csdl_setup);
}
GameLvl::~GameLvl()
{

}
void GameLvl::UpdateControls()
{
    if(controlTimer+16 < SDL_GetTicks())
    {
        if((csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONUP) &&
               (csdl_setup->GetMainEvent()->button.state == SDL_RELEASED) &&
               (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON(SDL_BUTTON_LEFT)))
               {
                    float tempX = 40 * cos(MainHero->getDirectionInRad());
                    float tempY = 40 * sin(MainHero->getDirectionInRad());
                    bullets.push_back(new Bullet(csdl_setup->GetScreenWidth()/2-*CameraX+tempX,csdl_setup->GetScreenHeight()/2-*CameraY+tempY, MainHero->getDirectionInRad(), CameraX,CameraY, &MovingCameraX, &MovingCameraY, csdl_setup));

                    csdl_setup->GetMainEvent()->type = NULL;
                    csdl_setup->GetMainEvent()->button.state = NULL;
                    csdl_setup->GetMainEvent()->button.button = NULL;
               }
    }

}


bool GameLvl::pointInTR(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3)
{
    int a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
    int b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
    int c = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);

    if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
        return 1;
    else
        return 0;
}

void GameLvl::UpdateCamera()
{
    int speed = 4;
    if(timerCamera+16 < SDL_GetTicks())
    {
        if(pointInTR(*MouseX, *MouseY, 0, 0, csdl_setup->GetScreenWidth(), 0, csdl_setup->GetScreenWidth()/2, csdl_setup->GetScreenHeight()/2))
        {

            float distance = GetDistance(MovingCameraX, MovingCameraY, 1, csdl_setup->GetScreenHeight()/4);
            /*
            std::cout << "MovingCameraX " << MovingCameraX << std::endl;
            std::cout << "MovingCameraY " << MovingCameraY << std::endl;
            std::cout << "csdl_setup->GetScreenHeight()/4 " << csdl_setup->GetScreenHeight()/4 << std::endl;
            std::cout << "distance " << distance << std::endl;
            */
            if(MovingCameraX != 1 && distance > 5)
            {
                MovingCameraX = MovingCameraX - ((MovingCameraX - 1) / distance)*speed;
            }
            else
            {
                MovingCameraX = 1;
            }
            if(MovingCameraY != csdl_setup->GetScreenHeight()/4 && distance > 5)
            {
                MovingCameraY = MovingCameraY - ((MovingCameraY - csdl_setup->GetScreenHeight()/4) / distance)*speed;
            }
            else
            {
                MovingCameraY = csdl_setup->GetScreenHeight()/4;
            }
        }
        else if(pointInTR(*MouseX, *MouseY, 0, 0, 0, csdl_setup->GetScreenHeight(), csdl_setup->GetScreenWidth()/2, csdl_setup->GetScreenHeight()/2))
        {
            float distance = GetDistance(MovingCameraX, MovingCameraY, csdl_setup->GetScreenWidth()/4, 1);
            if(MovingCameraX != csdl_setup->GetScreenWidth()/4 && distance > 5)
            {
                MovingCameraX = MovingCameraX - ((MovingCameraX - csdl_setup->GetScreenWidth()/4) / distance)*speed;
            }
            else
            {
                MovingCameraX = csdl_setup->GetScreenWidth()/4;
            }
            if(MovingCameraY != 1 && distance > 5)
            {
                MovingCameraY = MovingCameraY - ((MovingCameraY - 1) / distance)*speed;
            }
            else
            {
                MovingCameraY = 1;
            }
        }
        else if(pointInTR(*MouseX, *MouseY, csdl_setup->GetScreenWidth(), csdl_setup->GetScreenHeight(), csdl_setup->GetScreenWidth(), 0, csdl_setup->GetScreenWidth()/2, csdl_setup->GetScreenHeight()/2))
        {
            float distance = GetDistance(MovingCameraX, MovingCameraY, -csdl_setup->GetScreenWidth()/4, 1);
            if(MovingCameraX != -csdl_setup->GetScreenWidth()/4 && distance > 5)
            {
                MovingCameraX = MovingCameraX - ((MovingCameraX - (-csdl_setup->GetScreenWidth()/4)) / distance)*speed;
            }
            else
            {
                MovingCameraX = -csdl_setup->GetScreenWidth()/4;
            }
            if(MovingCameraY != 1 && distance > 5)
            {
                MovingCameraY = MovingCameraY - ((MovingCameraY - 1) / distance)*speed;
            }
            else
            {
                MovingCameraY = 1;
            }
        }
        else if(pointInTR(*MouseX, *MouseY, csdl_setup->GetScreenWidth(), csdl_setup->GetScreenHeight(), 0, csdl_setup->GetScreenHeight(), csdl_setup->GetScreenWidth()/2, csdl_setup->GetScreenHeight()/2))
        {
            float distance = GetDistance(MovingCameraX, MovingCameraY, 1, -csdl_setup->GetScreenHeight()/4);
            if(MovingCameraX != 1 && distance > 5)
            {
                MovingCameraX = MovingCameraX - ((MovingCameraX - 1) / distance)*speed;
            }
            else
            {
                MovingCameraX = 1;
            }
            if(MovingCameraY != - csdl_setup->GetScreenHeight()/4 && distance > 5)
            {
                MovingCameraY = MovingCameraY - ((MovingCameraY - (-csdl_setup->GetScreenHeight()/4)) / distance)*speed;
            }
            else
            {
                MovingCameraY = -csdl_setup->GetScreenHeight()/4;
            }
        }
        else
        {
            MovingCameraX = 0;
            MovingCameraY = 0;
        }
        timerCamera = SDL_GetTicks();
    }

}

void GameLvl::Update()
{
    UpdateCamera();
    UpdateControls();
    UpdateCollide();
    for(std::vector<Bullet*>::iterator i = bullets.begin(); i != bullets.end(); i++)
    {
        if((*i)->Destroy())
        {
            bullets.erase(i);
            i--;
        }
    }
            //std::cout << "*CameraX " << *CameraX << "*CameraY " << *CameraY << std::endl;
    //anim
}
void GameLvl::Draw()
{
    Update();
    for(std::vector<Wall*>::iterator i = walls.begin(); i != walls.end(); i++)
    {
        (*i)->Draw();
    }
    for(std::vector<Crate*>::iterator i = crates.begin(); i != crates.end(); i++)
    {
        (*i)->Draw();
    }

    MainHero->Draw();
    for(std::vector<Bullet*>::iterator i = bullets.begin(); i != bullets.end(); i++)
    {
        (*i)->Draw();
    }
}
void GameLvl::UpdateCollide()
{
    for(std::vector<Crate*>::iterator i = crates.begin(); i != crates.end(); i++)
    {
        if((*i)->getSprite()->isColliding(MainHero->getSprite()->GetCollisionRect()))
        {
            if(MainHero->getDirection() == 0)
            {
                *CameraY = *CameraY - MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 1)
            {
                *CameraX = *CameraX + MainHero->getSpeed();
                *CameraY = *CameraY - MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 2)
            {
                *CameraX = *CameraX + MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 3)
            {
                *CameraX = *CameraX + MainHero->getSpeed();
                *CameraY = *CameraY + MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 4)
            {
                *CameraY = *CameraY + MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 5)
            {
                *CameraX = *CameraX - MainHero->getSpeed();
                *CameraY = *CameraY + MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 6)
            {
                *CameraX = *CameraX - MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 7)
            {
                *CameraX = *CameraX - MainHero->getSpeed();
                *CameraY = *CameraY - MainHero->getSpeed();
            }
        }

    }
    for(std::vector<Wall*>::iterator i = walls.begin(); i != walls.end(); i++)
    {
        if((*i)->getSprite()->isColliding(MainHero->getSprite()->GetCollisionRect()))
        {
            if(MainHero->getDirection() == 0)
            {
                *CameraY = *CameraY - MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 1)
            {
                *CameraX = *CameraX + MainHero->getSpeed();
                *CameraY = *CameraY - MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 2)
            {
                *CameraX = *CameraX + MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 3)
            {
                *CameraX = *CameraX + MainHero->getSpeed();
                *CameraY = *CameraY + MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 4)
            {
                *CameraY = *CameraY + MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 5)
            {
                *CameraX = *CameraX - MainHero->getSpeed();
                *CameraY = *CameraY + MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 6)
            {
                *CameraX = *CameraX - MainHero->getSpeed();
            }
            if(MainHero->getDirection() == 7)
            {
                *CameraX = *CameraX - MainHero->getSpeed();
                *CameraY = *CameraY - MainHero->getSpeed();
            }


        }
        for(std::vector<Bullet*>::iterator z = bullets.begin(); z != bullets.end(); z++)
        {
            if((*i)->getSprite()->isColliding((*z)->getSprite()->GetCollisionRect()))
            {
                (*z)->setDestroy();
            }
        }

    }

}

float GameLvl::GetDistance(int X1, int Y1, int X2, int Y2)
{
	float DifferenceX = X1 - X2;
	float DifferenceY = Y1 - Y2;
	float distance = sqrt((DifferenceX * DifferenceX) + (DifferenceY * DifferenceY));
	return distance;
}
