#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//void Findnumberof1(int n)
//{
//	int num = 0;
//	while (n > 0)
//	{
//		if (n & 1 == 1)
//			num++;
//		n >>= 1;
//	}
//	cout << num << endl;
//}
//
//int main()
//{
//	int N = 0;
//	while (cin >> N)
//		Findnumberof1(N);
//}


//int findMinimum(int n, vector<int> left, vector<int> right) {
//	int suml = 0;
//	int minl = 99999;
//	int sumr = 0;
//	int minr = 99999;
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		if (left[i] * right[i] == 0)
//			sum += left[i] + right[i];
//		else {
//			suml += left[i];
//			sumr += right[i];
//			if (left[i] < minl)
//				minl = left[i];
//			if (right[i] < minr)
//				minr = right[i];
//		}
//	}
//	if (suml - minl < sumr - minr)
//		return sum + suml - minl + 2;
//	else
//		return sum + sumr - minr + 2;
//}