#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	int i = 0;
	vector<int> vec;
	for (i = 0; i < 10; i++)
	{
		vec.push_back(i);������//10��Ԫ�����ν��룬���Ϊ10
	}

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << "��ʼ��������" << vec[i] << endl;
	}
	//���Ϊ����������������������������������������
	vector<int>::iterator it;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << "����������" << *it << endl;
	}
	//���Ϊ����������������������������������������
	vec.insert(vec.begin() + 4, 0);
	//���Ϊ:11
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << "���������" << vec[i] << endl;
	}
	//���Ϊ��������������������������������������������
	vec.erase(vec.begin() + 2);
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << "����������" << vec[i] << endl;
	}
	//���Ϊ����������������������������������������
	vec.erase(vec.begin() + 3, vec.begin() + 5);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << "����������" << *it << endl;
	}
	return 0;
}

typedef struct rect
{
	int id;
	int length;
	int width;

	//��������Ԫ���ǽṹ��ģ����ڽṹ���ڲ�����ȽϺ��������水��id,length,width��������
	bool operator< (const rect &a)  const
	{
		if (id != a.id)
			return id < a.id;
		else
		{
			if (length != a.length)
				return length < a.length;
			else
				return width < a.width;
		}
	}
}Rect;

int main()
{
	vector<Rect> vec;
	Rect rect;
	rect.id = 1;
	rect.length = 2;
	rect.width = 3;
	vec.push_back(rect);
	vector<Rect>::iterator it = vec.begin();
	cout << (*it).id << ' ' << (*it).length << ' ' << (*it).width << endl;

	return 0;

}