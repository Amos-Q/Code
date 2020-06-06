#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int stuid)
//		:Person(name)
//		,_stuid(stuid)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)
//		, _stuid(s._stuid)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	// s1 = s3
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_stuid = s._stuid;
//			cout << "Student& operator=(const Student& s)" << endl;
//
//		}
//
//		return *this;
//	}
//
//	~Student()  // 子类的析构函数和父类的析构函数构成隐藏，因为他们的名字会被编译器统一处理成destructor（跟多态有关）
//	{
//		//Person::~Person(); // 正确的用法不需要你显示调用，结束后自动调用父类
//
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _stuid;
//};
//
//// 如何设计一个不能被继承的类？
//class A
//{
//private:
//	A()
//	{}
//};
//
//class B : public A
//{};
//
//int main()
//{
//	//Student s1("jack", 1);
//	//Student s;
//
//	//Student s2(s1);
//
//	//Student s3("rose", 2);
//
//	//s1 = s3;
//	//B b;
//
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//class Person
//{
//public:
//	Person() { ++_count; }
//public:
//	string _name; // 姓名
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	p._name = "jack";
//	s._name = "rose";
//
//	p._count = 1;
//	s._count = 2;
//
//	Person::_count++;
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//
//
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

// 内存对象模型（对象在内存中是怎么存的？）

//class A
//{
//public:
//	//int _a[10000];
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl; // 20
//
//	/*d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	d._a = 6;*/
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//private:
//	int _a;
//	char _ch;
//};
//int main()
//{
//	//cout << sizeof(Person) << endl;
//
//	return 0;
//}

class Person {
public:
	void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }

	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议这样使用*/
	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
};

void Func(Person* p)
{
	p->BuyTicket();
}

int main()
{
	Person ps;
	Student st;

	Func(&ps);
	Func(&st);

	return 0;
}