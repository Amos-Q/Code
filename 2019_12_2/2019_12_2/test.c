#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	int f1 = 0, f2 = 1, f3 = f1 + f2;
	while (1)
	{
		if (f2 == num)
		{
			printf("%d\n", 0);
			break;
		}
		else if (f2 > num)
		{
			if (abs(f2 - num) > abs(f1 - num))
			{
				printf("%d\n", abs(f1 - num));
			}
			else
			{
				printf("%d\n", abs(f2 - num));
			}
			break;
		}
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
	return 0;
}