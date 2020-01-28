#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void countEnglish(string s, int count[]) {
	int j = 0;
	// 这地方使用的是ASCII码值来表示的字母 
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z')
		{
			j = (int)(s[i] - 'a');
			count[j]++;
		}
		if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			j = (int)(s[i] - 'A');
			count[j]++;
		}
	}

}
//这个程序存在问题：
//1.只能顺序输出a-z的个数，如果字符串不是按顺序的，也会顺序输出a-z的个数
//2.如果是大写 小写字母混合的话 就不行(得用两个数组来存个数) 
int main()
{
	string str;           //定义字符串 s 是小写 
	getline(cin, str);    //输入字符串 
	cout << "字符串长度:" << str.length() << endl; //输出字符串长度 
//	cout<<(int)('z'-'a')<<endl;
	int count[26];
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
	}
	//调用函数 
	countEnglish(str, count);

	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			cout << (char)('a' + i) << count[i];
		}
	}
	return 0;

}