#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int a[3][4] = { 0 }; // 12
//	printf("%d\n", sizeof(a)); // 12*4
//	printf("%d\n", sizeof(a[0][0])); // 4
//	printf("%d\n", sizeof(a[0])); // 4*4
//	printf("%d\n", sizeof(a[0] + 1)); //  4
//	printf("%d\n", sizeof(*(a[0] + 1))); // 4
//	printf("%d\n", sizeof(a + 1)); // 4
//	printf("%d\n", sizeof(*(a + 1))); // 16
//	printf("%d\n", sizeof(&a[0] + 1)); // 4
//	printf("%d\n", sizeof(*(&a[0] + 1))); // 16
//	printf("%d\n", sizeof(*a)); // 16
//	printf("%d\n", sizeof(a[3])); // 16
//
//	return 0;
//}
#include <assert.h>

int my_strlen(const char* str)
{
	assert(str != NULL);

	int len = 0;
	while (*str != '\0')
	{
		++len;
		++str;
	}

	return len;
}

int main()
{
	//char* p1 = "hello world";
	//printf("%d\n", strlen(p1));

	//char p2[] = "hello world";
	//p2[5] = '0';
	//p2[5] = '\0';
	//printf("%d\n", strlen(p2));

	char p2[] = "hello\\\0world";
	printf("%d\n", my_strlen(p2));
	printf("%d\n", sizeof(p2));


	return 0;
}
#include <string.h>

char* my_strcpy(char* dst, const char* src)
{
	assert(dst != NULL);
	assert(src != NULL);

	char* ret = dst;

	//while (*src != '\0')
	while (*src)
	{
		*dst = *src;
		++src;
		++dst;
	}

	*dst = '\0';

	return ret;
}


char* my_strcpy(char* dst, const char* src)
{
	assert(dst != NULL);
	assert(src != NULL);

	char* ret = dst;

	// 0 '0' '\0'
	while (*dst++ = *src++);

	return ret;
}

//const char*  -> char*
//char*  -> const char*

int main()
{
	char p1[] = "hello111";
	char p2[20];
	char p3[20];

	// i = j = k
	my_strcpy(p3, my_strcpy(p2, p1));
	printf("%s\n", p2);
	printf("%s\n", p3);


	//char* p1 = NULL;
	//const char* p2 = NULL;
	//p1 = p2; //²»ÐÐ
	//p2 = p1; //ÐÐ

	return 0;
}