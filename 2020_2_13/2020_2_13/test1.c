#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int arr[5] = { 1,2,3,4,5 };
//	printf("%d", arr[i++]);
//	printf("%d", i);
//	system("pause");
//	return 0;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* sortArrayByParity(int* A, int ASize, int* returnSize) {
//	*returnSize = ASize;
//	int* returns = (int*)malloc(sizeof(int)*ASize);
//	int left = 0;
//	int right = ASize - 1;
//	while (left <= right)
//	{
//		if (*A % 2 == 0)
//		{
//			returns[left++] = *A;
//		}
//		else
//		{
//			returns[right--] = *A;
//		}
//		A++;
//	}
//	return returns;
//}

int pivotIndex(int* nums, int numsSize) {
	if (numsSize == 0)
		return -1;
	int left = 0;
	int right = numsSize - 1;
	int leftnum = 0;
	int rightnum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		leftnum = 0;
		rightnum = 0;
		for (left=0; left < i; left++)
		{
			leftnum += nums[left];
		}
		for (right=numsSize - 1; right > i; right--)
		{
			rightnum += nums[right];
		}
		if (leftnum == rightnum)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int nums[] = { 1,7,3,6,5,6 };
	pivotIndex(nums,6);
	return 0;
}
