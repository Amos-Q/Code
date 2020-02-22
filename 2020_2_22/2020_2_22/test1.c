#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define false 0
#define true 1
#include <stdio.h>
//bool isMatch(char * s, char * p) {
//	int left1 = 0;
//	int left2 = 0;
//	int right1 = strlen(s) - 1;
//	int right2 = strlen(p) - 1;
//	char tmp = 0;
//	while (left1 <= right1 || left2 <= right2)
//	{
//		if (s[left1] == p[left2])
//		{
//			left1++;
//			left2++;
//		}
//		else if (s[right1] == p[right2])
//		{
//			if (left1 < right1 && left2 < right2)
//			{
//				right1--;
//				right2--;
//			}
//			else
//				return false;
//		}
//		else if (p[left2] == '*')
//		{
//			if (p[left2 + 1] != '\0') {
//				tmp = p[left2 + 1];
//				if (s[left1] == tmp) {
//					left1++;
//					left2 += 2;
//				}
//				else
//				{
//					left1++;
//				}
//			}
//			else
//			{
//				left1++;
//				if (s[left1] == '\0')
//					left2++;
//			}
//		}
//		else if (p[left2] == '?')
//		{
//			left1++;
//			left2++;
//		}
//		else {
//			return false;
//		}
//	}
//	return true;
//}
//bool isMatch(char * s, char * p) {
//	int left1 = 0;
//	int left2 = 0;
//	if (*s == '\0')
//	{
//		if (*p == '?' || *p == '*' || *p == '\0')
//			return true;
//		else
//			return false;
//	}
//	while (s[left1] || p[left2])
//	{
//		if (s[left1] == p[left2])
//		{
//			left1++;
//			left2++;
//		}
//		else if (p[left2] == '*')
//		{
//			if (p[left2 + 1] != '\0') {
//				int num = left1;
//				int next = 0;
//				while (num < strlen(s))
//				{
//					if (s[num] == p[left2 + 1])
//						next = num;
//					num++;
//				}
//				left2 += 2;
//				left1 = ++next;
//			}
//			else
//				return true;
//		}
//		else if (p[left2] == '?')
//		{
//			left1++;
//			left2++;
//		}
//		else {
//			return false;
//		}
//	}
//	return true;
//}
//
//int left1 = 0;
//int left2 = 0;
//if (*s == '\0')
//{
//	if (*p == '\0' || *p == '*')
//		return true;
//	else
//		return false;
//}
//while (s[left1])
//{
//	if (s[left1] == p[left2])
//	{
//		left1++;
//		left2++;
//	}
//	else if (p[left2] == '*')
//	{
//		if (p[left2 + 1] != '\0') {
//			if (p[left2 + 1] == '?')
//			{
//
//			}
//			int num = left1;
//			int next = 0;
//			while (num < strlen(s))
//			{
//				if (s[num] == p[left2 + 1])
//					next = num;
//				num++;
//			}
//			left2 += 2;
//			left1 = ++next;
//		}
//		else
//			return true;
//	}
//	else if (p[left2] == '?')
//	{
//		left1++;
//		left2++;
//	}
//	else {
//		return false;
//	}
//}
//if (p[left2] == '\0' || (p[left2] == '*' && p[left2 + 1] == '\0'))
//return true;
//else
//return false;

bool isMatch(char * s, char * p) {
	int index_s = 0;
	int index_p = 0;
	int star_p = -1;
	int star_s = 0;
	while (index_s < strlen(s)) {
		if (index_p < strlen(p) && p[index_p] == '*') {
			//出现*
			star_p = index_p++;
			star_s = index_s;
		}
		else if (index_p < strlen(p) && (p[index_p] == s[index_s] || p[index_p] == '?')) {
			//当前字符匹配
			index_s++;
			index_p++;
		}
		else if (star_p > -1) {
			//当前字符不匹配，但前面出现过*，回溯，用前面的*匹配字符
			index_p = star_p + 1;
			index_s = ++star_s;
		}
		else {
			return false;
		}
	}
	//s 匹配完了，但是p只遍历了部分，当且仅当p 的剩余部分全部都是*，二者才能成功匹配。
	while (index_p < strlen(p)) {
		if (p[index_p] == '*')
			index_p++;
		else
			return false;
	}
	return true;
}
int main()
{
	char s[] = "abcdef";
	char p[] = "*a*b?ce*f";
	isMatch(s, p);
	system("pause");
	return 0;
}