#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
main()
{
    FILE *fp; /*定义一个指向FILE类型结构体的指针变量*/
    char filename1[20], filename2[20]; /*定义数组为字符型*/
    printf("please input the file name which do you want to change:\n");
    scanf("%s", filename1); /*输入要重命名的文件所在的路径及名称*/
    if ((fp = fopen(filename1, "r")) != NULL) /*以只读方式打开指定文件*/
    {
        printf("%s open successfully", filename1);
        printf("\nplease input new name!");
            scanf("%s", filename2); /*输入新的文件路径及名称*/
        rename(filename1, filename2); /*调用rename函数进行重命名*/
        fclose(fp); /*关闭文件*/
    }
    else
    {
        printf("cannot find!!");
        exit(0);
    }
}


int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else 
    {
        return n*func(n-1);
    }
}

#include <stdio.h>

int getLen(int num)    //计算该数一共有多少位(长度)
{
    int flags = 0;
    for (num; num >0 ; num/=10)  
    {
        flags++;   
    }
    return flags;   //返回位数(长度)
}

int getIndex(int len)   //len是数的位数
{
    int i=0;
    int res = 1;
    for (i = 0; i < len ; i++)
    {
        res=res*10;    
    }
    return res;    //返回10^i
}

int main()
{
    int num,temp,LastNum;
    printf("please input a num:\n");
    scanf("%d",&num);

    int len = getLen(num);

    int i=0;   
    for(i = 0; i<len ; i++)
    {

        temp=num%10;   //提取每个位的数
        num=num/10;

        LastNum+=temp*getIndex(len-i-1);   //这里是个累加过程
    }

    printf("the resault=%d\n",LastNum);
}


