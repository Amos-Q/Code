#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>

using namespace std;
//namespace f
//{
//	void fx()
//	{
//		::printf("\n");
//	}
//}
////using namespace f;
//using f::fx;
//
//int main()
//{
//	fx();
//	printf("\n");
//}
//
//using namespace std;
//int main()
//{
//	cout << "\n" << endl;
//	cout << ",";
//}
//
//void f(int a = 0)
//{
//	cout << a;
//}
//
//void f2(int a,int b =10)
//{
//	cout << a;
//}
//
//int main()
//{
//	f(1);
//	f2(1);
//	system("pause");
//	return 0;
//}

//
//int add(int left, int right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int r = add(1, 2);
//	cout << r;
//	return 0;
//}
//
//int main()
//{
//	const int i = 1;
//	int x = i;
//	const int q = x;
//}
int count1()
{
	int l;
	int r;
	return l + r;
}

int& count2()
{
	int l = 1;
	int r = 0;
	return  r;
}

int main()
{
	const int& r = count1();
	int& r2 = count2();
}

