#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int>& Yh_triangle(vector<int> & yh, int n)
//{
//	if (n == 1)
//	{
//		yh.push_back(1);
//		return yh;
//	}
//	vector<int> lyh;
//	lyh.push_back(1);
//	lyh.push_back(1);
//	yh = lyh;
//	n -= 1;
//	while (--n)
//	{
//		for (int i = 0; i < lyh.size(); i++)
//		{
//			if (i == 0)
//				yh[i] = lyh[i] + 2 * lyh[i + 1];
//			else if (i == lyh.size() - 1)
//				yh[i] = lyh[i - 1] + lyh[i];
//			else
//				yh[i] = lyh[i - 1] + lyh[i] + lyh[i + 1];
//		}
//		yh.push_back(1);
//		lyh = yh;
//	}
//	reverse(yh.begin(), yh.end());
//	for (int i = yh.size() - 2; i >= 0; i--)
//	{
//		yh.push_back(yh[i]);
//	}
//	return yh;
//}
//
//int Count(int n)
//{
//	vector<int> yh;
//	yh.resize(2);
//	yh = Yh_triangle(yh, n);
//	for (int i = 0; i < yh.size(); i++)
//	{
//		if (yh[i] % 2 == 0)
//			return i + 1;
//	}
//	return -1;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//		cout << Count(n) << endl;
//	system("pause");
//	return 0;
//}

//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//void Add(string s1, string s2)
//{
//	int begin1 = s1.size() - 1;
//	int begin2 = s2.size() - 1;
//	string add;
//	int flag = 0;
//	int sum = 0;
//	while (begin1 >= 0 && begin2 >= 0)
//	{
//		sum = s1[begin1] - '0' + s2[begin2] - '0';
//		if (flag == 1)
//		{
//			sum += 1;
//			flag = 0;
//		}
//		if (sum > 9)
//		{
//			flag = 1;
//			sum %= 10;
//		}
//		add.push_back(sum + '0');
//		begin1--;
//		begin2--;
//	}
//	while (begin1 >= 0)
//	{
//		sum = s1[begin1] - '0';
//		if (flag == 1)
//		{
//			sum += 1;
//			flag = 0;
//		}
//		if (sum > 9)
//		{
//			flag = 1;
//			sum %= 10;
//		}
//		add.push_back(sum + '0');
//		begin1--;
//	}
//	while (begin2 >= 0)
//	{
//		sum = s2[begin2] - '0';
//		if (flag == 1)
//		{
//			sum += 1;
//			flag = 0;
//		}
//		if (sum > 9)
//		{
//			flag = 1;
//			sum %= 10;
//		}
//		add.push_back(sum + '0');
//		begin2--;
//	}
//	if (flag == 1)
//		add.push_back('1');
//	reverse(add.begin(),add.end());
//	cout << add << endl;
//}
//
//int main()
//{
//	string s1;
//	string s2;
//	while(cin >> s1 >> s2)
//		Add(s1, s2);
//	system("pause");
//	return 0;
//}