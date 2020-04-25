//#include <iostream>
//using namespace std;
//
//// 为什么C语言中已经有malloc/free，C++也可以用，但是还需要new/delete
//// 1、针对内置类型用new还是malloc都是一样的
//// 2、针对自定义类型,new还要调用构造函数完成初始化，delete还要调用析构函数完成清理
//// 结论：C++中建议使用new/delete
//
//// C
//typedef struct ListNode_C
//{
//	int _val;
//	struct ListNode_C* _next;
//	struct ListNode_C* _prev;
//}ListNode_C;
//
////typedef struct ListNode_C ListNode_C;
//ListNode_C* BuyListNode_C(int val)
//{
//	ListNode_C* node_c = (ListNode_C*)malloc(sizeof(ListNode_C));
//	node_c->_val = 1;
//	node_c->_next = NULL;
//	node_c->_prev = NULL;
//
//	return node_c;
//}
//
//void DestoryListNode_C(ListNode_C* node);
//
//struct ListNode_CPP
//{
//	int _val;
//	struct ListNode_CPP* _next; // 兼容C struct的用法
//	ListNode_CPP* _prev;        // 在CPP中，struct已经可以认为是类，和class一样，区别是默认访问限定符
//
//	ListNode_CPP(int val = 0)
//		:_val(val)
//		,_next(nullptr)
//		, _prev(nullptr)
//	{
//		cout << "ListNode_CPP(int val = 0)" << endl;
//	}
//
//	~ListNode_CPP()
//	{
//		cout << "~ListNode_CPP()" << endl;
//	}
//};
//
////int main()
////{
////	int* p1 = (int*)malloc(sizeof(int));
////	int* p2 = new int;
////
////	ListNode_C* node1 = BuyListNode_C(1);
////	ListNode_C* node2 = BuyListNode_C(2);
////	ListNode_C* node3 = BuyListNode_C(3);
////
////	ListNode_CPP* node4 = new ListNode_CPP;
////	ListNode_CPP* node5 = new ListNode_CPP(5);
////
////	delete node4;
////	delete node5; 
////
////	return 0;
////}
//
//void f(int n)
//{
//	//Sum a[n];
//	//Sum* p = new Sum[10];
//}
//
//int main()
//{
//	ListNode_CPP a[10];
//	ListNode_CPP* p = new ListNode_CPP[10];
//	delete[] p;
//
//	return 0;
//}


#include <iostream>
using namespace std;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p3 = (A*)operator new(sizeof(A));
//
//	// operator new和malloc的区别是什么？
//	// 结论:使用方式都一样，处理错误的方式不一样
//	size_t size = 2;
//	void* p4 = malloc(size*1024*1024*1024);
//	cout << p4 << endl; // 失败返回0
//	//free(p4);
//
//	try
//	{
//		void* p5 = operator new(size * 1024 * 1024 * 1024);
//		cout << p5 << endl; // 失败抛异常  （面向对象处理错的方式）
//		//operator delete(p5);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// malloc
//	// operator new ==> malloc+失败抛异常实现
//	// new          ==> operator new + 构造函数
//	// new 比起malloc不一样的地方：1、调用构造函数初始化 2、失败了抛异常
//	// delete 比如free不一样的地方：1、调用析构函数清理
//	// operator free 和 free没区别，因为释放空间失败直接终止进程。 是因为要跟operator new成对出现才产生
//
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1); // 内存池
//		cout << "memory pool allocate" << endl;
//
//		return p;
//	}
//
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode; // 全局operator new + 构造函数
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//
//	// void PushBack(int val);
//
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//
//		delete _head;
//		_head = nullptr;
//	}
//
//private:
//	ListNode* _head;
//};
//
//int main()
//{
//	List l;
//
//	return 0;
//}
//
//int main()
//{
//	A* p1 = new A;
//	delete p1;
//	
//	// 想模拟上面的行为
//	// 显示调用了A的构造函数和析构函数
//	A* p2 = (A*)operator new(sizeof(A));
//	// 对已经存在的一块空间调用构造函数初始化. 定位new/replacement new
//	new(p2)A(10);  // new(空间的指针)类型(参数)
//
//	p2->~A();
//	operator delete(p2);
//
//	return 0;
//}

//int main()
//{
//	// 1G
//	char* p = new char[1024*1024*1024];
//	// 内存泄漏：p指向的空间不需要了，忘记或其他原因没有释放p指向的空间，就内存泄漏。
//	// 内存泄漏危害：长期运行的程序(游戏服务)，出现内存泄漏危害很大。或者设备的内存本身很小，也有危害。
//
//	return 0;
//}

#include <iostream>
using namespace std;

//int main()
//{
//	size_t n = 2;
//	try
//	{
//		void* p = new char[n * 1024 * 1024 * 1024];
//		cout << "new:" << p << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//
//// ...
//
//int main()
//{
//	int a = 0, b = 1;
//	Swap(a, b);
//	double c = 1.11, d = 2.22;
//	Swap(c, d);
//
//	return 0;
//}

// 泛型编程
// 模板 -> 写跟类型无关的代码
// 函数模板
// template<class T>
//template<typename T>    // 模板参数-》类型
//void Swap(T& x1, T& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}

// 下面调用的是否是同一个函数？
// 不是
// 这里我们不能调用函数模板，调用的是函数模板实例化生成的对应类型的函数
//int main()
//{
//	//int a = 0, b = 1;
//	//Swap(a, b);
//
//	//double c = 1.11, d = 2.22;
//	//Swap(c, d);
//
//	//char e = 'a', f = 'b';
//	//Swap(e, f);
//
//	return 0;
//}


// C语言如何实现一个Stack_C
typedef int STDateType;
struct Stack_C
{
	STDateType* _a;
	int  _size; // _top
	int  _capacity;
};

typedef struct Stack_C Stack_C;

void Stack_CInit(Stack_C* ps)
{}
void Stack_CDestory(Stack_C* ps)
{}
void Stack_CPush(Stack_C* ps, STDateType x)
{}
void Stack_CPop(Stack_C* ps)
{}
// ...

template<class T>
class Stack_CPP
{
public:
	Stack_CPP()
	{}

	~Stack_CPP()
	{}

	void Push(T x)
	{}

private:
	T* _a;
	int _size;
	int _capacity;
};

int main()
{
	// 1. 忘记初始化和销毁                    -> 构造函数+析构函数
	// 2. 没有封装，谁都可以修改结构体的数据  -> 类+访问限定符
	// 3. 如果想同时定义两个栈，一个栈存int，一个栈都double，做不到 -> 模板
	Stack_C st_c;
	Stack_CInit(&st_c);
	Stack_CPush(&st_c, 1);
	Stack_CPush(&st_c, 2);
	Stack_CPush(&st_c, 3);
	Stack_CPush(&st_c, 4);
	// 非法修改
	st_c._capacity = 0;
	Stack_CDestory(&st_c);

	Stack_CPP<int> st_cpp_int;
	st_cpp_int.Push(1);  // 实际我也是两个参数，有一个是隐含的this指针
	st_cpp_int.Push(2);
	st_cpp_int.Push(3);
	st_cpp_int.Push(4);
	//st_cpp_int._capacity = 0;

	Stack_CPP<double> st_cpp_double;
	st_cpp_double.Push(1.1);
	st_cpp_double.Push(2.2);

	return 0;
}