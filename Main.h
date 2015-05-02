#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"
#include "MainCharacter.h"
//#include "Enviroment.h"
//#include "Menu.h"
#include <windows.h>
#include <math.h>
class CMain
{
public:
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain(void);
	void GameLoop();
	void GameMenu();
	//bool GOMenu();
	//void Loading();
	//void DrawLoadingProcess(float, LoadingProcess*); //временная функция для увеличения прогресса загрузки на заданный процент и отображения на экране

private:
    float CameraX;
    float CameraY;

    MainCharacter* MainHero;

	int ScreenWidth;
	int ScreenHeight;
	bool quit;
	bool Mquit;

	CSDL_Setup* csdl_setup;

	int timeCheck;
	int MouseX;
	int MouseY;
    bool ignoreGameOver;
};

