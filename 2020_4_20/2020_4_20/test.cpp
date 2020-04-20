//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date构造函数" << endl;
//	}
//
//	// 1. 静态成员函数可以调用非静态成员函数吗？不行
//	void f1()
//	{
//
//	}
//
//	static void f2()
//	{
//		//f1(); // 没有this指针
//	}
//
//	// 2. 非静态成员函数可以调用类的静态成员函数吗？可以
//	void f3()
//	{
//		f4(); // 突破类域+访问限定符就可以访问，
//		     // 类里面是一个整体都这类域中，类里面不受访问限定符限制
//	}
//
//	static void f4()
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Sum {
//public:
//	Sum() {
//		_sum += _i;
//		++_i;
//	}
//
//	static void Init()
//	{
//		_i = 1;
//		_sum = 0;
//	}
//
//	static int GetSum() {
//		return _sum;
//	}
//private:
//	static int _i;
//	static int _sum;
//};
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum a[n];
//		Sum::Init();
//		Sum* p = new Sum[n];
//		return Sum::GetSum();
//	}
//};
//
//int main()
//{
//	Solution st;
//	cout << st.Sum_Solution(5) << endl;
//	cout << st.Sum_Solution(5) << endl;
//
//
//	/*Date d;
//	Date a[10];
//
//	int i;
//	int ai[10];*/
//
//	//Date d1(1, 2, 3);
//	//Date d2 = 1;
//	//Date d3 = {1,2};
//	//Date d4 = { 1, 2, 3};
//
//	//// 突破类域访问的两种方式。编译可以知道到哪个域找+访问限定符是否可以访问
//	//d1.f4();
//	//Date::f4();
//
//	//cout << sizeof(long) << endl; // 1、验证  2、查官网
//	//cout << sizeof(long long) << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date()
//		:_year(10)
//	{}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	// C++11
//	// 声明时给缺省值
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//
//	static int _n;
//};
//
//int Date::_n = 1;
//
//int main()
//{
//	Date d1;
//	d1.Print(); 
//
//	return 0;
//}

// 友元
//#include <iostream>
//using namespace std;
//
//class Date
//{
//	friend void f(Date& d); // 友元函数
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};
//
//void f(Date& d)
//{
//	d._year = 10;
//	cout << d._year << endl;
//}
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	f(d1);
//
//	return 0;
//}

#include <iostream>
using namespace std;

//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	//void operator<<(ostream& out)
//	//{
//	//	out << _year << "/" << _month << "/" << _day << endl;
//	//}
//
//private:
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "/" << d._month << "/" << d._day << endl;
//
//	return out;
//}
//
//// cout -> ostream
//// cin  -> istream
////写一下
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//int main()
//{
//	int i = 0, j = 1;
//	//cout << i << j << endl;
//
//	Date d1(2020,4,20);
//	Date d2(2020, 4, 21);
//	//cin >> d1 >> d2;
//	cout << d1 << d2 << i << endl;
//
//
//	// cout << d1;   // operator> << (cout, d1);
//	//d1 << cout; // d1.operator<<(cout);
//
//	int x = 1;
//	double y = 1.11;
//	// 为什么能自动识别类型，因为函数重载
//	cout << x; // cout.operator<<(&cout, x)
//	cout << y; // cout.operator<<(&cout, y)
//
//	return 0;
//}

class Time
{
	friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_t._hour = 1;
	}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	return 0;
}