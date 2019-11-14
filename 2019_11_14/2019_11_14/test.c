#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//
//char* my_strcat(char* dst, const char* src)
//{
//	assert(dst && dst);
//	char* ret = dst;
//
//	while (*dst != '\0')
//	{
//		++dst;
//	}
//
//	while (*dst++ = *src++);
//	//while (*src != '\0')
//	//{
//	//	*dst = *src;
//	//	++dst;
//	//	++src;
//	//}
//
//	//*dst = *src;
//
//	return ret;
//}
//
//int main()
//{
//	char* p1 = "hello";
//	char p2[12] = "world";
//	p2[10] = '1';
//
//	//strcpy(p2, p1);
//	my_strcat(p2, p1); // 追加 拼接
//
//	return 0;
//}
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	int ret = 0;
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//
//	while (*s1 && *s2)
//	{
//		if (*s1 > *s2)
//		{
//			return 1;
//		}
//		else if (*s1 < *s2)
//		{
//			return -1;
//		}
//		else
//		{
//			++s1;
//			++s2;
//		}
//	}
//
//	 "hello"  "hello"
//	 "hello"  "hello1"
//	 "hello1" "hello"
//	if (*s1 == '\0' && *s2 == '\0')
//	{
//		return 0;
//	}
//	else if (*s1 == '\0')
//	{
//		return -1;
//	}
//	else
//	{
//		return 1;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char p1[] = "我来了";
//	char* p2 = "hello1";
//
//	printf("%d\n", strcmp(p1, p2));
//	printf("%d\n", my_strcmp(p1, p2));
//
//	char p3[] = "想你";
//	p3[3] = -30;
//	p3[3] = -31;
//	p3[3] = -32;
//
//	return 0;
//}
//
//int main()
//{
//	//  int char char* char void*
//	//	0  '\0'  ""    '0'  NULL
//	char* p1 = "worldworld";
//	char p2[100] = "hello";
//	strncpy(p2, p1, 3);
//	printf("%s\n", p2);
//}
//
//
//	/*char* p1 = "worldworld";
//	char p2[100] = "hello";
//	strncat(p2, p1, 5);
//	printf("%s\n", p2);*/
//
//	//char* p1 = "helloworld";
//	//char* p2 = "hello";
//	//printf("%d\n", strncmp(p1, p2, 6));
//
//	return 0;
//}
//
//
//const char* my_strstr(const char* src, const char* sub)
//{
//	assert(src && sub);
//
//	const char* srci = src;
//	const char* subi = sub;
//
//	while (*srci != '\0')
//	{
//		while (*srci == *subi && *subi != '\0')
//		{
//			++srci;
//			++subi;
//		}
//
//		if (*subi == '\0')
//		{
//			return src;
//		}
//		else
//		{
//			subi = sub;
//			++src;
//			srci = src;
//		}
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	//char* p1 = "abcde";
//	//char* p2 = "cdeab";
//
//	//char p3[11]; // "abcdeabcde"
//	//strcpy(p3, p1);
//	//strcat(p3, p1);
//
//	//if (my_strstr(p3, p2) != NULL)
//	//{
//	//	printf("是旋转串\n");
//	//}
//	//else
//	//{
//	//	printf("不是旋转串\n");
//	//}
//
//	char* p1 = "aaaabcd";
//	char* p2 = "aaab";
//
//	char* pos = strstr(p1, p2);
//	printf("%s\n", pos);
//}
//
//
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>//必须包含的头文件
//
//int main()
//{
//	FILE * pFile;
//	pFile = fopen("unexist.ent", "r");
//	if (pFile == NULL)
//		printf("Error opening file unexist.ent: %s\n", strerror(errno));
//	//errno: Last error number
//	return 0;
//}
//
//struct Student
//{
//	char _name[10];
//	int  _age;
//};
//
//typedef unsigned int size_t;
//void* my_memcpy(void* dst, const void* src, size_t num)
//{
//	assert(dst && src);
//
//	char* str_dst = (char*)dst;
//	char* str_src = (char*)src;
//	for (size_t i = 0; i < num; ++i)
//	{
//		str_dst[i] = str_src[i]; // *(str_src+i)
//	}
//
//	return dst;
//}
//
//int main()
//{
//	int a1[10] = { 1, 2, 3, 4, 5 };
//	int a2[10];
//	my_memcpy(a2, a1, 10 * sizeof(int));
//
//	struct Student s1 = { "peter", 18 };
//	strcpy(s1._name,"peter");
//	s1._age = 18;
//
//	struct Student s2;
//	strcpy(s2._name, s1._name);
//	s2._age = s1._age;
//	my_memcpy(&s2, &s1, sizeof(struct Student));
//
//	return 0;
//}

void *MyMemmove(void * dst, const void * src, size_t num)
{
	assert(dst && src);
	void *ret = dst;
	char *str1 = (char*)dst;
	char *str2 = (char*)src;
	//if (str1 > str2)
	//{
		while (num--)
		{
			*(str1 + num) = *(str2 + num);//反向赋值
		}
	//}
///*	else
//	{
//		while (num--)
//		{
//			*str1++ = *str2++;
//		*/}
//	}
	return ret;
}

void* my_memcpy(void* dst, const void* src, size_t num)
{
	assert(dst && src);

	char* str_dst = (char*)dst;
	char* str_src = (char*)src;
	for (size_t i = 0; i < num; ++i)
	{
		str_dst[i] = str_src[i]; // *(str_src+i)
	}

	return dst;
}

int main()
{
	char str1[] = "Hello word";
	char* str2 = str1+6;
	printf("%s\n", str2);
	printf("%s\n", MyMemmove(str2, str1, 4));
	printf("%s", my_memcpy(str2, str1, 4));
	system("pause");
	return 0;
}