#define _CRT_SECURE_NO_WARNINGS 1
/*
����˼·�������ֵ��ʼ�ϲ������Ժϲ������������ĩβԪ�ؿ�ʼ�ϲ������ΰ�����Ԫ�طŵ�ĩβ���ɡ�
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	//end1:nums1��ĩβ
	//end2:nums2��ĩβ
	//end:�ϲ�֮�����������ĩβ
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;

	while (end1 >= 0 && end2 >= 0)
	{ //ѡ��β����Ԫ�أ���ŵ����������ĩβ
	//ÿ���һ��Ԫ�أ�β��ǰ�ƶ�һ��λ��
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	//ʣ��Ԫ��������ĩβ���
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
����˼·��ʹ��������ת������������תk��
1. ��������ת
2. ��ת������[0, k - 1]
3. ��ת������[k, size - 1]
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
// �������õ���˼·
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
	// ������Ҫ�ر�ע���[9,9,9,7] + 5�ĵ���������Ĵ���
	int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
		int* addRet = (int*)malloc(10001 * sizeof(int));
		//reti: ��iλ�Ľ��
		int reti = 0;
		//�ӵ�λ��ʼ���
		int ai = ASize - 1;
		int next = 0; // ��λֵ
		while (ai >= 0 || K > 0)
		{

			int x1 = 0;
			//���aiû��Խ�磬����δ��ӵ�λ��ȡ��һλ����x1
			if (ai >= 0)
			{
				x1 = A[ai];
				--ai;
			}
			int x2 = 0;
			//���k����0����ȡk�ĵ�iλ
			if (K > 0)
			{
				x2 = K % 10;
				K /= 10;
			}
			//��iλ�Ľ����ÿһλ��ֵ + ��λ
			int ret = x1 + x2 + next;
			//����������9����Ҫ��λ
			if (ret > 9)
			{
				ret %= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			//�����iλ�Ľ����������
			addRet[reti++] = ret;
		}
		//������λ�н�λ����Ҫ�ڴ���1
		if (next == 1)
		{
			addRet[reti++] = 1;
		}
		//���ý��
		reverse(addRet, 0, reti - 1);
		*returnSize = reti;
			���������ɾ���
			return addRet;
	}
}