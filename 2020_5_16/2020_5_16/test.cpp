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
		vec.push_back(i);　　　//10个元素依次进入，结果为10
	}

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << "初始化遍历：" << vec[i] << endl;
	}
	//结果为：０，１，２，３，４，５，６，７，８，９
	vector<int>::iterator it;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << "迭代遍历：" << *it << endl;
	}
	//结果为：０，１，２，３，４，５，６，７，８，９
	vec.insert(vec.begin() + 4, 0);
	//结果为:11
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << "插入遍历：" << vec[i] << endl;
	}
	//结果为：０，１，２，３，０，４，５，６，７，８，９
	vec.erase(vec.begin() + 2);
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << "擦除遍历：" << vec[i] << endl;
	}
	//结果为：０，１，３，０，４，５，６，７，８，９
	vec.erase(vec.begin() + 3, vec.begin() + 5);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << "迭代遍历：" << *it << endl;
	}
	return 0;
}

typedef struct rect
{
	int id;
	int length;
	int width;

	//对于向量元素是结构体的，可在结构体内部定义比较函数，下面按照id,length,width升序排序。
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