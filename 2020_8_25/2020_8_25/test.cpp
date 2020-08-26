#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//void Change(string s, vector<vector<int>> vv)
//{
//	for (int i = 0; i < s.size(); i++)
//	{
//		while (1)
//		{
//			int flag = 0;
//			for (int j = 0; j < vv.size(); j++)
//			{
//				if ((s[i] - '0') == vv[j][0])
//				{
//					flag = 1;
//					s[i] = vv[j][1] + '0';
//				}
//			}
//			if (flag == 0)
//				break;
//		}
//	}
//	cout << s << endl;
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//	
//		int n;
//		cin >> n;
//		vector<vector<int>> vv(n,vector<int>(2));
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				cin >> vv[i][j];
//			}
//		}
//		Change(s, vv);
//	
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Sum(vector<int> v)
{
	sort(v.begin(), v.end());
	int cout = 0;
	int tmp = 0;
	int begin = v[0];
	for (int i = v.size() - 1; i > 0; i--)
	{
		v[i] += (v[0] - begin);
		tmp = v[i] - v[0];
		cout += tmp;
		v[0] += tmp;
	}
	cout << cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	Sum(v);
}