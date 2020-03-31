#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdio.h>

using namespace std;

namespace f
{
	int printf = 2;
	void f()
	{
		::printf("%d", f::printf);
	}
}

int main()
{
	f::f();
	system("pause");
}

// 例4中的头文件header1(头文件1，没其文件名为cc8-4-h1.h)

#include

#include

using namespace std;

class Student //声明Student类
{
public:

    Student(int n, string nam, int a)
    {
        num = n;
        name = nam;
        age = a;
    }

    void get_data();

private:

    int num;

    string name;

    int age; 
};

void Student::get_data() //成员函数定义
{
    cout<<num<<" "<<name<<" "<<age<<endl; 
}

double fun(double a,double b)//定义全局函数(即外部函数)
{
    return sqrt(a+b);
}

// 在 main函数所在的文件中包含头文件headerl.h：

#include

using namespace std;

#include "header1.h" //注意要用双引号，因为文件一般是放在用用户目录中的

int main()
{
    Student stud1(101,"Wang",18); //定义类对象studl

    stud1.get_data();

    cout<<fun(5,3)<<endl;

    return 0; 
}
