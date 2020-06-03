//#define _CRT_SECURE_NO_WARNINGS 
//#include<iostream>
//#include<vector>
//using namespace std;
//
////int main()
////{
////	int n;
////	int i = 0;
////	while (cin >> n)
////	{
////		vector<int> a;
////		a.resize(n + 1);
////		int num = 0;
////		for (i = 0; i < n; i++)
////		{
////			cin >> a[i];
////		}
////		i = 0;
////		while (i < n)
////		{
////			if (a[i] < a[i + 1])
////			{
////				while (i < n && a[i] <= a[i + 1])
////					i++;
////				num++;
////				i++;
////			}
////			else if (a[i] == a[i + 1])
////				i++;
////			else
////			{
////				while (i < n && a[i] >= a[i + 1])
////					i++;
////				num++;
////				i++;
////			}
////		}
////		cout << num;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int sum = 0;
//	int pos = 0;
//	reverse(str.begin(), str.end());
//	int n = str.size();
//	int i = 0;
//	while (i < n)
//	{
//		while (i < n && str[i] != ' ')
//		{
//			sum++;
//			i++;
//		}
//		reverse(str.begin() + pos, str.begin() + pos + sum);
//		i++;
//		sum++;
//		pos += sum;
//		sum = 0;
//	}
//	cout << str;
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // 姓名
private:
	int _age = 18;  // 年龄
};

class Student :  Person
{
public:
	void f()
	{
		cout << _name << endl;
		//cout << _age << endl;
	}
protected:
	int _stuid; // 学号
};

class Teacher : public Person
{
protected:
	int _jobid; // 工号
};

int main()
{
	Student s;
	Teacher t;

	s.Print();
	t.Print();

	return 0;
}