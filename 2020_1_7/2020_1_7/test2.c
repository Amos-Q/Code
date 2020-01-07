#define _CRT_SECURE_NO_WARNINGS 1
/*
解题思路：将数组中要删除的元素用后面的元素覆盖掉
*/
int removeElement(int* nums, int numsSize, int val) {
	int src = 0;
	int dst = 0;
	比特科技
		while (src < numsSize)
		{
			// 将数组中不等于val的值依次挪动到数组的开始位置
			if (nums[src] != val)
			{
				nums[dst] = nums[src];
				src++;
				dst++;
			}
			else
			{
				//如果是被删除的元素，直接++src位置，找到第一个不是val的位置
				src++;
			}
		}
	return dst;
}