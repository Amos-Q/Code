#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

// 实现一个完善的日期类
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// 是2月且是闰年返回29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}

		return monthDays[month];
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}
	}

	// Date d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// d1 < d2
	// d1.operator<(&d1, d2)
	inline bool operator<(const Date& d) // bool operator<(Date* this, const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;

		return false;
	}

	inline bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// d1 <= d2; => d1 < d2 || d1 == d2
	// d1.operator<=(&d1, d2);
	bool operator<=(const Date& d) // bool operator<=(Date* this, const Date& d)
	{

		return *this < d || *this == d;   // 复用上面的来实现
	}

	// d1 > d2 -> !(d1 <= d2)
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// d1 + 10
	// d1 + 100
	// d1 + 1000
	Date operator+(int day)
	{
		Date ret(*this); // 用d1拷贝构造一个ret
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			// 如果日期的天不合法，就需要往月进度
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;

			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}

		return ret;
	}

	// d1 += 10
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

	//int _hour;
	//int _minute;
	//int _second;
};