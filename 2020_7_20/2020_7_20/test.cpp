#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//string Num(string s)
//{
//	string num;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] >= '0'&&s[i] <= '9')
//			num += s[i];
//	}
//	return num;
//}
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		cout << Num(str) << endl;
//	}
//}

#include <stdio.h>
char map[10][10];
struct mi {
	int x;
	int y;
};
void BFS(int a, int b);
int main()
{
	char z;
	while (scanf("%c", &z) != EOF) {
		map[0][0] = z;
		int i, j;
		for (i = 1; i < 10; i++) map[0][i] = getchar();
		getchar();
		for (i = 1; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				map[i][j] = getchar();
			}
			getchar();
		}
		BFS(0, 1);
		int x = 9, y = 8, k;
		int cnt = 0;
		printf("%d\n", map[9][8]);
	}
	return 0;
}
void BFS(int a, int b)
{
	int xx[4] = { 0, 0, 1, -1 };
	int yy[4] = { 1, -1, 0, 0 };
	struct mi A;
	A.x = a;
	A.y = b;
	struct mi queue[100];
	int front = -1, rear = -1;
	queue[++rear] = A;
	map[a][b] = 0;
	int zx, zy, i;
	while (rear != front) {
		struct mi temp;
		temp = queue[++front];
		if (temp.x == 9 && temp.y == 8) break;
		for (i = 0; i < 4; i++) {
			zx = temp.x + xx[i];
			zy = temp.y + yy[i];
			if (zx >= 10 || zx < 0 || zy >= 10 || zy < 0 || map[zx][zy] != '.') continue;
			map[zx][zy] = map[temp.x][temp.y] + 1;
			struct mi kao;
			kao.x = zx;
			kao.y = zy;
			queue[++rear] = kao;
		}
	}
}