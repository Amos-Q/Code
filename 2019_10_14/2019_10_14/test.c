#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int i, j, k;
	for (i = 1; i < 5; i++) { // 以下为三重循环
		for (j = 1; j < 5; j++) {
			for (k = 1; k < 5; k++) { // 确保i、j、k三位互不相同
				if (i != k && i != j && j != k) {
					printf("%d,%d,%d\n", i, j, k);
				}
			}
		}
	}
	system("pause");
	return 0;
}