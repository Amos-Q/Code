#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//void my_strcpy(char * arr, char * arr2)
//{
//	//while(*arr++ = *arr2)
//	//{
//	//	;
//	//}
//	while (*arr2 != '\0')
//	{
//		//arr = arr2;
//		//*arr++;
//		//*arr2++;
//		*arr++ = *arr2++;
//	}
//	//*arr = '\0';
//}
//
//int main()
//{
//	//strcpy
//	char arr[20] = { 0 };
//	char arr2[20] = "Hello,Bit!";
//	//strcpy(arr, arr2);
//	my_strcpy(arr, arr2);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

int my_strlen(const char * arr)
{
	int ret = 0;
	assert(*arr != '\0');
	while (*arr++)
	{
		ret++;
	}
	return ret;
}
int main()
{
	char arr[] = "Hello";
	int ret = my_strlen(arr);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
