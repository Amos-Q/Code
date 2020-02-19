#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
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
	if (left - right == 0)
	{
		return 0;
	}
	return right - left + 1;
}