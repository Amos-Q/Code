#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
using namespace std;

double power(double a, int b)
{
	int i;
	double result = 1.0;
	for (i = 0; i < b; i++)
		result = result * a;
	return result;
}
void main()
{
	double r;
	int n;
	cout << "r = ";
	cin >> r;
	cout << "n = ";
	cin >> n;
	cout << r << "µÄ" << n << "´ÎÃÝÊÇ£º" << power(r, n) << endl;
}