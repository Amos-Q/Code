#define _CRT_SECURE_NO_WARNINGS 1
//�ַ����Ľ���

#include <stdio.h>
#include <string.h>

int main(void)
{
	int age = 0;
	int money = 0;
	char buf[] = "aobma|45|10000000|X|";
	char name[32] = {};        //�����ĸ���������Ž�������ַ���
	char tmp[1024] = {};
	double sal[100] = {};
	char hun[10] = {};

	char* p = buf;
	char* q = strchr(p, '|');//strchr������������pָ��������в����ַ���|'

	int i = 0;
	while (p != q)
	{
		name[i++] = *p;
		p++;
	}
	name[i] = 0;          //0Ϊ'\0'
	printf("name=%s\n", name);

	q++;    //��qָ��'|'����һ���ַ���
	p = strchr(q, '|');    //��strchr��q�в���'|';
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

//�����ȡʮ�����֣���С��������

#include <stdio.h>

int main(void)
{
    srand(time(NULL));  //������������ӡ�

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

    for(i=0;i<10;i++)         //����
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