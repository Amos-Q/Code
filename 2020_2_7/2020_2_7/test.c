#define _CRT_SECURE_NO_WARNINGS 1
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


void rotate(int* nums, int numsSize, int k) 
{ 
	int i = 0;   
	int *dst = (int *)malloc(sizeof(int)*numsSize);    
	for (; i < numsSize; i++)
	{
		dst[(i + k) % numsSize] = nums[i];
	}   
	memcpy(nums, dst, sizeof(int)*numsSize); 
}


