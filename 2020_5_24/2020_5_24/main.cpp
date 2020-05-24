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
		cout << endl << "你想再玩一次吗,再玩请输入1,退出请输任意内容并回车:";

		cin >> AgainGame;
		cout << endl << "***************************************************";
	} while (AgainGame == '1');
	return 0;
}