#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void countEnglish(string s, int count[], int counT[]) {
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
			counT[j]++;
		}
	}

}
//解决大写 小写字母混合输入计数问题 （用两个数组来存大写 小写个数) 
int main()
{
	string str;           //定义字符串 s 是小写 
	getline(cin, str);    //输入字符串 
	cout << str.length() << endl; //输出字符串长度 
	cout << (int)('z' - 'a') << endl;
	int count[26]; //存小写字母 
	int counT[26]; //存大写字母
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
		counT[i] = 0;
	}
	//调用函数 
	countEnglish(str, count, counT);

	for (int i = 0; i < 26; i++)
	{
		//输出小写字母计数
		if (count[i] != 0)
		{
			cout << (char)('a' + i) << count[i];
		}
		//输出大写字母计数 
		if (counT[i] != 0)
		{
			cout << (char)('A' + i) << counT[i];
		}
	}
	return 0;

}