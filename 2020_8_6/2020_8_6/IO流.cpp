#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	virtual ~A(){cout << "~A()" << endl;}
};

class B : public A
{
public:
	virtual ~B(){cout << "~B()" << endl;}
};

//int main()
//{
//
//	//A* p = new A;
//	//delete p; // p->destructor()  +  operator delete(p)
//	// 期望p指向父类调父类的析构函数，指向子类调子类的析构函数
//
//	A* p = new B;
//	delete p; // p->destructor()  +  operator delete(p)
//	          // 期望p指向父类调父类的析构函数，指向子类调子类的析构函数
//
//	/*int a = 0;
//	scanf("%d", &a);
//	printf("%d", a);
//
//	cin >> a;  // cin是标准库中定义的istream 类型全局对象
//	cout << a; // cout是标准库中定义的ostream 类型全局对象
//	cin.operator>>(a);
//	cout.operator<<(a);
//	*/
//
//	int a = 1;
//	double b = 2.2;
//	// C++ cout和cin能自动识别对象类型，因为本质他是一个函数重载区分识别
//	cout << a << endl;
//	cout << b << endl;
//
//	string str;
//	while (cin >> str)  // 按ctrl+c结束
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}

#include<fstream>

//int main()
//{
//	ofstream ofs("test.txt");   // fopen(,"W")
//	ofs.put('x');               // fputc
//	ofs.write("111111", 3);     // fwrite
//	
//	ofs.close();
//
//	ifstream ifs("test.txt");   // fopen(,"R")
//	cout << ifs.get() << endl;  // fgetc
//	// ifs.read                 // fread
//
//	return 0;
//}

struct info
{
	string name;
	int age;
	int score;
};

//int main()
//{
//	// 读写一个结构体
//	// 用起来跟cout和cin类似，非常方便，且可读性好。
//	info win = { "小明", 18 };
//
//	ofstream ofs("test.txt");   // fopen(,"W")
//	ofs << win.name<<" ";  // ofs << win.name<<endl;
//	ofs << win.age;
//	ofs.close();
//
//	info rin;
//	ifstream ifs("test.txt");   // fopen(,"R")
//	ifs >> rin.name;
//	ifs >> rin.age;
//
//
//	return 0;
//}

#include<sstream>

int main()
{
	info win = { "小明", 18,  99 };
	// 序列化成字符串
	ostringstream ost;
	ost << win.name<<endl;  // ost << win.name<<" ";
	ost << win.age << endl;
	ost << win.score << endl;


	string str1 = ost.str();
	cout << str1 << endl;  
    // 网络中就可以把这个str1发送给另一端。

	// 网络另一端接收到以后就可以解析数据
	// 反序列化
	istringstream ist;
	ist.str(str1);
	info rin;
	ist >> rin.name;
	ist >> rin.age;
	ist >> rin.score;
}