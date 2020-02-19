#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#include <stdio.h>
//
////int cmp(const void* a, const void* b)
////{
////	return *(int*)a - *(int*)b;
////}
////
////int main()
////{
////	int arr[] = { 1,2,3,6,7 };
////	qsort(arr, 5, sizeof(int), cmp);
////}
////
////int main()
////{
////	char a[] = "acfg";
////	strcpy(a, "ADC");
////	printf("%s", a);
////	system("pause");
////	return 0;
////}
//
//bool isPalindrome(char * s) {
//	int left = 0;
//	int right = strlen(s) - 1;
//	while (left <= right)
//	{
//		if (s[left] < 48 || (s[left] > 57 && s[left] < 'A') || (s[left] > 'Z' && s[left] < 'a') || s[left] > 'z')
//		{
//			left++;
//		}
//		else if (s[right] < 'A' || (s[left] > 'Z' && s[left] < 'a') || s[right] > 'z')
//		{
//			right--;
//		}
//		else {
//			if (s[left] == s[right] || s[left] + 32 == s[right] || s[left] - 32 == s[right])
//			{
//				left++;
//				right--;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	char s[] = "0P";
//	isPalindrome(s);
//	system("pause");
//	return 0;
//}
//
//
//int compress(char* chars, int charsSize) {
//	int num = 0;
//	int i = 0;
//	int ch = 0;
//	while (i < charsSize)
//	{
//		if (chars[i] == chars[ch])
//		{
//			num++;
//			i++;
//		}
//		else
//		{
//			chars[++ch] = num + '0';
//			num = 0;
//			ch = i;
//		}
//	}
//	return i;
//}
int cmp(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}
int findUnsortedSubarray(int* nums, int numsSize) {
	int* arr = (int*)malloc(sizeof(int)*numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		arr[i] = nums[i];
	}
	int left = 0;
	int right = numsSize - 1;
	qsort(arr, numsSize, sizeof(int), cmp);
	while (left < right)
	{
		if (arr[left] == nums[left])
		{
			left++;
		}
		else if (arr[right] == nums[right])
		{
			right--;
		}
		else
		{
			break;
		}
	}
	return right - left;
}

int main()
{
	int nums[] = { 2,6,4,8,10,9,15 };
	findUnsortedSubarray(nums,7);
	system("pause");
	return 0;
}