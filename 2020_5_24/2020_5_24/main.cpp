#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"
#include "test.h"
int main()
{
	char AgainGame;
	do
	{
		Point21 newGame;
		newGame.Game();
		cout << endl << endl << "***************************************************";
		cout << endl << "��������һ����,����������1,�˳������������ݲ��س�:";

		cin >> AgainGame;
		cout << endl << "***************************************************";
	} while (AgainGame == '1');
	return 0;
}