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
//	// ����pָ��������������������ָ��������������������
//
//	A* p = new B;
//	delete p; // p->destructor()  +  operator delete(p)
//	          // ����pָ��������������������ָ��������������������
//
//	/*int a = 0;
//	scanf("%d", &a);
//	printf("%d", a);
//
//	cin >> a;  // cin�Ǳ�׼���ж����istream ����ȫ�ֶ���
//	cout << a; // cout�Ǳ�׼���ж����ostream ����ȫ�ֶ���
//	cin.operator>>(a);
//	cout.operator<<(a);
//	*/
//
//	int a = 1;
//	double b = 2.2;
//	// C++ cout��cin���Զ�ʶ��������ͣ���Ϊ��������һ��������������ʶ��
//	cout << a << endl;
//	cout << b << endl;
//
//	string str;
//	while (cin >> str)  // ��ctrl+c����
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
//	// ��дһ���ṹ��
//	// ��������cout��cin���ƣ��ǳ����㣬�ҿɶ��Ժá�
//	info win = { "С��", 18 };
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
	info win = { "С��", 18,  99 };
	// ���л����ַ���
	ostringstream ost;
	ost << win.name<<endl;  // ost << win.name<<" ";
	ost << win.age << endl;
	ost << win.score << endl;


	string str1 = ost.str();
	cout << str1 << endl;  
    // �����оͿ��԰����str1���͸���һ�ˡ�

	// ������һ�˽��յ��Ժ�Ϳ��Խ�������
	// �����л�
	istringstream ist;
	ist.str(str1);
	info rin;
	ist >> rin.name;
	ist >> rin.age;
	ist >> rin.score;
}