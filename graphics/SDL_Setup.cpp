#include "../libraries.h"
#include "SDL_Setup.h"


CSDL_Setup::CSDL_Setup(bool* quit, int passed_ScreenWidth, int passed_ScreenHeight)
{
    //� ������ ������ ������������� ����� - ����� �� ��������� � ������ ������
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "Unable to init SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    ScreenWidth = passed_ScreenWidth;
    ScreenHeight = passed_ScreenHeight;
	window = NULL;
	window = SDL_CreateWindow("monochrome", 0, 30, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN /*|| SDL_WINDOW_FULLSCREEN*/);

	if (window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		*quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	mainEvent = new SDL_Event();
}


CSDL_Setup::~CSDL_Setup(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	delete mainEvent;
}

SDL_Renderer* CSDL_Setup::GetRenderer()
{
	return renderer;
}

SDL_Event* CSDL_Setup::GetMainEvent()
{
	return mainEvent;
}

void CSDL_Setup::Begin()
{
    //"����� �������" �� mainEvent
	SDL_PollEvent(mainEvent);

	//�������� ������
	SDL_RenderClear(renderer);
}

void CSDL_Setup::End()
{
    //���������� ������
	SDL_RenderPresent(renderer);
}

int CSDL_Setup::GetScreenWidth()
{
    return ScreenWidth;
}
int CSDL_Setup::GetScreenHeight()
{
    return ScreenHeight;
}

SDL_Texture* CSDL_Setup::addSprite(std::string FilePath) //�������� ������ � map ����������� ��������
{
    SDL_Texture* tmpImage = IMG_LoadTexture(renderer, FilePath.c_str());
    createdSprites.insert(std::pair<std::string, SDL_Texture*>(FilePath, tmpImage));
    return createdSprites[FilePath];
}

bool CSDL_Setup::checkSprite(std::string FilePath)  //��������� ������ � map ����������� �������� �� �������������
{
    if( createdSprites.find(FilePath) != createdSprites.end() )
        return true;
    else
        return false;
}

SDL_Texture* CSDL_Setup::readSprite(std::string FilePath) //������� ������ �� map ����������� ��������
{
    return createdSprites[FilePath];
}

void CSDL_Setup::showMap() //�������� ������� ���� ����������� ��������
{
    for(std::map<std::string, SDL_Texture*>::iterator i = createdSprites.begin(); i != createdSprites.end(); ++i)
    {
        std::cout << "\t" << i->first << "\t" << i->second << std::endl;
    }
    std::cout << std::endl;
}
