// #define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//void Print(string s)
//{
//	int i = 0;
//	int flag = 0;
//	int sum = 0;
//	string tmp;
//	vector<int> v;
//	while (i < s.size())
//	{
//		sum = 0;
//		while (i < s.size() && s[i] != ' ')
//		{
//			sum++;
//			tmp += s[i];
//			i++;
//		}
//		v.push_back(sum);
//		i++;
//		if (i < s.size() && s[i] == '"')
//		{
//			sum = 0;
//			i++;
//			while (i < s.size() && s[i] != '"')
//			{
//				sum++;
//				tmp += s[i];
//				i++;
//			}
//			v.push_back(sum);
//			i++;
//		}
//	}
//	cout << v.size() << endl;
//	int tt = 0;
//	for (int j = 0; j < v.size(); j++)
//	{
//		while (v[j] > 0)
//		{
//			cout << tmp[tt];
//			tt++;
//			v[j]--;
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	Print(str);
//	system("pause");
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;

int Appnum(int a)
{
	int max = 0;
	for (int i = 1; i < a; i++)
		if (a % i == 0)
			if (i > max)
				max = i;
	return max;
}

void Sum(int n,int m)
{
	int sum = 0;
	int maxapp = Appnum(n);
	while ((m - n) > maxapp)
	{
		n += maxapp;
		maxapp = Appnum(n);
		sum++;
	}

	if (n % (m - n) == 0)
		cout << sum + 1;
	else
		cout << -1;
}

int main()
{
	int N = 0;
	int M = 0;
	cin >> N >> M;
	Sum(N, M);
	system("pause");
	return 0;
}