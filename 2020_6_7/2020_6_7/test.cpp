#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Euclid(int a,int b)
//{
//	vector<vector<int>> v(a);
//	for (int i = 0; i < a; i++) 
//		v[i].resize(b);
//	int sum = 0;
//	for (int i = 0; i < a; i++)
//	{
//		for (int j = 0; j < b; j++)
//		{
//			if (v[i][j] == 0)
//			{
//				if ((i + 2) < a)
//					v[i + 2][j] = 1;
//				if ((j + 2) < b)
//					v[i][j + 2] = 1;
//				sum++;
//			}
//		}
//	}
//	cout << sum << endl;
//}
//int main()
//{
//	int W = 0;
//	int H = 0;
//	cin >> W >> H;
//	Euclid(W, H);
//	system("pause");
//	return 0;
//}