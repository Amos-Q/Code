#define _CRT_SECURE_NO_WARNINGS 1

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<time.h>
using namespace::std;
#define N 50000+1
void PushDown(int first, int n);
void Swap(int &a, int &b);
int A[N];
int main()
{
	int opr;
	ifstream in;
	ofstream out;
	/*in.open("C:\\Users\\asus\\Documents\\Visual Studio 2017\\Projects\\teat\\666.txt");
	if (in.fail())
		cout << "ERROR!" << endl;
	else
	{
		for (int opt = 1; opt <N; opt++)
		{
			in >> A[opt];
		}
	}*/
	srand((unsigned)time(NULL));//设置随机数种子
	for (int i = 1; i < N; i++)
	{
		A[i] = (rand() % (N - 1) + 1);//生成随机数
	}
	out.open("C:\\Users\\asus\\Documents\\Visual Studio 2017\\Projects\\teat\\output.txt");
	if (out.fail())
		cout << "ERROR!" << endl;
	clock_t start = clock();
	//建最小堆
	for (opr = (N - 1) / 2; opr >= 1; opr--)
	{
		PushDown(opr, N - 1);
	}
	//排序输出
	for (int t = N - 1; t >= 2; t--)
	{
		Swap(A[1], A[t]);
		PushDown(1, t - 1);
	}
	clock_t end = clock();
	for (int p = N - 1; p >= 1; p--)
	{
		out << A[p] << "   ";

	}
	cout << "time is" << (double)(end - start);//计算运行时间
	return 0;
}
void PushDown(int first, int n)
{
	int temp = first;
	while (temp <= n / 2)
	{
		if ((temp == n / 2) && (n % 2 == 0))
		{
			if (A[temp] > A[2 * temp])
			{
				Swap(A[temp], A[2 * temp]);
			}
			temp = n;//exit cycle！！！
		}
		else if ((A[temp] > A[2 * temp]) && (A[2 * temp] <= A[temp * 2 + 1]))
		{
			Swap(A[temp], A[2 * temp]);
			temp = 2 * temp;
		}
		else if ((A[temp] > A[2 * temp + 1]) && (A[2 * temp + 1] < A[2 * temp]))
		{
			Swap(A[temp], A[temp * 2 + 1]);
			temp = temp * 2 + 1;
		}
		else
			temp = n;
	}
}
void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}