#include "libraries.h"
#include "Main.h"

using namespace std;

int main(int argc, char *argv[])
{

    //����� ������� ����

	//CMain* cmain = new CMain(1280, 800);
	//CMain* cmain = new CMain(1280, 700);
	//CMain* cmain = new CMain(1080, 720);
	CMain* cmain = new CMain(800, 600);

	//������ �������� ����

    //cmain->GameMenu(); //������ �������� ����
    cmain->GameLoop(); //������ �������� ��������
    //cmain->GOMenu(); //������ ���� GameOver
    //cmain->Loading(); //������ ���� Loading

	return 0;

}
