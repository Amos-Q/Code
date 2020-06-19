#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//bool Per_number(int i)
//{
//	int sum = 0;
//	for (int j = 1; j < i; j++)
//	{
//		if (i%j == 0)
//			sum += j;
//	}
//	if (sum == i)
//		return true;
//	return false;
//}
//
//void Number(int n)
//{
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (Per_number(i))
//			count++;
//	}
//	cout << count << endl;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//		Number(n);
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>
#include <map>
using namespace std;

string Judge(string s)
{
	map<char,int> dx;
	dx.insert(pair<char, int>('2',2));
	dx.insert(make_pair('3',3));
	dx.insert(make_pair('4',4));
	dx.insert(make_pair('5',5));
	dx.insert(make_pair('6',6));
	dx.insert(make_pair('7',7));
	dx.insert(make_pair('8',8));
	dx.insert(make_pair('9',9));
	dx.insert(make_pair('1',10));
	dx.insert(make_pair('J',11));
	dx.insert(make_pair('Q',12));
	dx.insert(make_pair('K',13));
	dx.insert(make_pair('A',14));
	string s1;
	string s2;
	int i = 0;
	while (s[i] != '-')
	{
		if (s[i] != '0')
			s1.push_back(s[i]);
		i++;
	}
	i++;
	while (s[i] != '\0')
	{
		if (s[i] != '0')
			s2.push_back(s[i]);
		i++;
	}
	if (s1.size() == 7)
	{
		if (s2.size() == 7)
		{
			map<char, int>::iterator it1, it2;
			it1 = dx.find(s1[0]);
			it2 = dx.find(s2[0]);
			if (it1->second > it2->second)
				return s1;
			else
				return s2;
		}
		else if (s2.size() == 11)
			return s2;
		else
			return s1;
	}
	else if (s1[0] == 'j')
		return s1;
	else if (s1.size() == 5)
	{
		if (s2[0] == 'j' || s2.size() == 7)
			return s2;
		else if (s2.size() == 5)
		{
			map<char, int>::iterator it1, it2;
			it1 = dx.find(s1[0]);
			it2 = dx.find(s2[0]);
			if (it1->second > it2->second)
				return s1;
			else
				return s2;
		}
		else
			return "ERROR";
	}
	else if (s1.size() == 9)
	{
		if (s2[0] == 'j' || s2.size() == 7)
			return s2;
		else if (s2.size() == 9)
		{
			map<char, int>::iterator it1, it2;
			it1 = dx.find(s1[0]);
			it2 = dx.find(s2[0]);
			if (it1->second > it2->second)
				return s1;
			else
				return s2;
		}
		else
			return "ERROR";
	}
	else if (s1.size() == 3)
	{
		if (s2[0] == 'j' || s2.size() == 7)
			return s2;
		else if (s2.size() == 3)
		{
			map<char, int>::iterator it1, it2;
			it1 = dx.find(s1[0]);
			it2 = dx.find(s2[0]);
			if (it1->second > it2->second)
				return s1;
			else
				return s2;
		}
		else
			return "ERROR";
	}
	else if (s1.size() == 1)
	{
		if (s2[0] == 'j' || s2.size() == 7)
			return s2;
		else if (s2.size() == 1)
		{
			map<char, int>::iterator it1, it2;
			it1 = dx.find(s1[0]);
			it2 = dx.find(s2[0]);
			if (it1->second > it2->second)
				return s1;
			else
				return s2;
		}
		else
			return "ERROR";
	}
}

int main()
{
	string str;
	string count;
	getline(cin,str);
	count = Judge(str);
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] == '1')
			count.insert(count.begin()+i+1,'0');
	}
	cout << count << endl;
	system("pause");
	return 0;
}