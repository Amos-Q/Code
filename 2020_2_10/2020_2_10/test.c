#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	if (x >= 0 && x < 10)
		return true;
	if (x % 10 == 0)
		return false;
	int sz = sizeof(x) / sizeof(int);
	int arr[1000] = { 0 };
	int i = 0;
	while (x > 9)
	{
		arr[i] = x % 10;
		x /= 10;
		i++;
	}
	arr[i] = x;
	int left = 0;
	int right = i;
	while (left < right)
	{
		if (arr[left] == arr[right])
		{
			left++;
			right--;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	isPalindrome(123);
}