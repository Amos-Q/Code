#define _CRT_SECURE_NO_WARNINGS 1
int pivotIndex(int* nums, int numsSize) {
	int i, left = 0, right = 0;
	if (numsSize == 0)//考虑极端情况
		return -1;
	for (i = 1; i < numsSize; i++)//算出右边的总和
	{
		right = right + nums[i];
	}
	i = 0;
	while (right != left && i < numsSize - 1)
	{
		left = left + nums[i];
		i++;
		right = right - nums[i];
	}
	if (right == left)
		return i;
	return -1;
}
