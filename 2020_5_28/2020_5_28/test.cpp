#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//void Print(string& str,string out)
//{
//	for(int i = 0;i<out.size();i++)
//	{
//		for (int j = 0; j < str.size(); j++)
//		{
//			if (str[j] == out[i])
//			{
//				str.erase(j);
//			}
//		}
//	}
//}
//
//int main()
//{
//	string str;
//	string out;
//	cin >> str;
//	cout << endl;
//	cin >> out;
//	cout << endl;
//	Print(str,out);
//	cout << str << endl;
//	return 0;
//}
//
//class Solution {
//public:
//	string reverseStr(string s, int k) {
//		if (k > 1 && s.size() > 1)
//		{
//			if (s.size() <= k)
//			{
//				reverse(s.begin(), s.end());
//				return s;
//			}
//			reverse(s.begin(), s.begin() + k);
//			int i = k;
//			int j = 2 * k;
//			while (i < s.size())
//			{
//				if (i == j)
//				{
//					int t = 0;
//					int b = i;
//					while (b < s.size() && t < k)
//					{
//						b++;
//						t++;
//					}
//					reverse(s.begin() + i, s.begin() + i + t);
//					i = b;
//					j += 2 * k;
//				}
//				i++;
//			}
//		}
//		return s;
//	}
//};


