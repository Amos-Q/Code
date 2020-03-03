#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"


int main()
{

	int arr[10] = { 23, 56, 78, 9, 3, 4, 66, 88, 34, 25 };
	/*HeapCreate(&hp, arr, 10);
	HeapSort(arr, 10);*/
	PrintTopK(arr, 10, 3);
	system("pause");
	return 0;
}