#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>  
#include<stdlib.h>   

int main()
{

	int killer = 'A';
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		int num = 0;
		num = (killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D');
		if (num == 3)
		{
			printf("killer = %c\n", killer);
		}
	}
	system("pause");
	return 0;

}