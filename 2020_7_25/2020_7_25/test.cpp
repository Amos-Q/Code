#define _CRT_SECURE_NO_WARNINGS 1
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		int sum = 0;
//		sort(numbers.begin(), numbers.end());
//		int middle = numbers[numbers.size() / 2];
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			if (numbers[i] == middle)
//				sum++;
//		}
//		if (sum > numbers.size() / 2)
//			return middle;
//		else
//			return 0;
//	}
//};

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> s;
vector<int> num;
string str;

void Print()
{
	for (int i = 0; i < s.size(); i++)
	{
		int max = 0;
		int maxadd = 0;
		int j = 0;
		for (j = i; j < s.size(); j++)
		{
			if (num[j] > max)
			{
				max = num[j];
				maxadd = j;
			}
		}
		swap(s[i], s[maxadd]);
		swap(num[i], num[maxadd]);
	}
	for (int i = 0; i < 8; i++)
	{
		cout << s[i] << ' ' << num[i] << endl;
	}
}

void Sum()
{
	int i = str.size() - 1;
	while (i >= 0)
	{
		string tmp;
		if (s.empty())
		{
			for (; i >= 0; i--)
			{
				if (str[i] == '\\')
					break;
				else
					tmp += str[i];
			}
			reverse(tmp.begin(), tmp.end());
			s.push_back(tmp);
			num.push_back(1);
		}
		else
		{
			int flag = 0;
			for (; i >= 0; i--)
			{
				if (str[i] == '\\')
					break;
				else
					tmp += str[i];
			}
			reverse(tmp.begin(), tmp.end());
			for (int j = 0; j < s.size(); j++)
			{
				if (tmp == s[j])
				{
					num[j]++;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				s.push_back(tmp);
				num.push_back(1);
			}
		}
		while (i >= 0 && str[i] != ' ')
			i--;
		i--;
	}
}


int main()
{
	while (getline(cin, str))
	{
		Sum();
		Print();
		s.clear();
		num.clear();
	}
}