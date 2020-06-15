#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	int i;
//	int flag = 0;
//	int a[26] = { 0 };
//	while (cin >> str)
//	{
//		flag = 0;
//		int sLength = str.length();
//		for (i = 0; i < sLength; i++)
//		{
//			a[str[i] - 'a']++;
//		}
//		for (i = 0; i < sLength; i++)
//		{
//			if (a[str[i] - 'a'] == 1)
//			{
//				flag = 1;
//				cout << str[i] << endl;
//				break;
//			}
//		}
//		if (flag == 0)
//			cout << -1 << endl;
//	}
//	system("pause");
//	return 0;
//}

#include "string.h"

int main()
{
	fxd::test_string1();
	system("pause");
	return 0;
}