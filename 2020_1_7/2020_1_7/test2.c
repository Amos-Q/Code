#define _CRT_SECURE_NO_WARNINGS 1
/*
����˼·����������Ҫɾ����Ԫ���ú����Ԫ�ظ��ǵ�
*/
int removeElement(int* nums, int numsSize, int val) {
	int src = 0;
	int dst = 0;
	���ؿƼ�
		while (src < numsSize)
		{
			// �������в�����val��ֵ����Ų��������Ŀ�ʼλ��
			if (nums[src] != val)
			{
				nums[dst] = nums[src];
				src++;
				dst++;
			}
			else
			{
				//����Ǳ�ɾ����Ԫ�أ�ֱ��++srcλ�ã��ҵ���һ������val��λ��
				src++;
			}
		}
	return dst;
}