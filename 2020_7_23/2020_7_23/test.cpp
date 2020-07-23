#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int flag = 0;
//		string tmp;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == '_')
//			{
//				flag = 1;
//				continue;
//			}
//			else
//			{
//				if (flag == 1)
//				{
//					tmp += (str[i] - 32);
//					flag = 0;
//				}
//				else
//					tmp += str[i];
//			}
//		}
//		cout << tmp << endl;
//	}
//}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
			{
				str[i] = ' ';
			}
		}
		while (str[0] == ' ')
			str.erase(str.begin());
		while (str[str.size() - 1] == ' ')
			str.erase(str.end() - 1);
		reverse(str.begin(), str.end());
		int begin = 0;
		for (int i = 0; i <= str.size(); i++)
		{
			if (str[i] == ' ' || str[i] == '\0')
			{
				reverse(str.begin() + begin, str.begin() + i);
				begin = i + 1;
			}
		}
		cout << str << endl;
	}
}