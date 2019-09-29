#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#include <time.h>
//
//void guess()
//{
//	int num = 0;
//	int g = 0;
//	printf("**************\n");
//	printf("*** 猜数字 ***\n");
//	printf("**************\n");
//	srand((unsigned)time(NULL));
//	num = rand() % 100 + 1;
//	while (1)
//	{
//		printf("猜数字:");
//		scanf("%d", &g);
//		if (num > g)
//			printf("猜小了\n");
//		else if (num < g)
//			printf("猜大了\n");
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int i = 0;
//	do
//	{
//		guess();
//		printf("*** 1-继续 *** 0-退出 ***\n");
//		scanf("%d", &i);
//		switch (i)
//		{
//		case 0: break;
//		case 1: ;
//		}
//	} while (i);
//	system("pause");
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	char a[10] = {0};
//	for(i=0; i<3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", a);
//		if(strcmp(a, "258369") == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if(i == 3)
//	{
//		printf("三次密码错误，退出程序\n");
//	}
//	system("pause");
//	return 0;
//}


//int search(int arr[], int a, int sz)
//{
//	int left = 0;
//	int right = sz-1;
//	while(left<=right)
//	{
//		int mid = (left+right)/2;
//		if(arr[mid] > a)
//		{
//			right = mid-1;
//		}
//		else if(arr[mid] < a)
//		{
//			left = mid+1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int a = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int ret = 0;
//	printf("输入查找数字:");
//	scanf("%d", &a);
//	ret = search(arr, a, sz);
//	if(ret == -1)
//	{
//		printf("很遗憾，找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	system("pause");
//	return 0;
//}




int main()
{
	char c;
	do
	{
		printf("请输入一个字母：");
		scanf("%c", &c);
		if (c >= 65 & c <= 90)
			printf("%c\n", c + 32);
		if (c >= 97 & c <= 122)
			printf("%c\n", c - 32);
		else
			continue;
	} while (1);
	system("pause");
	return 0;
}