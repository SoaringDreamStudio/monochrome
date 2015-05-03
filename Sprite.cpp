#include "libraries.h"
#include "Sprite.h"


CSprite::CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, float *passed_CameraX, float *passed_CameraY, CCollisionRectangle passed_CollisionRect, CSDL_Setup* csdl_setup)
{
    CollisionRect = passed_CollisionRect;
	renderer = passed_renderer;
	image = NULL;

	//���� �������� � ��������� ����� ��� ��� ��������
    if(checkLoadedSprites(csdl_setup, FilePath))
    {
        //���������� ��������
        image = csdl_setup->readSprite(FilePath);
    }

    //���� �������� � ��������� ����� �� ��� ��� ��������
    else
    {
        //��������� �������� � ����
        image = csdl_setup->addSprite(FilePath);
    }

    //���� �������� �� ���� ��������� - ������ ������
	if (image == NULL)
	{
		std::cout << "Couldn't load " << FilePath.c_str() << std::endl;
	}

	hitbox = NULL;

    //������� ����������� ��� ����������� ���������
	//hitbox = IMG_LoadTexture(renderer, "data/img/hitbox.png");

	//if (hitbox == NULL)
	//{
	//	std::cout << "Couldn't load hitbox image" << std::endl;
	//}

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image,NULL,NULL, &img_width, &img_height);

	crop.x = 0;
	crop.y = 0;
	crop.w = img_width;
	crop.h = img_height;


	X_pos = x;
	Y_pos = y;

	Orgin_X = 0;
	Orgin_Y = 0;

	CurrentFrame = 0;
	Amount_Frame_X = 0;
	Amount_Frame_Y = 0;

    CameraX = passed_CameraX;
    CameraY = passed_CameraY;

	Camera.x = rect.x + *CameraX;
    Camera.y = rect.y + *CameraY;
    Camera.w = rect.w;
    Camera.h = rect.h;

    animationDelay = SDL_GetTicks();
}

void CSprite::SetUpAnimation(int passed_Amount_X, int passed_Amount_Y) //��������� ��������
{
	Amount_Frame_X = passed_Amount_X;
	Amount_Frame_Y = passed_Amount_Y;
}
void CSprite::PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed) //�������� ��������
{
    //������ ���� ������ speed ������
    if (animationDelay+Speed < SDL_GetTicks())
	{
	    //���� ������� ���� ������ ���������� - ������ ������
		if (EndFrame <= CurrentFrame)
		{
			CurrentFrame = BeginFrame;
		}

		//����� ���������� ��������� ����
		else
			CurrentFrame++;

        //��������� ������� � ������������ � ������� ������
		crop.x = CurrentFrame * (img_width/Amount_Frame_X);
		crop.y = Row * (img_height/Amount_Frame_Y);
		crop.w = img_width/Amount_Frame_X;
		crop.h = img_height/Amount_Frame_Y;

		//��� �������
		animationDelay = SDL_GetTicks();
	}
}
CSprite::~CSprite(void)
{
	SDL_DestroyTexture(image);
}

void CSprite::DrawWithCoord(CSDL_Setup* csdl_setup, coordinates spawn) //���������� � ������������ � �������� ������������
{

    Camera.x = rect.x + (csdl_setup->GetScreenWidth()/2)-spawn.x + *CameraX;
    Camera.y = rect.y + (csdl_setup->GetScreenHeight()/2)-spawn.y + *CameraY;

    CollisionRect.SetX(rect.x + (csdl_setup->GetScreenWidth()/2)-spawn.x + *CameraX);
    CollisionRect.SetY(rect.y + (csdl_setup->GetScreenHeight()/2)-spawn.y + *CameraY);

	SDL_RenderCopy(renderer, image, &crop, &Camera);
    SDL_Rect tmpper = CollisionRect.GetRectangle();
	SDL_RenderCopy(renderer, hitbox, NULL, &tmpper);
}
void CSprite::Draw() //���������� (��� ����� spawn)
{
    Camera.x = rect.x + *CameraX;
    Camera.y = rect.y + *CameraY;

    CollisionRect.SetX(rect.x + *CameraX);
    CollisionRect.SetY(rect.y + *CameraY);

	SDL_RenderCopy(renderer, image, &crop, &Camera);
    SDL_Rect tmpper = CollisionRect.GetRectangle();
	SDL_RenderCopy(renderer, hitbox, NULL, &tmpper);
}

void CSprite::DrawStatic() //���������� � ����
{
    Camera.x = rect.x;// + *CameraX;
    Camera.y = rect.y;// + *CameraY;

    CollisionRect.SetX(rect.x);// + *CameraX);
    CollisionRect.SetY(rect.y);// + *CameraY);

	SDL_RenderCopy(renderer, image, &crop, &Camera);
    SDL_Rect tmpper = CollisionRect.GetRectangle();
	SDL_RenderCopy(renderer, hitbox, NULL, &tmpper);
}

void CSprite::DrawSteady() //���������� � ���� (� ��, ��� ��� �� �������. �������� ���������� ������ DrawStatic)
{
    SDL_RenderCopy(renderer, image, &crop, &Camera);


   // CollisionRect.SetX(rect.x + *CameraX);
   // CollisionRect.SetY(rect.y + *CameraY);

    SDL_Rect tmpper = CollisionRect.GetRectangle();
	SDL_RenderCopy(renderer, hitbox, NULL, &tmpper);
}

void CSprite::SetX(float X)
{
	X_pos = X;
	rect.x = int(X_pos - Orgin_X);
}

void CSprite::SetY(float Y)
{
	Y_pos = Y;
	rect.y = int(Y_pos - Orgin_Y);
}

void CSprite::SetPosition(float X, float Y)
{
	X_pos = X;
	Y_pos = Y;

	rect.x = int(X_pos - Orgin_X);
	rect.y = int(Y_pos - Orgin_Y);
}

float CSprite::GetX()
{
	return X_pos;
}

float CSprite::GetY()
{
	return Y_pos;
}

void CSprite::SetOrgin(float X, float Y)
{
	Orgin_X = X;
	Orgin_Y = Y;

	SetPosition(GetX(), GetY());
}


void CSprite::SetWidht(int W)
{
	rect.w = W;
}

void CSprite::SetHeight(int H)
{
	rect.h = H;
}


int CSprite::GetWidht()
{
	return rect.w;
}
int CSprite::GetHeight()
{
	return rect.h;
}

bool  CSprite::isColliding(CCollisionRectangle theCollider) //�������� �� ������������
{
    return !(CollisionRect.GetRectangle().x + CollisionRect.GetRectangle().w < theCollider.GetRectangle().x
             || CollisionRect.GetRectangle().y + CollisionRect.GetRectangle().h < theCollider.GetRectangle().y
             || CollisionRect.GetRectangle().x > theCollider.GetRectangle().x + theCollider.GetRectangle().w
             || CollisionRect.GetRectangle().y > theCollider.GetRectangle().y + theCollider.GetRectangle().h);
}

bool  CSprite::isColliding(int x, int y) // �������� �� ������������
{
    return !(CollisionRect.GetRectangle().x + CollisionRect.GetRectangle().w < x
             || CollisionRect.GetRectangle().y + CollisionRect.GetRectangle().h < y
             || CollisionRect.GetRectangle().x > x
             || CollisionRect.GetRectangle().y > y);
}

bool CSprite::checkLoadedSprites(CSDL_Setup* csdl_setup, std::string FilePath) //�������� �� �������������
{
    if(csdl_setup->checkSprite(FilePath))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CSprite::DrawWithRotate(double angle)
{
    CollisionRect.SetX(rect.x);// + *CameraX);
    CollisionRect.SetY(rect.y);// + *CameraY);

    SDL_RenderCopyEx(renderer,
                     image,
                     NULL,
                     &rect,
                     angle,
                     NULL,
                     SDL_FLIP_NONE);


    SDL_Rect tmpper = CollisionRect.GetRectangle();
	SDL_RenderCopy(renderer, hitbox, NULL, &tmpper);
}
