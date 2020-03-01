#define _CRT_SECURE_NO_WARNINGS 1

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//�����
void AdjustDown(int arr[], int size, int root) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int max;
	//û������
	if (left >= size) {
		return;
	}
	//�Һ��Ӵ����Ҵ�������
	if (right < size && arr[right] > arr[left]) {
		max = right;
	}
	else {
		max = left;
	}
	if (arr[root] >= arr[max]) {
		return;
	}
	Swap(arr + root, arr + max);
	AdjustDown(arr, size, max);
}
void CreateHeap(int arr[], int size) {
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(arr, size, i);
	}
}
void HeapSort(int arr[], int size) {
	CreateHeap(arr, size);
	for (int i = 0; i < size; i++) {
		Swap(arr, arr + size - i - 1);
		AdjustDown(arr, size - i - 1, 0);
	}
}
