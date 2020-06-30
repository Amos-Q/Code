#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//int Treeroot(long long n)
//{
//	while (n >= 10)
//	{
//		int sum = 0;
//		while (n >= 10)
//		{
//			sum += n % 10;
//			n /= 10;
//		}
//		sum += n;
//		n = sum;
//	}
//	return n;
//}
//
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//
//		int num = 0;
//		for (int i = 0; i < str.size(); ++i)
//			num += str[i] - '0';
//		cout << Treeroot(num) << endl;
//	}
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> Base()
{
	vector<vector<int>> vv;
	vector<int> base1;
	base1.push_back(1);
	base1.push_back(1);
	vv.push_back(base1);
	vector<int> base2;
	base2.push_back(1);
	base2.push_back(0);
	vv.push_back(base2);
	return vv;
}

void Cipher(vector<int> v)
{
	vector<int> p;
	for (int i = 0; i < v.size(); i++)
	{
		vector<vector<int>> vv1;
		vector<vector<int>> vv2;
		int sum = 0;
		vv1 = Base();
		vv2 = Base();
		int F = vv2[0][0];
		int S = vv2[0][1];
		int T = vv2[1][0];
		int T1 = vv2[1][1];
		for (int j = 1; j < v[i]; j++)
		{
			F = vv1[0][0] * vv2[0][0] + vv1[0][1] * vv2[1][0];
			S = vv1[0][0] * vv2[0][1] + vv1[0][1] * vv2[1][1];
			T = vv1[1][0] * vv2[0][0] + vv1[1][1] * vv2[1][0];
			T1 = vv1[1][0] * vv2[0][1] + vv1[1][1] * vv2[1][1];
			vv1[0][0] = F;
			vv1[0][1] = S;
			vv1[1][0] = T;
			vv1[1][1] = T1;
			if (F > 9999)
				break;
		}
		int ret = 0;
		for (int pp = 0; pp < 4; pp++)
		{
			if (F > 9)
			{
				ret = F % 10;
				p.push_back(ret);
			}
			else
				p.push_back(F);
			F /= 10;
		}
		reverse(p.begin() + 4 * i, p.begin() + 4 * (i + 1));
	}
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i];
	}
	cout << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int X = 0;
			cin >> X;
			v.push_back(X);
		}
		Cipher(v);
	}
	system("pause");
	return 0;
}


#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v = { 1, 1 };
	for (int i = 2; i < 10001; ++i) {
		v.push_back((v[i - 2] + v[i - 1]) % 10000);
	}
	int n, x;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			printf("%04d", v[x]);
		}
		cout << endl;
	}
	return 0;
}