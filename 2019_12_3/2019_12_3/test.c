#define _CRT_SECURE_NO_WARNINGS 1

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
	{
		return 0;
	}
	int i = 1;
	int num = 0;
	while (i < numsSize)
	{
		if (nums[num] != nums[i])
		{
			num++;
			nums[num] = nums[i];
		}
		i++;
	}
	return (num + 1);
}

int removeElement(int* nums, int numsSize, int val) {
	int num = 0;
	int i = 0;
	while (i < numsSize)
	{
		if (nums[i] != val)
		{
			nums[num] = nums[i];
			num++;
		}
		i++;
	}
	return num;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int p = m;
	int q = 0;
	int j = 0;
	int tmp = 0;
	for (; p < nums1Size; p++)
	{
		nums1[p] = nums2[q];
		q++;
	}
	for (q = 0; q < nums1Size - 1; q++)
	{
		for (j = 0; j < nums1Size - 1 - q; j++)
		{
			if (nums1[j] > nums1[j + 1])
			{
				tmp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = tmp;
			}
		}
	}
}

void rotate(int* nums, int numsSize, int k) {
	int *ret = (int *)malloc(sizeof(int)*numsSize);
	for (int i = 0; i < numsSize; i++) {
		ret[(i + k) % numsSize] = nums[i];
	}
	memcpy(nums, ret, sizeof(int)*numsSize);
	return;
}
