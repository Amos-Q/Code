#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Partition(int buf[], int left, int right) {
	int temp = buf[left];
	while (left < right) {
		while (left < right && buf[right]>temp)
			right--;
		buf[left] = buf[right];
		while (left < right && buf[left] <= temp)
			left++;
		buf[right] = buf[left];
	}
	buf[left] = temp;
	return left;
}
void quickSort(int buf[], int left, int right) {
	if (left < right) {
		int p = Partition(buf, left, right);
		quickSort(buf, left, p - 1);
		quickSort(buf, p + 1, right);
	}
}
int main() {
	int n, i;
	int buf[101];
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		quickSort(buf, 0, n - 1);
		for (i = 0; i < n; i++) {
			printf("%d ", buf[i]);
		}
		printf("\n");
	}
}