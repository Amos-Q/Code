#define _CRT_SECURE_NO_WARNINGS 1
struct student

{

	int num;

	char *name;

	char sex;

	int age;

}stu[5] = { {1001,”lihua”,’F’,18},{1002,”liuxing”,’M’,19},{1003,”huangke”,’F’,19},{1004,”fengshou”,’F’,19},{1005,”Wangming”,’M’,18} };

main()

{
	int i;

	struct student *ps;

	printf(“Num \tName\t\t\tSex\tAge\t\n”);

	/*用指针变量输出结构体数组元素。*/

	for (ps = stu; ps < stu + 5; ps++)

		printf(“%d\t%-10s\t\t%c\t%d\t\n”, ps->num, ps->name, ps->sex, ps->age);

	/*用数组下标法输出结构体数组元素学号和年龄。*/

	for (i = 0; i < 5; i++)

		printf(“%d\t%d\t\n”, stu[i].num, stu[i].age);

}

#define NULL 0

struct student

{

	int num;

	char *name;

	int age;

	struct student*next;

};

void main()

{

	struct studenta, b, c, *head, *p;

	a.num = 1001; a.name = ”lihua”; a.age = 18; /* 对结点成员进行赋值 */

	b.num = 1002; b.name = ”liuxing”; b.age = 19;

	c.num = 1003; c.name = ”huangke”; c.age = 18;

	head = &a; /* 建立链表，a为头结点 */

	a.next = &b;

	b.next = &c;

	c.next = NULL;

	p = head; /* 输出链表 */

	do {

		printf(“ % 5d, %s, % 3d\n”, p->num, p->name, p->age);

		p = p->next;

	} while (p != NULL);

}

#include<stdio.h>

#include<string.h>

#include<string.h>

main()

{
	char s[100];

	int i, j, n;

	printf(“输入字符串：\n”);

	gets(s);

	n = strlen(s);

	for (i = 0, j = n - 1; i < j; i++, j–)

		if (s[i] != s[j]) break;

	if (i >= j) printf(“是回文串\n”);

	else printf(“不是回文串\n”);

}



void fun(inta[], int n)

{
	int i, j, t;

	for (i = 0; i <= n - 1; i++)

		for (j = 0; j < i; j++)

			if (a[j] > a[j + 1]) { t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }

}

main()

{
	inta[10] = { 12,45,7,8,96,4,10,48,2,46 }, n = 10, i;

	FILE *f;

	if ((f = fopen(“myf2.out”, ”w”)) == NULL)

		printf(“open file myf2.outfailed!\n”);

	fun(a, 10);

	for (i = 0; i < 10; i++)

	{
		printf(“ % 4d”, a[i]);

		fprintf(f, ” % 4d”, a[i]);

	}

	fclose(f);

}


#include<stdio.h>

doublecountpi(double eps) /*eps为允许误差*/

{

	int m = 1;

	double temp = 1.0, s = 0;

	while (temp >= eps)

	{
		s += temp;

		temp = temp * m / (2 * m + 1);

		m++;

	}

	return(2 * s);

}

main()

{
	FILE *fp;

	double eps = 1e-5, pi;

	if ((fp = fopen(“p7_3.out”, ”w”)) == NULL)

	{
		printf(“cannot open thefile\n”);

		exit(0);

	}

	pi = countpi(eps);

	printf(“pi = %lf\n”, pi);

	fprintf(fp, ”pi = %lf\n”, pi);

	fclose(fp);

}