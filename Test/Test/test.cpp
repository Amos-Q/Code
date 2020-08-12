#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//#ifdef _________TEST________
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
//#endif _________TEST________
using namespace std;
//int Fun(char *s1, char s2)
//{
//	for (int i = 0; i < strlen(s1); i++)
//	{
//		if (s1[i] == s2)
//			return i + 1;
//	}
//	return -1;
//}
//
//int main()
//{
//	char str1[] = "dcabf";
//	char str2[] = "ab";
//	for (int i = 0; i < strlen(str2); i++)
//	{
//		printf("%c:%d\n", str2[i], Fun(str1, str2[i]));
//	}
//	return 0;
//}

//void Swap1(int *a,int *b)
//{
//	printf("Swap1(传地址)");
//	int tmp = 0;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void Swap(int a, int b)
//{
//	int tmp = 0;
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("Swap(传值)");
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	printf("a:%d  b:%d\n", a, b);
//	Swap1(&a, &b);
//	printf("a:%d  b:%d\n", a, b);
//	system("pause");
//	return 0;
//}


//int arrmax(int *arr, int n)
//{
//	int max = 0;
//	int maxarr = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//			maxarr = i;
//		}
//	}
//	return maxarr;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,7,84,7,8,9,0,55,3 };
//	int max = arrmax(arr, 12);
//	int t = arr[max];
//	arr[max] = arr[11];
//	arr[11] = t;
//	for (int i = 0; i < 12; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	//system("pause");
//	return 0;
//}

//string test(string && s)
//{
//	string s1 ("test");
//	return s1;
//}
//
//int main()
//{
//	//map<string,int> m;
//	//for (auto &e : m)
//	//{
//
//	//}
//	cout << test("test") << endl;
//	string  ss (test("test"));
//	system("pause");
//}

//int main()
//{
//	int a = 1;
//	int b = 2;
//	swap(a, b);
//	auto swapab = [&]()-> void{swap(a, b); };
//	swapab();
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	//char arr[] = "abcdef";
//	char arr[] = { 'a','b','c' };
//	//cout << sizeof(a) << endl;
//	//cout << sizeof(a + 0) << endl;
//	//cout << sizeof(*a) << endl;
//	//cout << (a + 1) << endl;
//	//cout << sizeof(a[1]) << endl;
//	//cout << sizeof(&a) << endl;
//	//cout << sizeof(*&a) << endl;
//	//cout << sizeof(a) << endl;
//	//cout << sizeof(&a + 1) << endl;
//	//cout << sizeof(&a[0]) << endl;
//	//cout << sizeof(&a[0] + 1) << endl;
//	//cout << &a << endl;
//	cout << sizeof(arr) << endl;
//	cout << strlen(arr) << endl;
//	//cout << strlen(&arr) << endl;
//	system("pause");
//}

//#include <stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(long double));
//	system("pause");
//	return 0;
//}

//int main()
//{
//	printf("%d\n", strlen("abcdef"));
//	// \32被解析成一个转义字符
//	printf("%s\n", "c:\test\328\test.c");
//	return 0;
//}
//void test()
//{
//	int i = 0;
//	i++;
//	printf("%d ", i);
//}
//int main()
//{
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;
//}
//代码2
//#include <stdio.h>
//void test()
//{
//	//static修饰局部变量
//	static int i = 0;
//	i++;
//	printf("%d ", i);
//}
//int main()
//{
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;
//}

//#define
//typedef
//default
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)
//	{
//		k++;
//		cout << 1 << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//void hanoi(int N, char source, char relay, char destination)
//{
//	if (N == 1)
//		cout << source << "-->" << destination << endl;
//	else
//	{
//		hanoi(N - 1, source, destination, relay);
//		cout << source << "-->" << destination << endl;
//		hanoi(N - 1, relay, source, destination);
//	}
//}
//
//int main()
//{
//	cout << "移动盘子：" << endl;
//	hanoi(5, 'A', 'B', 'C');
//
//	return 0;
//}

//
//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//(2)
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//(4)
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));//(1)
//	printf("%d\n", sizeof(ch));//(3)
//	test1(arr);
//	test2(ch);
//	return 0;
//}

//void Hanoi(int n, char A, char B, char C)
//{
//	if (n == 1)
//		cout << A << '-' << C << endl;
//	else
//	{
//		Hanoi(n - 1, A, C, B);
//		cout << A << '-' << C << endl;
//		Hanoi(n - 1, B, A, C);
//	}
//}
//
//int main()
//{
//	Hanoi(3, 'a', 'b', 'c');
//}

//
//int main()
//{
//	char str[] = "This is a simple string";
//	char * pch;
//	cout << strstr(str, "simple") << endl;
////	strncpy(pch, "sample", 6);
//	puts(str);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	const char *p = "zhangpengwei@bitedu.tech";
//	const char* sep = ".@";
//	char arr[30];
//	char *str = NULL;
//	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
//	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
//	{
//		printf("%s\n", str);
//	}
//}


//int main()
//{
//	char str[] = "memmove can be very useful......";
//	memcpy(str + 20, str + 15, 11);
//	puts(str);
//	//memmove(str + 20, str + 15, 11);
//	//puts(str);
//	return 0;
//}

//typedef struct
//{
//	int data;
//	Node* next;
//}Node;
//
//struct Node
//{
//	int data;
//	struct Node *next;
//};
////可行否？
//int main()
//{
//	cout << sizeof(struct Node) << endl;
//}

//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//enum Sex
//{
//	MAN=1,
//	WOMAN=2,
//};
//union UN
//{
//	char c;
//	int i;
//};
//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//int main()
//{
//	//输出的结果是什么？
//	//printf("%d\n", sizeof(struct S1));
//	//printf("%d\n", sizeof(struct S2));
//	//printf("%d\n", sizeof(struct A));
//	//printf("%d\n", sizeof(struct S));
//	//printf("%d\n", sizeof(enum Sex));
//	//enum Sex ss = MAN;
//	//union UN un;
//	// 下面输出的结果是一样的吗？
//	//printf("%d\n", &(un.i));
//	//printf("%d\n", &(un.c));
//	//下面输出的结果是什么？
//	//un.i = 0x11223344;
//	//un.c = 0x55;
//	//printf("%x\n", un.i);
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//	return 0;
//}


//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//char *GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//void Test(void)
//{
//	char *str = (char *)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//}

//struct S
//{
//	char a[15];
//	int i[2];
//};
//union un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//cout << sizeof(S) << endl;
//	un un;
//	//printf("%d\n", &(un.i));
//	//printf("%d\n", &(un.c));
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//}

int check_sys()
{
	union un
	{
		char c;
		int i;
	}num;
	num.i = 1;
	return num.c;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("本机为小端模式\n");
	}
	else
	{
		printf("本机为大端模式\n");
	}
	system("pause");
	return 0;
}