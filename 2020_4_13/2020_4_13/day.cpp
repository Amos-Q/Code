#define _CRT_SECURE_NO_WARNINGS 1

#include "day.h"

int main()
{
	Date d1(2020, 4, 11);
	d1.Print();

	Date d2(2020, 2, 29);
	d2.Print();

	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 >= d2) << endl;

	// 是否要重载一个运算符，看的是这个运算符是否对这个类的对象有意义
	Date d4 = d1 + 10000;
	d4.Print();
	Date d5 = d1 += 10000;
	d5.Print();

	/*d1 += 10;
	d1 - 10;
	d1 -= 10;
	d1 - d2;
	d1++;
	d1--;*/
	system("pause");
	return 0;
}