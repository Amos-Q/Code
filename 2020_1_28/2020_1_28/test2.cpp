#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void countEnglish(string s, int count[], int counT[]) {
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
			counT[j]++;
		}
	}

}
//�����д Сд��ĸ�������������� �����������������д Сд����) 
int main()
{
	string str;           //�����ַ��� s ��Сд 
	getline(cin, str);    //�����ַ��� 
	cout << str.length() << endl; //����ַ������� 
	cout << (int)('z' - 'a') << endl;
	int count[26]; //��Сд��ĸ 
	int counT[26]; //���д��ĸ
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
		counT[i] = 0;
	}
	//���ú��� 
	countEnglish(str, count, counT);

	for (int i = 0; i < 26; i++)
	{
		//���Сд��ĸ����
		if (count[i] != 0)
		{
			cout << (char)('a' + i) << count[i];
		}
		//�����д��ĸ���� 
		if (counT[i] != 0)
		{
			cout << (char)('A' + i) << counT[i];
		}
	}
	return 0;

}