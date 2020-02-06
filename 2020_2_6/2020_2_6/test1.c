#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int nums[] = { 1,2,3,4,5 };
	int k = 3;
	int i = 0;
	int sz = sizeof(nums)/sizeof(int);
	int* num = (int*)malloc(sizeof(int) * sz);
	for (i = 0; i < sz; i++)
	{
		num[(i + k) % sz] = nums[i];
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d", num[i]);
	}
	system("pause");
	return 0;
}
//int main()
//{
//	char s[30] = "Hello China";
//	int i = 0;
//	for (i = 0; s[i] != '\0'; i++)
//	{
//		if (s[i] >= 'A'&&s[i] <= 'Z')
//			s[i] += 32;//ºËÐÄÓï¾ä£¬ÊµÏÖ×Ö·û´®ÖÐ×ÖÄ¸µÄ´óÐ¡Ð´»¥»»
//	}
//	printf("%s", s);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	//int i = 1;
//	//int y = 2;
//	//int k = 0;
//	//k *= i + y;
//	//printf("%d", k);
//	printf("%d,%d,%d,%d", 0 % 3, 1 % 3, 2 % 3, 3 % 3);
//	system("pause");
//	return 0;
//}