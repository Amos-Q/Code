#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] < 9)
		{
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
		digits[i] = 0;
	}
	int* returns = (int*)malloc(sizeof(int)*(digitsSize + 1));
	returns[0] = 1;
	for (int i = 1; i < (digitsSize + 1); i++)
		returns[i] = 0;
	*returnSize = digitsSize + 1;
	return returns;
}

int thirdMax(int* nums, int numsSize) {
	int min = nums[0];
	for (int i = 0; i < numsSize; i++)
	{
		if (min > nums[i])
			min = nums[i];
	}
	int max1 = min, max2 = min, max3 = min;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max1) {
			max3 = max2;
			max2 = max1;
			max1 = nums[i];
		}
		else if (nums[i] > max2&& nums[i] < max1) {
			max3 = max2;
			max2 = nums[i];
		}
		else if (nums[i] > max3&& nums[i] < max2) {
			max3 = nums[i];
		}
	}
	if (max3 == max2)
		return max1;
	else
		return max3;
}