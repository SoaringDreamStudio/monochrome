
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
    for(int i=0; i < 400; i=i+30)
    {
        crates.push_back(new Crate(i+200, 150, CameraX, CameraY, csdl_setup));
        crates.push_back(new Crate(i+200, 550, CameraX, CameraY, csdl_setup));
        crates.push_back(new Crate(170, i+153, CameraX, CameraY, csdl_setup));
        crates.push_back(new Crate(617, i+153, CameraX, CameraY, csdl_setup));

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


void GameLvl::Update()
{
    UpdateCollide();
            //std::cout << "*CameraX " << *CameraX << "*CameraY " << *CameraY << std::endl;
    //anim
}
void GameLvl::Draw()
{
    Update();
    for(std::vector<Crate*>::iterator i = crates.begin(); i != crates.end(); i++)
    {
        (*i)->Draw();
    }

    MainHero->Draw();
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

}
