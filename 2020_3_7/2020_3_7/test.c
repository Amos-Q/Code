#define _CRT_SECURE_NO_WARNINGS 1
//字符串的解析

#include <stdio.h>
#include <string.h>

int main(void)
{
	int age = 0;
	int money = 0;
	char buf[] = "aobma|45|10000000|X|";
	char name[32] = {};        //以下四个数组来存放解析后的字符串
	char tmp[1024] = {};
	double sal[100] = {};
	char hun[10] = {};

	char* p = buf;
	char* q = strchr(p, '|');//strchr函数作用是在p指向的内容中查找字符’|'

	int i = 0;
	while (p != q)
	{
		name[i++] = *p;
		p++;
	}
	name[i] = 0;          //0为'\0'
	printf("name=%s\n", name);

	q++;    //让q指向'|'的下一个字符，
	p = strchr(q, '|');    //让strchr在q中查找'|';
	i = 0;
	while (q != p)
	{
		tmp[i++] = *q;
		q++;
	}
	tmp[i] = 0;

	i = 0;
	while (tmp[i] != 0)
	{
		age = age * 10 + (tmp[i] - '0');
		i++;
	}
	printf("age=%d\n", age);

	p++;
	q = strchr(p, '|');
	i = 0;
	while (q != p)
	{
		sal[i++] = *p;
		p++;
	}
	sal[i] = 0;

	i = 0;
	while (sal[i] != 0)
	{
		money = money * 10 + (sal[i] - '0');
		i++;
	}
	printf("money=%d\n", money);

	q++;
	p = strchr(q, '|');
	i = 0;
	while (p != q)
	{
		hun[i++] = *q;
		q++;
	}
	hun[i] = 0;

	printf("hun=%s\n", hun);

	return 0;
}

//随机读取十个数字，从小到大排序

#include <stdio.h>

int main(void)
{
    srand(time(NULL));  //产生随机数种子。

    int i;
    int j;
    int a[10]={0};

    for(i=0;i<10;i++)
    {
        a[i]=rand()%100+1;
    }

    printf("before:");
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    for(i=0;i<10;i++)         //排序
    {
        for(j=i;j<10;j++)
        {
            if(a[i]>a[j])
            {
                int tmp = a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    printf("after:");
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}