#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void test1(int(*p)[5], int n, int m)
{
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)
		{
			p[i][j];
		}
	}
}
// test1 等价于test2
void test2(int p[][5], int n, int m)  //常用
{

}

void test3(int* p[5], int n, int m)
{

}
// test3等价于test4 都不行
void test4(int** p, int n, int m)
{

}

int main()
{
	// [][][][][]
	// [][][][][]
	// [][][][][]
	int arr[3][5] = { 0 };
	test1(arr, 3, 5);
	test2(arr, 3, 5);
	//test3(arr, 3, 5);

	//printf("%d\n", sizeof(arr)); // sizeof(数组名) 数组的大小
	//test1(arr, 3, 5);
	//printf("%d\n", sizeof(arr)); // sizeof(数组名) 数组的大小
	//printf("%d\n", sizeof(arr+1)); // 首元素的地址 arr类型-> int(*)[5]
	//printf("%p\n", arr); // 二维数组的首元素是第一行
	//printf("%p\n", arr+1);

	// arr[2][3] 等价于 *(*(arr+2)+3) 
	// arr[2] 等价于  *(arr+2)

	printf("%d\n", sizeof(arr[2])); // arr[2]代表第3行数组名 arr[2] 的类型是什么? -> int*
	printf("%d\n", sizeof(arr[2] + 1));
	printf("%p\n", arr[2]);
	printf("%p\n", arr[2] + 1);

	printf("%p\n", &arr[2]); // int(*)[5]
	printf("%p\n", &arr[2] + 1);

}