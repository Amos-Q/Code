#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fibonacci(int n)
{
   if (n <= 1)
        return n;
   else
   {
        int iter1 = 0;
        int iter2 = 1;
        int f = 0;

        for (int i = 2; i <= n; i++)
        {
            f = iter1 + iter2;
            iter1 = iter2;
            iter2 = f;
        }

        return f;
     }
}

union
    {
        char             c;
        unsigned short   s;    
    }A;

    A.s = 0x1234;         
    if(A.c == 0x12)   //0x12是高位字节
    {
        printf("It's MSB");    // 1  0x34
                               // 0  0x12
    }
    else
    {
        printf("It's LSB");    // 1  0x12
                               // 0  0x34
    }

