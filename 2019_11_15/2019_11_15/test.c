#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct s1 {
	int a;
	int b;
	int *c;
};

struct s2 {
	struct s1 s3;
	struct s1 *s4;
};
//struct s1 s={1,2};
//子线程传一个结构体struct s2 类型，并处理。
void *func(void *arg)
{
	struct s2 *fun1;
	fun1 = arg;
	int number = fun1->s4->a;
	printf("number = %d\n", number);//输出a的值
}

int main()
{
	//struct s1 b={3,4};
	//struct s2 test = {{1,2},&b};
	//结构体1赋值
	struct s1 b;
	int k = 7;
	b.a = 3;
	b.b = 4;
	//b.c = &k;
	//结构体2赋值
	struct s2 test;
	test.s3.a = 1;
	test.s3.b = 2;
	//s4为指针，需要先声明才可使用
	test.s4 = (struct s1*)malloc(sizeof(struct s1));
	test.s4->a = 5;
	test.s4->b = 6;
	test.s4->c = &k;
	pthread_t fd;
	//创建子线程func，将test传入子线程。
	pthread_create(&fd, NULL, func, &test);
	printf("a = %d\n", test.s3.a);
	printf("b = %d\n", test.s3.b);
	printf("a = %d\n", test.s4->a);
	printf("b = %d\n", test.s4->b);
	printf("c = %d\n", *(test.s4->c));
	sleep(2);
	return 0;
}
