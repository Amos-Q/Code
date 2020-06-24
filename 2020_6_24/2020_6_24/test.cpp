#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	float t = 1.0;
	for (float i = 2; i <= 5; i++)
	{
		t += 1 / i;
	}
	cout << t;
	system("pause");
}