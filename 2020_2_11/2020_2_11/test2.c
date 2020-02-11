#define _CRT_SECURE_NO_WARNINGS 1

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b; //��С��������
	//return *(int *)b - *(int *)a; �ɴ�С����
}

bool containsDuplicate(int* nums, int numsSize) {
	if (numsSize == 0 || numsSize == 1)
		return false;
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 0; i < numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1]) {
			return true;
		}
	}
	return false;
}