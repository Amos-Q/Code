#include <iostream>
using namespace std;

//int main()
//{
//	// Ȩ����С�ͷŴ�������������ú�ָ���
//	// Ȩ�޷Ŵ�  const���ܸ���const��constֻ�ܸ�const
//	const int a = 10;
//	//int& b = a;
//	const int& b = a;
//
//	// Ȩ�޵���С  ��const�ȿ��Ը���const��Ҳ���Ը�const
//	int c = 20;
//	int& d = c;
//	const int& e = c;
//
//	const int* cp1 = &a;
//	//int* p1 = cp1; // ���ܣ�����Ȩ�޵ķŴ�
//	
//	int* p2 = &c;
//	const int* cp2 = p2; // ���ԣ�����Ȩ�޵���С
//
//
//
//	// ������ԣ���������Ĺ���
//	const int x = 10;
//	int y = x;
//	int z = 20;
//	const int r = z;
//
//	return 0;
//}

// 1������������
//void swap(int r1, int r2)
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//void swap_c(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void swap_cpp(int& r1, int& r2)
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//
//int main()
//{
//int a = 0, b = 1;
//swap_c(&a, &b);
//
//swap_cpp(a, b);
//
//	int x = 10;
//	int& y = x;
//
//	return 0;
//}

// ����������ֵ
//int Count1()
//{
//	static int n = 0;
//	n++;
//
//	return n;
//}
//
//int& Count2()
//{
//	static int n = 0;
//	n++;
//
//	return n;
//}
//
//int main()
//{
//	const int& r1 = Count1();
//	int& r2 = Count2();
//
//	static int x = 0;
//	int& y = x;
//
//	return 0;
//}

//int Add1(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	const int& ret = Add1(1, 2);
//	Add1(3, 4);
//	cout << "Add1(1, 2) is :" << ret << endl;
//	return 0;
//}

//int& Add2(int a, int b)
//{
//	static int c = 1;
//	c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add2(1, 2);
//	//Add2(3, 4);
//	printf("hello world\n");
//	cout << "Add2(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
//struct A
//{ 
//	int a[10000];
//};
//
//// 40000byte
//
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//
//// ���÷���
//A& TestFunc2(){ return a;}
//
//void main()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}


#include <time.h>
struct A{ int a[10000]; };
void TestFunc1(A a){}

void TestFunc2(A& a){}

void main()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}