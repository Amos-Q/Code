#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//char * reverseOnlyLetters(char * S) {
//	int left = 0;
//	int right = strlen(S) - 1;
//	char* returns = (char*)malloc(sizeof(char)*strlen(S));
//	printf("%d  %d  %d", left, right, strlen(S));
//	while (left <= right)
//	{
//		if (S[left] != '-')
//		{
//			if (S[right] != '-')
//			{
//				returns[left] = S[right];
//				returns[right] = S[left];
//				left++;
//				right--;
//			}
//			else
//			{
//				returns[right] = S[right];
//				right--;
//			}
//		}
//		else
//		{
//			if (S[right] != '-')
//			{
//				returns[left] = S[left];
//				left++;
//			}
//			else
//			{
//				returns[right] = S[right];
//				returns[left] = S[left];
//				left++;
//				right--;
//			}
//		}
//	}
//	return returns;
//}
//int main()
//{
//	char S[5] = "ab-cd";
//	reverseOnlyLetters(S);
//}
//
//char * reverseOnlyLetters(char * S) {
//	int length = 0, i, j;
//	while (S[length] != 0) length++;
//	char str[length + 1];
//	str[length] = 0;
//	i = 0;
//	j = length - 1;
//	while (i <= j) {
//		if (!(S[i] >= 'A'&&S[i] <= 'Z' || S[i] >= 'a'&&S[i] <= 'z')) {
//			str[i] = S[i];
//			i++;
//			continue;
//		}
//		if (!(S[j] >= 'A'&&S[j] <= 'Z' || S[j] >= 'a'&&S[j] <= 'z')) {
//			str[j] = S[j];
//			j--;
//			continue;
//		}
//		str[i] = S[j];
//		str[j] = S[i];
//		i++;
//		j--;
//	}
//	S = str;
//	return S;
//}
int main()
{
	char str[] = "ABCD", *p = str;
	printf("%d", *(p + 4));
	system("pause");
	return 0;
}