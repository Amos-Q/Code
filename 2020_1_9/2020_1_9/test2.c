#define _CRT_SECURE_NO_WARNINGS 1
/*
解题思路：从最大值开始合并，所以合并从两个数组的末尾元素开始合并，依次把最大的元素放到末尾即可。
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	//end1:nums1的末尾
	//end2:nums2的末尾
	//end:合并之后整个数组的末尾
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;

	while (end1 >= 0 && end2 >= 0)
	{ //选出尾最大的元素，存放到整个数组的末尾
	//每存放一个元素，尾向前移动一个位置
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	//剩余元素依次向末尾存放
	while (end1 >= 0)
	{
		nums1[end--] = nums1[end1--];
	}

	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}
/*
解题思路：使用三次逆转法，让数组旋转k次
1. 先整体逆转
2. 逆转子数组[0, k - 1]
3. 逆转子数组[k, size - 1]
*/
void reverse(int* nums, int begin, int end) {
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;
		++begin;
		--end;
	}
}
// 三趟逆置倒的思路
void rotate(int* nums, int numsSize, int k) {
	if (k > numsSize)
	{
		k %= numsSize;
	}

	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}


void reverse(int* nums, int begin, int end) {
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;
		++begin;
		--end;
	}
	// 本题需要特别注意对[9,9,9,7] + 5的等特殊情况的处理
	int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
		int* addRet = (int*)malloc(10001 * sizeof(int));
		//reti: 第i位的结果
		int reti = 0;
		//从低位开始相加
		int ai = ASize - 1;
		int next = 0; // 进位值
		while (ai >= 0 || K > 0)
		{

			int x1 = 0;
			//如果ai没有越界，还有未相加的位，取出一位存入x1
			if (ai >= 0)
			{
				x1 = A[ai];
				--ai;
			}
			int x2 = 0;
			//如果k大于0，获取k的第i位
			if (K > 0)
			{
				x2 = K % 10;
				K /= 10;
			}
			//第i位的结果：每一位的值 + 进位
			int ret = x1 + x2 + next;
			//如果结果大于9，需要进位
			if (ret > 9)
			{
				ret %= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			//存入第i位的结果到数组中
			addRet[reti++] = ret;
		}
		//如果最高位有进位，需要在存入1
		if (next == 1)
		{
			addRet[reti++] = 1;
		}
		//逆置结果
		reverse(addRet, 0, reti - 1);
		*returnSize = reti;
			单链表的增删查改
			return addRet;
	}
}