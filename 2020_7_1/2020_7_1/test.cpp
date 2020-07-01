#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Judge(double n, double r)
{
	if (n > 6.28*r)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}

int main()
{
	double n = 0;
	double r = 0;
	while (cin >> n >> r)
	{
		Judge(n, r);
	}
}
