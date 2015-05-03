
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

    controlTimer = SDL_GetTicks();
    for(int i=0; i < 400; i=i+30)
    {
        walls.push_back(new Wall(i+200, 150, CameraX, CameraY, csdl_setup));
        walls.push_back(new Wall(i+200, 550, CameraX, CameraY, csdl_setup));
        walls.push_back(new Wall(170, i+153, CameraX, CameraY, csdl_setup));
        walls.push_back(new Wall(617, i+153, CameraX, CameraY, csdl_setup));

    }

    crates.push_back(new Crate(230, 250, CameraX, CameraY, csdl_setup));
    crates.push_back(new Crate(260, 250, CameraX, CameraY, csdl_setup));
    crates.push_back(new Crate(230, 280, CameraX, CameraY, csdl_setup));
    crates.push_back(new Crate(400, 450, CameraX, CameraY, csdl_setup));
    crates.push_back(new Crate(315, 400, CameraX, CameraY, csdl_setup));
    crates.push_back(new Crate(387, 240, CameraX, CameraY, csdl_setup));
    crates.push_back(new Crate(500, 300, CameraX, CameraY, csdl_setup));
    crates.push_back(new Crate(400, 300, CameraX, CameraY, csdl_setup));

	MainHero = new MainCharacter(MouseX, MouseY, CameraX, CameraY, csdl_setup);
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
                    bullets.push_back(new Bullet(csdl_setup->GetScreenWidth()/2-*CameraX+tempX,csdl_setup->GetScreenHeight()/2-*CameraY+tempY, MainHero->getDirectionInRad(), CameraX,CameraY, csdl_setup));

                    csdl_setup->GetMainEvent()->type = NULL;
                    csdl_setup->GetMainEvent()->button.state = NULL;
                    csdl_setup->GetMainEvent()->button.button = NULL;
               }
    }
}

void GameLvl::Update()
{
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
