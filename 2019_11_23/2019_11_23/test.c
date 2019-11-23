#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <assert.h>

//char *my_strncpy(char *dst, const char *src, int n)
//{
//	assert(dst);
//	assert(src);
//	assert(n > 0);
//	char *cpy = dst;
//	while (n--)
//	{
//		*dst++ = *src++;
//	}
//	return cpy;
//
//}
//
//int main()
//{
//	char a[20] = "abcdefgh";
//	char *p = "1234";
//	int n = 0;
//	char *ret = my_strncpy(a, p, 5);
//	printf("ret: %s\n", ret);
//
//	system("pause");
//	return 0;
//}
//char *my_strncat(char *des, const char *src, int count)
//{
//	assert(des);
//	assert(src);
//	char *cat = des;
//	int i = 0;
//	while (*des != '\0')
//	{
//		des++;
//	}
//	for (; i < count; i++)
//	{
//		*des = *src;
//		des++;
//		*src++;
//	}
//	return cat;
//}
//
//int main()
//{
//	char a[10] = { 'a', 'b', 'c', '\0' };
//	char b[20] = "world and bit";
//	int n = 5;
//	char *ret = my_strncat(a, b, n);
//	printf("ret: %s\n", ret);
//	system("pause");
//	return 0;
//}


int my_strncmp(const char *str1, const char *str2, int n)
{
	assert(str1);
	assert(str2);
	assert(n > 0);
	const char *p = str1;
	const char *q = str2;
	while (*p != '\0' && *q != '\0' && (n--))
	{

		if (*p == *q)
		{
			p++;
			q++;

		}
		else if (*p > *q)
		{
			return 1;
		}
		else
		{
			return -1;
		}

	}
	if (*p != '\0')
	{
		return 1;

	}
	if (*q != '\0')
	{
		return -1;
	}
}
int main()
{
	char *p = "abcd1234";
	char *q = "abcd2345";
	int n = 5;
	int ret = my_strncmp(p, q, n);
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}
