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
//	// ���Բ�д��Date��û��ʲô��Դ��Ҫ����
//	/*~Date()
//	{
//		cout << "~Date()" << this<<endl;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//	// ���ǲ�д�����������ɵĹ��캯������������
//	// ��������/��������  int/char  ���ᴦ��
//	// �Զ�������  �������Ĺ��캯����ʼ��/��������
//
//	Time _t;
//};
//
//class Stack
//{
//public:
//	// ���󴴽�ʱ�Զ�������ɳ�ʼ������
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
//	// �����������ڵ����Ժ����������
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
//	//Date d1; // 1�����ǲ�д���������� 2��ȫȱʡ��  3���޲ε�  -�� Ĭ�Ϲ��캯�� -�������ο��Ե��õ�
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
//	// ������д�����ǵ��ÿ�������
//	Date d2(d1); // ���õĿ������� 
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
//// ������м�����������operator���صĺ������м�������
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//// �Զ��������ǲ�����������ģ�Ҫ�þ͵�ʵ�����غ������Զ��������õ�ʱ��ȼ��ڵ���������غ���
//int main()
//{
//	Date d1(2020, 5, 12);
//	Date d2(2020, 5, 13);
//	// ����Date�Ķ�����Ƚϴ�С���
//	// IsDateEqual(d1, d2);
//	d1 == d2; // ������ε���->��������ת����operator==(d1, d2);���������һ����������
//	// ��������һ�㲻������д����Ϊ�����ɶ��Բ���
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
//// �Զ��������ǲ�����������ģ�Ҫ�þ͵�ʵ�����غ������Զ��������õ�ʱ��ȼ��ڵ���������غ���
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