#define _CRT_SECURE_NO_WARNINGS 1
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