#define _CRT_SECURE_NO_WARNINGS 1
#include < iostream >
#include < string >
using namespace std;
int strlen(char *str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}
void revers(char *b)
{
	char c;
	int j, len;
	len = strlen(b);
	j = len / 2 - 1;
	while (j >= 0)
	{
		c = *(b + j);
		*(b + j) = *(b + len - j - 1);
		*(b + len - j - 1) = c;
		j--;
	}
	b[len] = '\0';
}
void main()
{
	char str[] = { "1234567890" };
	cout << str << "----的长度：" << strlen(str) << endl;
	cout << str << endl;//倒序前
	revers(str);//
	cout << str << endl;//倒序后
}