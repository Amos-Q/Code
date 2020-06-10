#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int addAB(int A, int B) 
{
	if (B == 0)
		return A;
	int sum = A ^ B;
	int carry = (A&B) << 1;
	return addAB(sum, carry);
}

int main()
{
	cout << addAB(6,3);
	system("pause");
	return 0;
}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int Num(int a, int b)
//{
//	if (a == 0 && b == 0)
//		return 0;
//	if (a == 0 || b == 0)
//		return 1;
//	return Num(a - 1, b) || Num(a, b - 1);
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	cin >> n >> m;
//	cout << Num(n, m);
//	return 0;
//}