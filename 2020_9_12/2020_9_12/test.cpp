#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//void FP(vector<vector<string>> &vv)
//{
//	int time = 1;
//	for (int i = 0; i < vv.size(); i++)
//	{
//		time *= vv[i].size();
//	}
//	vector<string> out(time);
//	int r = 0;
//	int l = 0;
//	time = 1;
//	for (int len = 0; len < vv.size(); len++)
//	{
//		int c = 0;
//		int flag = 0;
//		int i = 0;
//		while(i < out.size())
//		{
//			for (int j = 0; j < time; j++)
//			{
//				out[i] += vv[l][r];
//				i++;
//			}
//			r++;
//			r %= vv[l].size();
//		}
//		if (len == vv.size() - 1)
//			break;
//		for (i = 0; i < out.size(); i++)
//		{
//			out[i] += '-';
//		}
//		l++;
//		r = 0;
//		time *= vv[len].size();
//	}
//	for (int i = 0; i < out.size(); i++)
//	{
//		cout << out[i] << endl;
//	}
//}
//
//
//void TZ(vector<string> &v, vector<vector<string>> &vv, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		for (int j = 0; j < v[i].size(); j++)
//		{
//			if (v[i][j] != ' ')
//				s += v[i][j];
//			else
//			{
//				vv[i].push_back(s);
//				s.clear();
//			}
//		}
//		if (!s.empty())
//			vv[i].push_back(s);
//	}
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> v(n);
//		getchar();
//		for (int i = 0; i < n; i++)
//		{
//			getline(cin, v[i]);
//		}
//		vector<vector<string>> vv(n);
//		TZ(v, vv, n);
//		FP(vv);
//	}
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//bool Judge(vector<vector<int>> &vv,int l, int r)
//{
//	if (vv[l][0] == -1 && vv[l][1] == -1)
//		if (vv[r][0] == -1 && vv[r][1] == -1)
//			return true;
//	return false;
//}
//
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		vector<vector<int>> vv(m+1, vector<int>(2, -1));
//		string s;
//		int x;
//		int cont = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				cin >> x;
//				cin >> s;
//				if (s == "left")
//					cin >> vv[x][0];
//				if (s == "right")
//					cin >> vv[x][1];
//			}
//		}
//		for (int i = 0; i < vv.size(); i++)
//		{
//			if (vv[i][0] == -1 || vv[i][1] == -1)
//				continue;
//			else
//			{
//				if (Judge(vv,vv[i][0], vv[i][1]))
//					cont++;
//			}
//		}
//		cout << cont << endl;
//	}
//}


#include <iostream>
#include <vector>
using namespace std;

void get(vector<int> arr, int len, int loc, vector<vector<int>> &res,vector<int> v)
{
	if (loc == len) {
		res.push_back(v);
		return;
	}
	get(arr, len, loc + 1, res,v);
	v.push_back(arr[loc]);
	get(arr, len, loc + 1, res, v);
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(n);
		int sum = 0;
		int max = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		vector<int> v;
		vector<vector<int>> res;
		for (int i = 0; i < n; i++) 
		{
			get(arr, n, i + 1, res,v);
		}
		for (int i = 0; i < res.size(); i++)
		{
			sum = 0;
			for (int j = 0; j < res[i].size(); j++)
			{
				sum += res[i][j];
			}
			if (sum & 7 == 0)
				if (sum > max)
					max = sum;
		}
		cout << max << endl;
	}
}