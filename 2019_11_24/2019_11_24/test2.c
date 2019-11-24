#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetMemory(char **p)
{
	*p = (char *)malloc(100);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
}

void Test(void)
{
	char *str = (char *)malloc(100);
	strcpy(str, "hello");
	free(str);
	str = NULL;
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

typedef struct st_type
{
	int i;
	int a[];//柔性数组成员
}type_a;

typedef struct contact
{
	char name[20];
	// ..
}Contact, *pContact;
// 等价于
struct contact
{
	char name[20];
	// ..
};

typedef struct contact Contact;
typedef struct contact* pContact;


struct contact
{
	char name[20];
	// ..
}Contact, *pContact;

int main()
{
	//Test();
	printf("%d\n", sizeof(struct st_type));
	struct st_type* p = (struct st_type*)malloc(sizeof(struct st_type) + sizeof(int)*100);
	p->i = 10;
	p->a[0] = 0;
	p->a[99] = 99;

	return 0;
}

int main()
{
	FILE* fout = fopen("D:\\课堂代码\\65班\\11-21\\11-21\\test.c", "r");
	char ch = fgetc(fout);
	while (ch != EOF)
	{
		printf("%c", ch);
		ch = fgetc(fout);
	}

	getchar();

	return 0;
}