#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	int nums[] = { 3,2,3,4,5,3 };
	int val = 3;
	int newIndex = 0;
	int sz = sizeof(nums) / sizeof(int);
	for (int i = 0; i < sz; i++) 
	{
		if (nums[i] != val) 
		{
			nums[newIndex] = nums[i];
			newIndex++;
		}
	}
	system("pause");
	return 0;
}