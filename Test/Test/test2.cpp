#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

//class string
//{
//public:
//	string(const char* str = "")
//	{
//		// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	~string()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//// ����
//void Teststring()
//{
//	string s1("hello bit!!!");
//	string s2(s1);
//}
//int main()
//{
//	Teststring();
//}

class T
{
public:
	virtual ~T()
	{

	}
private:
	int a;
};
static int s;

int main()
{
	//static int s;
	int A[10] = { 1,2,3,4,6 };
	cout << *A << endl;
	//cout << sizeof(T) << endl;
}