#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//void Dele(string s1, string s2)
//{
//	for (int i = 0; i < s2.size(); i++)
//	{
//		for (int j = 0; j < s1.size(); j++)
//		{
//			if (s1[j] == s2[i])
//			{
//				s1.erase(s1.begin() + j);
//				j--;
//			}
//		}
//	}
//	cout << s1 << endl;
//}
//
//int main()
//{
//	string s1, s2;
//	while (getline(cin,s1))
//	{
//		cin >> s2;
//		Dele(s1, s2);
//	}
//}

//#include <iostream>
//#include <vector>
//#include <limits.h>
//using namespace std;
//
//int main()
//{
//	int n;
//	int sum = 0;
//	int max = INT_MIN;
//	while (cin >> n)
//	{
//		vector<int> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//			sum += v[i];
//			if (sum > max) {
//				max = sum;
//			}
//			if (sum < 0) {
//				sum = 0;
//			}
//		}
//		cout << max << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//bool is24(vector<int> a, int tot, int result)
//{
//	if (a.empty())
//	{
//		return result == tot;
//	}
//	for (int i = 0; i < a.size(); i++)
//	{
//		vector<int> b(a);
//		b.erase(b.begin() + i);
//		if (is24(b, tot, result + a[i])
//			|| is24(b, tot, result - a[i])
//			|| is24(b, tot, result*a[i])
//			|| is24(b, tot, result / a[i]))
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	vector<int> a(4);
//	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
//	{
//		if (is24(a, 24, 0))
//			cout << "true" << endl;
//		else cout << "false" << endl;
//	}
//}



//class MaxGap {
//public:
//	int findMaxGap(vector<int> A, int n) {
//		// write code here
//		int max = INT_MIN;
//		int min = A[0] > A[n - 1] ? A[n - 1] : A[0];
//		for (int i = 0; i < n; i++)
//		{
//			if (A[i] > max)
//				max = A[i];
//		}
//		return max - min;
//	}
//};

#include <iostream>
#include <vector>
using namespace std;

void Print(vector<vector<int>> mat,int n,int m)
{
	// write code here
	vector<int> ret;
	int x1 = 0, y1 = 0;      //左上角坐标
	int x2 = n - 1, y2 = m - 1;  //右下角坐标
	while (x1 <= x2 && y1 <= y2) {
		for (int j = y1; j <= y2; ++j)
			ret.push_back(mat[x1][j]);
		for (int i = x1 + 1; i < x2; ++i)
			ret.push_back(mat[i][y2]);
		for (int j = y2; x1 < x2 && j >= y1; --j) //x1 < x2：只有在不是单一的横行时才执行这个循环
			ret.push_back(mat[x2][j]);
		for (int i = x2 - 1; y1 < y2 && i > x1; --i)//y1 < y2：只有在不是单一的竖列时才执行这个循环
			ret.push_back(mat[i][y1]);
		x1++; y1++;
		x2--; y2--;
	}
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << ' ';
	}
	cout << endl;
}

 int main()
 {
	 int n, m;
	 while (cin >> n >> m)
	 {
		 vector<vector<int>> mat(n, vector<int>(m));
		 for (int i = 0; i < n; i++)
		 {
			 for (int j = 0; j < m; j++)
			 {
				 cin >> mat[i][j];
			 }
		 }
		 Print(mat,n,m);
	 }
 }