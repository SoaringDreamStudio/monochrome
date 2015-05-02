#include "libraries.h"
#include "Main.h"

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;
	quit = false;
	Mquit = false;

	csdl_setup = new CSDL_Setup(&quit, ScreenWidth, ScreenHeight);

    CameraX = 0;
	CameraY = 0;

	MouseX = 0;
	MouseY = 0;
	ignoreGameOver = false;

}


CMain::~CMain(void)
{
	delete csdl_setup;
	//delete MainHero;
}

void CMain::GameLoop(void)
{
    /*
    //инициализируем процесс загрузки
    LoadingProcess* loadingProcess = new LoadingProcess(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY);
    DrawLoadingProcess(3.3, loadingProcess);

    //инициализируем положение камеры
    CameraX = 0;
    CameraY = 0;
    DrawLoadingProcess(3.3, loadingProcess);

    //инициализируем положение мыши и игровой уровень
    SDL_GetMouseState(&MouseX, &MouseY);
    Stage1 = new CEnviroment(&CameraX, &CameraY, &MouseX, &MouseY,  csdl_setup, loadingProcess);
    DrawLoadingProcess(3.4, loadingProcess);

    //инициализируем игровой интерфейс
    GameInterface* gameInterface = new GameInterface(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY);
    DrawLoadingProcess(9, loadingProcess);

    //инициализируем главного героя
    MainHero = new MainCharacter(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY, Stage1, loadingProcess, gameInterface);
    DrawLoadingProcess(4, loadingProcess);

    interpretator = new CInterpretator(Stage1, MainHero);
    DrawLoadingProcess(4, loadingProcess);

    //удаляем процесс загрузки
    delete loadingProcess;
*/
    //основной процесс игры
    //Выполняется до тех пор пока переменная quit ложна и не был нажат крестик
	while(!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
	{
	    //очищаем окно и проверяем на события
		csdl_setup->Begin();

        //считываем положение мышки
		SDL_GetMouseState(&MouseX, &MouseY);
        /*
        //проверка на режим игры и считывание клавиш для переключения режимов
        Stage1->Update();

        interpretator->command(Stage1->GetConsoleCommand());
        Stage1->SetConsoleCommand("");

        //отрисовка заднего плана
        Stage1->DrawBack();

        //отрисовка главного героя
        MainHero->Draw();

        //обновление анимации и управление ГГ
        MainHero->Update();

        //просчет и прорисовка для игрового интерфейса
        gameInterface->Update();
        gameInterface->Draw();

        //отрисовка переднего плана
        Stage1->DrawFront();
*/
        //отрисовка рендера
		csdl_setup->End();
/*
		//в случае, если здоровье ГГ упадет до 0 - удалить его и выйти из цикла
		if(*(MainHero->GetHP()) <= 0)
        {
            delete MainHero;
            break;
        }
        if(gameInterface->getMquit())
        {
            ignoreGameOver = true;
            break;
        }
        */
	}

}
/*
void CMain::GameMenu(void)
{
    //инициализация главного меню
    MainMenu* mainMenu = new MainMenu(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY, gsocket);
    //CSprite* menu1 = new CSprite(csdl_setup->GetRenderer(), "data/img/menu1.png", 100, 0, 800, 600, &CameraX, &CameraY, CCollisionRectangle());
    //CSprite* menuButton1 = new CSprite(csdl_setup->GetRenderer(), "data/img/menuButton.png", 50, 150, 300, 100, &CameraX, &CameraY, CCollisionRectangle());
    //CSprite* menuButton2 = new CSprite(csdl_setup->GetRenderer(), "data/img/menuButton.png", 50, 300, 300, 100, &CameraX, &CameraY, CCollisionRectangle());

    //исполняется до тех пор, пока не будет передана команда выхода из главного меню

    ////А нужен ли вообще этот цикл?
    for(csdl_setup->GetMainEvent()->type != SDL_QUIT)
    {

        ignoreGameOver = false;

        //????инициализация Mquit в mainmenu (используется для мгновенного выхода из программы)
        mainMenu->setMquit(false);

        //инициализация Mquit для цикла
        Mquit = false;

        //цикл для отображения главного меню
        //Выполняется до тех пор пока переменная quit ложна и не был нажат крестик
        while(!Mquit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
        {
            //очищаем окно и проверяем на события
            csdl_setup->Begin();

            //считываем положение мышки
            SDL_GetMouseState(&MouseX, &MouseY);

            //отрисовка и "просчеты"
            mainMenu->Draw();
            mainMenu->Update();

            //приравнивание Mquit Mquit'y  из меню
            Mquit = mainMenu->getMquit();

            //menu1->Draw();
            //menuButton1->Draw();
            //menuButton2->Draw();

            //отрисовка рендера
            csdl_setup->End();
        }
        if(Mquit)
        {
            //запуск игрового процесса
            GameLoop();

            //запуск GameOver
            GOMenu();
            //СУКА!! БОЛЬШЕ НЕ БУДЕШЬ БАГОВАТЬ
            csdl_setup->GetMainEvent()->type = NULL;
            csdl_setup->GetMainEvent()->button.state = NULL;
            csdl_setup->GetMainEvent()->button.button = NULL;
        }
    }
}*/
/*
bool CMain::GOMenu(void)
{
    //инициализация Mquit
    Mquit = ignoreGameOver;

    //инициализация GameOver окна
    GameOverMenu* gameOverMenu = new GameOverMenu(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY);

    //основной цикл GameOver окна
    //Выполняется до тех пор пока переменная quit ложна и не был нажат крестик
    while(!Mquit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
    {
        //очищаем окно и проверяем на события
        csdl_setup->Begin();

        //считываем положение мышки
		SDL_GetMouseState(&MouseX, &MouseY);

		//отрисовка и "просчеты"
		gameOverMenu->Draw();
        gameOverMenu->Update();

        //приравнивание Mquit Mquit'y из окна
        Mquit = gameOverMenu->getMquit();

        //отрисовка рендера
		csdl_setup->End();
    }
    return true;
}
*//*
void CMain::Loading(void)
{
    //инициализация окна загрузки
    LoadingProcess* loadingProcess = new LoadingProcess(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY);

    //основной цикл загрузки
    //Выполняется до тех пор пока переменная quit ложна и не был нажат крестик
    while(csdl_setup->GetMainEvent()->type != SDL_QUIT)
    {
        //очищаем окно и проверяем на события
        csdl_setup->Begin();

        //считываем положение мышки
		SDL_GetMouseState(&MouseX, &MouseY);

		//добавляем 0.1 процент
        loadingProcess->addProcent(0.1);

        //просчеты и "отрисовка"
        loadingProcess->Update();
		loadingProcess->Draw();

        //отрисовка рендера
		csdl_setup->End();
    }
}
*//*
void CMain::DrawLoadingProcess(float percent, LoadingProcess* loadingProcess) //отрисовка процесса (только для опытных пользователей, хе-хе)
{
    csdl_setup->Begin();
    loadingProcess->addProcent(percent);
    loadingProcess->Update();
    loadingProcess->Draw();
    csdl_setup->End();
}
*/
