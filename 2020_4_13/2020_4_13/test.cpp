#include <iostream>
using namespace std;

//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//};
//
//class Date
//{
//public:
//	/*Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}*/
//	
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date()" << this << endl;
//	}
//
//	// 可以不写，Date类没有什么资源需要清理
//	/*~Date()
//	{
//		cout << "~Date()" << this<<endl;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//	// 我们不写，编译器生成的构造函数和析构函数
//	// 内置类型/基本类型  int/char  不会处理
//	// 自定义类型  调用它的构造函数初始化/析构函数
//
//	Time _t;
//};
//
//class Stack
//{
//public:
//	// 对象创建时自动调用完成初始化工作
//	Stack(int n = 10)
//	{
//		_a = (int*)malloc(sizeof(int)*n);
//		_size = 0;
//		_capacity = n;
//	}
//
//	void Push(int x);
//	void Pop();
//	size_t Size();
//	// ...
//
//	// 对象声明周期到了以后，完成清理工作
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	//Date d1; // 1、我们不写编译器生成 2、全缺省的  3、无参的  -》 默认构造函数 -》不传参可以调用的
//	//Date d2(2020, 4, 11);
//	//Date d2;
//
//	//Stack st;
//
//	Date d;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// Date d2(d1); 
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void func(Date& d)
//{
//
//}
//
//int main()
//{
//	Date d1(2020, 5, 12);
//
//	// 这两个写法都是调用拷贝构造
//	Date d2(d1); // 调用的拷贝构造 
//	Date d3 = d1;
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	//func(d1);
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////bool IsDateEqual(const Date& d1, const Date& d2)
////{
////	// ..
////}
//
//// 运算符有几个操作数，operator重载的函数就有几个参数
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//// 自定义类型是不能用运算符的，要用就得实现重载函数，自定义类型用的时候等价于调用这个重载函数
//int main()
//{
//	Date d1(2020, 5, 12);
//	Date d2(2020, 5, 13);
//	// 比如Date的对象想比较大小相等
//	// IsDateEqual(d1, d2);
//	d1 == d2; // 编译如何调用->这里编译会转换成operator==(d1, d2);所这里就是一个函数调用
//	// 但是我们一般不会这样写，因为这样可读性不好
//	operator==(d1, d2);
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	// d1 == d2;
//	// d1.operator==(&d1, d2);
//	bool operator==(const Date& d) // bool operator==(Date* this, const Date& d)
//	{
//		return this->_year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	
//	// d1 > d2;
//	// d1.operator>(d2);
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year)
//			return true;
//		else if (_year == d._year && _month > d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day > d._day)
//			return true;
//
//		return false;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// 自定义类型是不能用运算符的，要用就得实现重载函数，自定义类型用的时候等价于调用这个重载函数
//int main()
//{
//	Date d1(2020, 5, 12);
//	Date d2(2020, 5, 13);
//	d1 == d2;  // d1.operator==(d2);
//
//	cout << (d1 > d2) << endl;
//
//	return 0;
//}