#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include < iostream >
using namespace std;
char up(char c)
{

	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return c;
}
void main()
{
	int i;
	char c[15] = { 'A','v','e','t','E','T','%','&','4','Y','e','i','@','9','^' };
	for (i = 0; i < 15; i++)
		cout << up(c[i]) << ", ";
	cout << endl;
}

//#include < iostream >
//using namespace std;
//void print_triangle(char c, int n)
//{
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			cout << c;
//		}
//		cout << endl;
//	}
//}
//void main()
//{
//	print_triangle('a', 10);
//}