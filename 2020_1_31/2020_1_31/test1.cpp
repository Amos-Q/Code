#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
string my_reverse(string in, int in_len);

int main(void)
{
	cout << "�����ַ���" << endl;
	string str_in, str_out;
	getline(cin, str_in);//����cin >> str_in,���ո��ֹͣ������д��str_in
	int in_len = str_in.length();
	str_out = my_reverse(str_in, in_len);
	cout << str_out << endl;

	system("pause");
	return 0;
}


string my_reverse(string in, int in_len)
{
	string out;

	for (int i = 0; i < in_len; i++)
	{
		out += in[in_len - i - 1];
	}
	return out;
}