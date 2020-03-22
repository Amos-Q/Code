#define _CRT_SECURE_NO_WARNINGS 1
void quickSort(int a[], int left, int right) {
	if (left > right)
		return;
	//枢纽单元的选取为最左边、最中间、最右边三个数的中位数,使得左右分布尽量均匀
	int key;
	int index = 0;
	if (a[left] > a[right] && a[left] < a[(left + right) / 2] || a[left]<a[right] && a[left] > a[(left + right) / 2]) {
		key = a[left];
		index = left;
	}
	else if (a[right] > a[left] && a[right] < a[(left + right) / 2] || a[right]<a[left] && a[right] > a[(left + right) / 2]) {
		key = a[right];
		index = right;
	}
	else {
		key = a[(left + right) / 2];
		index = (left + right) / 2;
	}
	//将key的值放在第一位
	int temp = a[left];
	a[left] = a[index];
	a[index] = temp;

	//实现大数右边小数左边
	int i = left, j = right;
	while (i < j) {
		while (i<j&&a[j]>key) { j--; }
		if (i < j) {
			a[i++] = a[j];
		}
		while (i < j&&a[i] < key) { i++; }
		if (i < j) {
			a[j--] = a[i];
		}
	}
	//最后退出一定是i==j，因为某个（i或者j）在等待时，另一个++或--，当++或--到与另一个相等时
	//就退出，这时相等的下标位置就是等待着插入元素的位置，也就是最后要放key值的位置。
	a[i] = key;
	//递归地处理左边，递归地处理右边
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);

}
