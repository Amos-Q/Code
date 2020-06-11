#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//void Degree(string s)
//{
//	int sum = 0;
//	int strmax = 0;
//	int strmin = 0;
//	int strnum = 0;
//	int strchar = 0;
//	if (s.size() <= 4)
//		sum += 5;
//	else if (5 <= s.size() && s.size() <= 7)
//		sum += 10;
//	else if (s.size() >= 8)
//		sum += 25;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if ('A' <= s[i] && s[i] <= 'Z')
//			strmax++;
//		if ('a' <= s[i] && s[i] <= 'z')
//			strmin++;
//		if ('0' <= s[i] && s[i] <= '9')
//			strnum++;
//		if (('!' <= s[i] && s[i] <= '/') || (':' <= s[i] && s[i] <= '@') || ('[' <= s[i] && s[i] <= 96) || ('{' <= s[i] && s[i] <= 126))
//			strchar++;
//	}
//
//	if (strmax > 0)
//		sum += 10;
//	if (strmin > 0)
//		sum += 10;
//	if (strnum == 1)
//		sum += 10;
//	else if (strnum > 1)
//		sum += 20;
//	if (strchar == 1)
//		sum += 10;
//	else if (strchar > 1)
//		sum += 25;
//
//
//	if (strmax > 0 && strmin > 0 && strnum > 0 && strchar > 0)
//		sum += 5;
//	else if (((strmax > 0 && strmin == 0) || (strmin > 0 && strmax == 0)) && strnum > 0 && strchar > 0)
//		sum += 3;
//	else if (strnum > 0 && (strmin > 0 || strmax > 0))
//		sum += 2;
//
//
//	if (sum >= 90)
//		cout << "VERY_SECURE" << endl;
//	else if (sum >= 80)
//		cout << "SECURE" << endl;
//	else if (sum >= 70)
//		cout << "VERY_STRONG" << endl;
//	else if (sum >= 60)
//		cout << "STRONG" << endl;
//	else if (sum >= 50)
//		cout << "AVERAGE" << endl;
//	else if (sum >= 25)
//		cout << "WEAK" << endl;
//	else if (sum >= 0)
//		cout << "VERY_WEAK" << endl;
//}
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//		Degree(str);
//	system("pause");
//	return 0;
//}

//class Board {
//public:
//	bool checkWon(vector<vector<int> > board) {
//		// write code here
//		int len = board.size();
//		for (int i = 0; i < len; i++)
//		{
//			int sh = 0;
//			int ss = 0;
//			for (int j = 0; j < len; j++)
//			{
//				sh += board[i][j];
//				ss += board[j][i];
//			}
//			if (sh == len || ss == len)
//				return true;
//		}
//		int left = 0;
//		int right = 0;
//		for (int i = 0; i < len; i++)
//		{
//			left += board[i][i];
//			right += board[len - i - 1][len - i - 1];
//		}
//		if (left == len || right == len)
//			return true;
//		return false;
//	}
//};

#include <iostream>
using namespace std;

int main()
{
	cout << 2 && 0;
	system("pause");
}