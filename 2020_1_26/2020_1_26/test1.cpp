#include<iostream>
using namespace std;

void Reverse(char s[], int i)
{
	if (s[i])
		Reverse(s, i + 1);     //if条件成立，即进行递归
	cout << s[i];           //按反序输出字符串中的各个字符
}
int main()
{
	char str[100];
	cout << "Enter a sentence: " << endl;
	cin.getline(str, 100);
	Reverse(str, 0);
	cout << endl;
}