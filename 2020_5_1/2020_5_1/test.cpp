#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main()
//{
//	vector<int> v;
//	v.push_back(3);  //����β������3
//	v.push_back(2);
//	v.push_back(1);
//	v.push_back(0);
//	cout << " �±� " << v[3] << endl;
//	cout << " ������ " << endl;
//	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
//	{
//		cout << *i << " ";
//	}
//	cout << endl;
//	//�ڵ�һ��Ԫ��֮ǰ����111  insert begin+n���ڵ�n��Ԫ��֮ǰ����
//	v.insert(v.begin(), 111);
//	//�����һ��Ԫ��֮�����222 insert end + n ����n��Ԫ��֮�����
//	v.insert(v.end(), 222);
//	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
//	{
//		cout << *i << " ";
//	}
//	cout << endl;
//
//	vector<int> arr(10);
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
//	{
//		cout << *i << " ";
//	}
//	cout << endl;
//	//ɾ�� ͬinsert
//	arr.erase(arr.begin());
//	for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
//	{
//		cout << *i << " ";
//	}
//	cout << endl;
//	arr.erase(arr.begin(), arr.begin() + 5);
//	for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
//	{
//		cout << *i << " ";
//	}
//	cout << endl;
//	return 0;
//}


//1.����ͳ�ʼ��
vector<int> vec1;    //Ĭ�ϳ�ʼ����vec1Ϊ��
vector<int> vec2(vec1);  //ʹ��vec1��ʼ��vec2
vector<int> vec3(vec1.begin(), vec1.end());//ʹ��vec1��ʼ��vec2
vector<int> vec4(10);    //10��ֵΪ��Ԫ��
vector<int> vec5(10, 4);  //10��ֵΪ��Ԫ��
//2.���ò�������
vec1.push_back(100);            //���Ԫ��
int size = vec1.size();         //Ԫ�ظ���
bool isEmpty = vec1.empty();    //�ж��Ƿ�Ϊ��
cout << vec1[0] << endl;        //ȡ�õ�һ��Ԫ��
vec1.insert(vec1.end(), 5, 3);    //��vec1.backλ�ò����ֵΪ��Ԫ��
vec1.pop_back();              //ɾ��ĩβԪ��
vec1.erase(vec1.begin(), vec1.end());//ɾ��֮���Ԫ�أ�����Ԫ��ǰ��
cout << (vec1 == vec2) ? true : false;  //�ж��Ƿ����==����=��>=��<=...
vector<int>::iterator iter = vec1.begin();    //��ȡ�������׵�ַ
vec1.clear();                 //���Ԫ��
//3.����
	//�±귨
int length = vec1.size();
for (int i = 0; i < length; i++)
{
	cout << vec1[i];
}
cout << endl << endl;
//��������
vector<int>::const_iterator iterator = vec1.begin();
for (; iterator != vec1.end(); iterator++)
{
	cout << *iterator;
}

