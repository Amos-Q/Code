#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Print(char* str)
{
	int count = 0;
	char arr[100] = { 0 };
	while (*str != '\0')
	{
		if (*str != ' ')
		{
			arr[count] = *str;
			count++;
		}
		else
		{
			for(count -=1;count >= 0;count--)
				printf("%c", arr[count]);
			printf(" ");
			count++;
		}
		str++;
	}
	for (count -= 1; count >= 0; count--)
		printf("%c", arr[count]);
}

void Swap(char* str,int len)
{
	char tmp = 0;
	char* right = str + len - 1;
	while (str <= right)
	{
		tmp = *str;
		*str = *right;
		*right = tmp;
		str++;
		right--;
	}
}

int  strlen(char*arr) 
{
	int count = 0;
	while (*arr++)
	{
		count++;
	}
	return count;
}

int main()
{
	char str[] = "student a am i";
	int len = 0;
	len = strlen(str);
	Swap(str,len);
	Print(str);
	system("pause");
	return 0;
}
