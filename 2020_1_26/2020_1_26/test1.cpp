#include<iostream>
using namespace std;

void Reverse(char s[], int i)
{
	if (s[i])
		Reverse(s, i + 1);     //if���������������еݹ�
	cout << s[i];           //����������ַ����еĸ����ַ�
}
int main()
{
	char str[100];
	cout << "Enter a sentence: " << endl;
	cin.getline(str, 100);
	Reverse(str, 0);
	cout << endl;
}