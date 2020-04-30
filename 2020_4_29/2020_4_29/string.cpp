#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

//1、4个默认成员函数
void test_string1()
{
	string s1; // ok
	string s2("hello"); // ok
	string s3("hello", 2);
	string s4(s2); // ok
	string s5(s2, 1, 8);
	string s6(s2, 1);
	string s7(10, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;

	s1 = s7; // ok
	cout << s1 << endl;
}

// 1、遍历
void test_string2()
{
	string s1("hello");
	s1 += ' ';
	s1 += "world";
	cout << s1 << endl;

	// [] + 下标  推荐用这个
	// 写
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
	}

	// 读
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	// 迭代器
	// 写
	//string::iterator it = s1.begin();
	auto it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}
	// 读
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 范围for
	// C++11 -> 原理被替换成迭代器
	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;

	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
	cout << *vit << " ";
	++vit;
	}
	cout << endl;*/
}

int string2int(const string& str)
{
	int val = 0;
	// const 迭代器 只能读，不能写
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		// *it -= 1;
		val *= 10;
		val += (*it-'0');
		++it;
	}

	val = 0;
	//string::const_reverse_iterator rit = str.rbegin();
	auto rit = str.rbegin();
	while (rit != str.rend())
	{
		// *it -= 1;
		val *= 10;
		val += (*rit - '0');
		++rit;
	}

	return val;
}

// 再看看其他迭代器
void test_string3()
{
	string s1("hello world");
	//倒着遍历？ 反向迭代器
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	string nums("12345");
	cout << string2int(nums) << endl;

	// 方向：正向和反向
	// 属性：普通和const
}

void test_string4()
{
	string s1("hello world");
	string s2("hello");
	cout << s1.size() << endl;
	cout << s2.size() << endl;
	cout << s1.length() << endl;
	cout << s2.length() << endl;

	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;

	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;

	s1 += "111111";
	cout << s1.capacity() << endl;
	s1.clear();
	cout << s1 << endl;
	cout << s1.capacity() << endl;
}

void test_string5()
{
	//string s;
	//s.reserve(100);
	////s.resize(100, 'x');
	//size_t sz = s.capacity();
	//cout << "making s grow:\n";
	//for (int i = 0; i < 100; ++i)
	//{
	//	s.push_back('c');
	//	if (sz != s.capacity())
	//	{
	//		sz = s.capacity();
	//		cout << "capacity changed: " << sz << '\n';
	//	}
	//}

	//string s("hello world");
	//s.resize(5);
	//s.resize(20, 'x');
}

void test_string6()
{
	//string s;
	//s.push_back('x');
	//s.append("111111");

	//s += 'x';
	//s += "xxxxx";
	//cout << s << endl;

	string s;
	s += '1';
	s += "3456";
	cout << s << endl;
	s.insert(s.begin(), '0');
	cout << s << endl;
	s.insert(2, "2");
	cout << s << endl;
	s.erase(2, 10);
	cout << s << endl;

}

int main()
{
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	test_string6();



	return 0;
}