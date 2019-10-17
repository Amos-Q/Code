#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void Print(unsigned int value)
{
	int arr[32] = { 0 };
	int i = 0;
	while (value > 0)
	{
		if ((value & 1) == 1)
		{
			arr[i] = 1;
			i++;
		}
		if ((value & 1) == 0)
		{
			arr[i] = 0;
			i++;
		}
		value >>= 1;
	}
	for (i -= 1; i >= 0; i--)
		printf("%d ", arr[i]);
}

int main()
{
	int i = 0;
	printf("Input number:");
	scanf("%d", &i);
	Print(i);
	system("pause");
	return 0;
}