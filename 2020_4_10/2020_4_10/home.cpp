#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

int main()
{
	HideCursor();
	srand(time(NULL));
	Block::State_Init();
	Game* pG = new Game();
	pG->Begin();
	while (1)
	{
		int tick_times = 0;
		while (++tick_times < pG->GetTickCnt())      //��������ʱ�����Լ��������,��������ķ���������
		{
			pG->CheckBoard();
			Sleep(10);
		}
		if (!pG->ChangePos(1, 0))
		{
			if (pG->runB.p == Point(1, 5))            //���һ��ʼ���²�ȥ,game over.
			{
				pG->Over();
				break;
			}
			pG->PlaceOn();
			pG->CheckLine();
			pG->GetNext();
		}
	}
	delete pG;
	return 0;
}