#pragma once
#include "graphics.h"
//#include "MainCharacter.h"
#include "GameLvl.h"
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
	//void DrawLoadingProcess(float, LoadingProcess*); //��������� ������� ��� ���������� ��������� �������� �� �������� ������� � ����������� �� ������

private:
    float CameraX;
    float CameraY;


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

