#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void print()  /*��ӡ����*/
{
	int i, j;
	cout << " -------" << endl;
	for (i = 0; i < 3; ++i)
	{
		cout << "| ";
		for (j = 0; j < 3; ++j)
			cout << arr[i][j] << ' ';
		cout << "| ";
		cout << endl;
	}
	cout << " ------" << endl;
}
void init()             //��ʼ��
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void player()          //����ж�
{
	int i = 0;
	int j = 0;
	cout << "�������к��У�" << endl;
	cin >> i >> j;
	i--;
	j--;
	if (arr[i][j] != ' ')
	{
		cout << "������Ч,����������" << endl;
		player();
	}
	else
	{
		arr[i][j] = '*';
	}
}
void computer()           //�����ж�
{
	for (int i = 0; i < 3; i++)    //�������һ����������Ԫ�أ�����ʣ���λ������
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == '*')
				count++;  //��ÿһ���ϼ���
			if (count == 2)
				break;
		}
		if (count == 2)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[i][k] == ' ')     //�ڿ�λ��������
				{
					arr[i][k] = '@';
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)    //������������Ԫ�أ�����ʣ��λ������
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (arr[j][i] == '*')     //��ÿһ���ϼ���
			{
				count++;
			}
		}
		if (count == 2)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[k][i] == ' ')        //�ڿ�λ��������
				{
					arr[k][i] = '@';
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)    //�ж����Խ���
	{
		int count = 0;          //�����Խ����ϼ���
		if (arr[i][i] == '*')
			count++;
		if (count == 2)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[j][j] == ' ')
				{
					arr[j][j] = '@';
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)     //�жϸ��Խ���
	{
		int count = 0;           //�ڸ��Խ����ϼ���
		if (arr[i][3 - i] == '*')
			count++;
		if (count == 2)
		{
			for (int j = 1; j <= 3; j++)
			{
				if (arr[j][3 - j] == ' ')
				{
					arr[j][3 - j] = '@';
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)      //���û����������������������������
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')
			{
				arr[i][j] = '@';
				return;
			}
		}
	}
}
char judge()         //�ж��ķ�ʤ��
{
	int i = 0;
	for (int i = 0; i < 3; i++)          //�ж��Ƿ���һ��
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
		{
			return arr[i][0];
		}
	}
	for (i = 0; i < 3; i++)              //�ж��Ƿ���һ��
	{
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
		{
			return arr[0][i];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])      //�ж����Խ���
		return arr[0][0];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])      //�жϸ��Խ���
		return arr[0][2];
	return ' ';
}
int  panduan()     //�ж�ʤ��
{
	if (judge() == '*')
	{
		cout << "��ϲ��Ӯ��" << endl;
		print();
		return  1;
	}
	else if (judge() == '@')
	{
		cout << "���ź���������" << endl;
		print();
		return 1;
	}
	return 0;
}
int main()
{
	int n = 0;    //��¼����
	init();          //��ʼ��
	cout << "������Ϸ" << endl;
	while (n <= 9)
	{
		print();
		player();
		n++;
		if (panduan() == 1)     //ʤ���Ѷ�
		{
			return 0;
		}
		computer();
		n++;
		if (panduan() == 1)     //ʤ���Ѷ�
		{
			return 0;
		}
	}
	print();
	cout << "ƽ��" << endl;
	return 0;
}