#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void countEnglish(string s, int count[]) {
	int j = 0;
	// ��ط�ʹ�õ���ASCII��ֵ����ʾ����ĸ 
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
//�������������⣺
//1.ֻ��˳�����a-z�ĸ���������ַ������ǰ�˳��ģ�Ҳ��˳�����a-z�ĸ���
//2.����Ǵ�д Сд��ĸ��ϵĻ� �Ͳ���(�������������������) 
int main()
{
	string str;           //�����ַ��� s ��Сд 
	getline(cin, str);    //�����ַ��� 
	cout << "�ַ�������:" << str.length() << endl; //����ַ������� 
//	cout<<(int)('z'-'a')<<endl;
	int count[26];
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
	}
	//���ú��� 
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