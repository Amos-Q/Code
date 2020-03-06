#define _CRT_SECURE_NO_WARNINGS 1
/*  File name:Pascal triangle or YangHui triangle
	Founction: display the 8 raws of YangHui triangle
	Time:2018.04.07
	edited by qjx
*/

#include <stdio.h>
#define N 8
int Factorial(int n);
int Combinations(int n, int k);
void GiveInstruction(void);

main()
{
	int raw, i, j, k;
	GiveInstruction();
	printf("Please input the raws of YangHui triangle:");
	scanf("%d", &raw);
	for (i = 1; i <= raw; i++)
	{
		for (j = 0; j < raw - i; j++)	//print the spacebar
		{
			printf(" ");
		}
		for (k = 0; k <= i - 1; k++)	//print the YangHui triangle
		{
			printf("%4d ", Combinations(i - 1, k));
			//	printf(" ");
		}
		printf("\n");
	}
}

int Factorial(int n)   //calculate n！
{
	int i, product = 1;
	for (i = 1; i <= n; i++)
	{
		product *= i;
	}
	return product;
}

int Combinations(int n, int k)    //calculate C(n,k)=n!/(k!*(n-k)!)
{
	int a, b, c;
	a = Factorial(n);
	b = Factorial(k);
	c = Factorial(n - k);
	return a / (b*c);
}

void GiveInstruction(void)
{
	printf("This program can display the YangHui triangle!\n");
	printf("For example:\n");
	printf("  1  \n");
	printf(" 1 1 \n");
	printf("1 2 1\n");
}



#include <stdio.h> 
#include <limits.h>
#define N 13
int Factorial(int n);

main()
{
	int a;
	a = Factorial(N);
	printf("%d", a);
	printf("The value of INT_MAX is %i\n", INT_MAX);
	printf("The value of INT_MIN is %i\n", INT_MIN);
	printf("An int takes %d bytes\n", sizeof(int));

}

int Factorial(int n)   //calculate n！  
{
	int i, product = 1;
	for (i = 1; i <= n; i++)
	{
		product *= i;
	}
	return product;
}