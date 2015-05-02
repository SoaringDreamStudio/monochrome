#include "libraries.h"
#include "Main.h"

using namespace std;

int main(int argc, char *argv[])
{

    //Выбор размера окна

	//CMain* cmain = new CMain(1280, 800);
	//CMain* cmain = new CMain(1280, 700);
	//CMain* cmain = new CMain(1080, 720);
	CMain* cmain = new CMain(800, 600);

	//Запуск процесса игры

    //cmain->GameMenu(); //Запуск главного меню
    cmain->GameLoop(); //Запуск игрового процесса
    //cmain->GOMenu(); //Запуск окна GameOver
    //cmain->Loading(); //Запуск окна Loading

	return 0;

}
