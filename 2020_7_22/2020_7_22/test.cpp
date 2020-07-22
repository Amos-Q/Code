//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//vector<vector<char>> vv;
//
//void Set()
//{
//	vector<char> v(4);
//	vv.push_back(v);
//	vv.push_back(v);
//	v[0] = 'A';
//	v[1] = 'B';
//	v[2] = 'C';
//	vv.push_back(v);
//	v[0] = 'D';
//	v[1] = 'E';
//	v[2] = 'F';
//	vv.push_back(v);
//	v[0] = 'G';
//	v[1] = 'H';
//	v[2] = 'I';
//	vv.push_back(v);
//	v[0] = 'J';
//	v[1] = 'K';
//	v[2] = 'L';
//	vv.push_back(v);
//	v[0] = 'M';
//	v[1] = 'N';
//	v[2] = 'O';
//	vv.push_back(v);
//	v[0] = 'P';
//	v[1] = 'Q';
//	v[2] = 'R';
//	v[3] = 'S';
//	vv.push_back(v);
//	v[0] = 'T';
//	v[1] = 'U';
//	v[2] = 'V';
//	vv.push_back(v);
//	v[0] = 'W';
//	v[1] = 'X';
//	v[2] = 'Y';
//	v[3] = 'Z';
//	vv.push_back(v);
//}
//
//void Sort(vector<string> tel)
//{
//	sort(tel.begin(), tel.end());
//	for (int i = 0; i < tel.size() - 1; i++)
//	{
//		if (tel[i] == tel[i + 1])
//		{
//			tel.erase(tel.begin() + i + 1);
//			i--;
//		}
//	}
//	for (int i = 0; i < tel.size(); i++)
//	{
//		for (int j = 0; j < tel[i].size(); j++)
//		{
//			if (j == 3)
//				cout << '-';
//			cout << tel[i][j];
//		}
//		cout << endl;
//	}
//}
//
//char Find(char c)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (vv[i][j] == c)
//				return i + '0';
//		}
//	}
//}
//
//void Judge(vector<string> v)
//{
//	vector<string> tel;
//	for (int i = 0; i < v.size(); i++)
//	{
//		string tmp;
//		for (int j = 0; j < v[i].size(); j++)
//		{
//			if (v[i][j] >= '0'&&v[i][j] <= '9')
//			{
//				tmp += v[i][j];
//			}
//			else if (v[i][j] == '-')
//				continue;
//			else
//			{
//				tmp += Find(v[i][j]);
//			}
//		}
//		tel.push_back(tmp);
//		tmp.clear();
//	}
//	Sort(tel);
//}
//
//int main()
//{
//	int n;
//	Set();
//	while (cin >> n)
//	{
//		vector<string> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//		Judge(v);
//		cout << endl;
//	}
//}


#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) {
	//if (beg>n) return;
	if (m == 0) {
		for (int i = 0; i < v.size(); i++) {
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n && i <= m; i++) {
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>v;
		help(n, m, v, 1);
	}
}