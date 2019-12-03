#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int* addToArrayForm(int* A, int ASize, int K)
{
		int length = ASize - 1;
		int sum = 0;
		int tmp = 0;
		int i = 0;
		int* res = (int*)malloc(sizeof(int)*(ASize + 5));
		for (i = 0; i < ASize; i++)
		{
			sum += A[i] * pow(10, length);
			length--;
		}
		sum += K;
		length = 0;
		while (sum >= 10)
		{
			res[length] = sum % 10;
			length++;
			sum /= 10;
		}
		res[length] = sum;
		for (i = 0, length; i <= length; i++, length--)
		{
			tmp = res[length];
			res[length] = res[i];
			res[i] = tmp;
		}
		return res;
}
int main()
{
	int A[4] = { 9,9,9,9 };
	addToArrayForm(A, 4, 1);
}