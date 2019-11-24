#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a = 1;

int main()
{
	int a = 0;
	printf("%d\n", a);
	printf("%d\n", ::a);

	return 0;
}
struct A
{
	int a1;
	int a2;
};

enum Colour
{
	RED,
	BLACK,
};

int main()
{
	struct A a;
	enum Colour col1 = RED;
	int col2 = RED;

	col1 = 3;
	col2 = 3;

	char p[] = "hello";
	strlen(p);
	strlen(*p);


	return 0;
}

int main()
{
	char* p = (char*)malloc(1024*1024*1024);

	return 0;
}

int main()
{
	int a = 0;
	int* p = (int*)malloc(sizeof(int));

	printf("Õ»:%p\n", &a);
	printf("¶Ñ:%p\n", p);

	return 0;
}
