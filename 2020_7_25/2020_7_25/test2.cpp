#include<iostream>
#include<memory>
using namespace std;

#include"SmartPtr.h"

int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");

	return a / b;
}

void f1()
{
	/*int* p1 = new int;
	int* p2 = new int;
	int* p3 = new int*/;

	/*int* p = new int;
	try
	{
		cout << div() << endl;
	}
	catch (...)
	{
		delete p;
		throw;
	}
	delete p;*/

	SmartPtr<int> sp1(new int);
	*sp1 = 10;

	SmartPtr<pair<int, int>> sp2(new pair<int, int>);
	sp2->first = 20;
	sp2->second = 30;

	cout << div() << endl;
}

//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

// 智能指针的坑
int x1()
{
	int* p1 = new int;
	int* p2 = p1;

	//bit::auto_ptr<int> ap1(new int);
	//bit::auto_ptr<int> ap2 = ap1;
	// *ap1 = 1; 悬空崩溃

	//bit::unique_ptr<int> up1(new int);
	//bit::unique_ptr<int> up2(up1);

	bit::shared_ptr<int> sp1(new int);
	bit::shared_ptr<int> sp2(sp1);

	bit::shared_ptr<int> sp3(new int);
	bit::shared_ptr<int> sp4(sp3);
	bit::shared_ptr<int> sp5(sp3);

	sp1 = sp4;


	return 0;
}

// shared_ptr的拷贝赋值时线程安全问题
// shared_ptr是否是线程安全的，答：注意这里问题的shared_ptr对象拷贝和析构++/--引用计数是否是安全的，库的实现中是安全的。
#include<thread>

int x2()
{
	bit::shared_ptr<int> sp(new int);
	cout << sp.use_count() << endl;
	int n =	10000;
	
	std::thread t1([&](){
		for (int i = 0; i < n; ++i)
		{
			bit::shared_ptr<int> sp1(sp);
		}
	});

	std::thread t2([&](){
		for (int i = 0; i < n; ++i)
		{
			bit::shared_ptr<int> sp2(sp);
		}
	});

	t1.join();
	t2.join();

	cout << sp.use_count() << endl;

	return 0;
}

struct ListNode
{
	int val;
	//ListNode* _next;
	//ListNode* _prev;
	//bit::shared_ptr<ListNode> _spnext;
	//bit::shared_ptr<ListNode> _spprev;

	bit::weak_ptr<ListNode> _spnext;
	bit::weak_ptr<ListNode> _spprev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

int x3()
{
	/*ListNode* n1 = new ListNode;
	ListNode* n2 = new ListNode;

	n1->_next = n2;
	n2->_prev = n1;

	delete n1;
	delete n2;*/

	bit::shared_ptr<ListNode> spn1(new ListNode);
	bit::shared_ptr<ListNode> spn2(new ListNode);

	cout << spn1.use_count() << endl;
	cout << spn2.use_count() << endl;

	// 循环引用
	spn1->_spnext = spn2; // 解决方式：使用weak_ptr，不增加引用计数
	spn2->_spprev = spn1;

	cout << spn1.use_count() << endl;
	cout << spn2.use_count() << endl;

	return 0;
}

// 定制删除器 -- （了解）
//#include<memory>
//class A
//{
//public:
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//
//template<class T>
//struct DeleteArry
//{
//	void operator()(T* pa)
//	{
//		delete[] pa;
//	}
//};
//
//struct Free
//{
//	void operator()(void* p)
//	{
//		cout << "free(p)" << endl;
//
//		free(p);
//	}
//};
//
//struct Fclose
//{
//	void operator()(FILE* p)
//	{
//
//		cout << "fclose(p)" << endl;
//
//		fclose(p);
//	}
//};
//
//int x4()
//{
//	std::shared_ptr<A> sp1(new A);
//	std::shared_ptr<A> sp2(new A[10], DeleteArry<A>());
//	std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), Free());
//	std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), Fclose());
//
//	return 0;
//}

// 智能指针是RAII思想的一种应用的体现
// 本质RAII就是借助构造函数和析构函数来搞事情，因为构造函数和析构函数的特点都是自动调用
#include<mutex>

// 使用RAII思想设计的锁管理守卫
template<class Lock>
class LockGuard
{
public:
	LockGuard(Lock& lock)
		:_lk(lock)
	{
		_lk.lock();
	}

	~LockGuard()
	{
		cout << "解锁" << endl;
		_lk.unlock();
	}

	LockGuard(LockGuard<Lock>&) = delete;
	LockGuard<Lock>& operator=(LockGuard<Lock>&) = delete;
private:
	Lock& _lk;  // 注意这里是引用
};


//void f()
//{
//	mutex mtx;
//	mtx.lock();
//
//	// func()   // 假设func函数有可能抛异常
//
//	mtx.unlock();
//}

void f()
{
	mutex mtx;
	LockGuard<mutex> lg(mtx);

	cout << div() << endl;   // 假设div函数有可能抛异常
}

int x5()
{
	//try
	//{
	//	f();
	//}
	//catch (exception& e)
	//{
	//	cout << e.what() << endl;
	//}
	char* p = new char[1024*1024*1024];


	return 0;
}

// 创建出的类对象只能在堆上
// 思路：正常创建对象一定要调用构造函数，或者拷贝构造
class HeapOnly
{
public:
	static HeapOnly* GetObj()
	{
		return new HeapOnly;
	}

private:
	HeapOnly()
	{}

	// C++98防拷贝：声明成私有
	//HeapOnly(const HeapOnly& );
public:
	// C++11 : 声明成delete
	HeapOnly(const HeapOnly&) = delete;
};

int x7()
{
	//HeapOnly hp;
	//HeapOnly* p = new HeapOnly;
	//HeapOnly* p = HeapOnly::GetObj();
	std::shared_ptr<HeapOnly> sp1(HeapOnly::GetObj());
	std::shared_ptr<HeapOnly> sp2(HeapOnly::GetObj());

	//HeapOnly copy(*sp1);


	return 0;
}

//class StackOnly
//{
//public:
//	static StackOnly GetObj()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//};

// 这种方案存在一定程序缺陷，无法阻止在数据段(静态区)创建对象
class StackOnly
{
public:
	void* operator new(size_t size) = delete;
};

int x8()
{
	StackOnly so;
	//StackOnly* p = new StackOnly;

	static StackOnly sso;


	return 0;
}

// 之前已经学过一些设计模式
// 迭代器模式 -- 基于面向对象三大特性之一的 封装设计出来的，用一个迭代器类封装以后，不暴露容器的结构的情况下，统一的方式访问修改容器中的数据。

// 适配器模式 -- 体现的是一种复用
// 还有一些常见的设计模式如：工厂模式、装饰器模式、观察者模式、单例模式...
// 一个类只能在全局(进程中)只有一个实例对象。
// 什么场景下使用？比如一个进程中有一个内存池，进程中的多线程需要内存都要到这个内存池中取，那么这个内存池的类就可以设计单例模式。

// 类的名称是随着你的场景给的，比如你的是内存池，那么你就定义成MemoryPool
#include<thread>
#include<vector>
#include<windows.h>

namespace lazy_man
{
	// 懒汉模式 -- 第一次获取对象时，再创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			//::Sleep(1000);  增加没加锁时出现线程不安全的条件（2个以上线程同时过了判断条件）

			// 双检查
			if (_pinst == nullptr)
			{
				//_mtx.lock();
				unique_lock<mutex> lock(_mtx);
				if (_pinst == nullptr)
				{
					_pinst = new Singleton;
				}
				//_mtx.unlock();
			}

			// ...

			return _pinst;
		}

		static void DelInstance()
		{
			//unique_lock<mutex> lock(_mtx);
			delete _pinst;
			_pinst = nullptr;
		}

		Singleton(const Singleton& s) = delete;

	private:
		Singleton()
		{}

		static Singleton* _pinst;
		static mutex _mtx;
	};

	// 1、如果要手动释放单例对象，可以调用DelInstance
	// 2、如果需要程序结束时，正常释放单例对象，可以加入下面的设计
	class GC
	{
	public:
		~GC()
		{
			Singleton::DelInstance();
		}
	};

	static GC gc;


	Singleton* Singleton::_pinst = nullptr;
	mutex Singleton::_mtx;

	int x()
	{
		//Singleton s1;
		//Singleton s2;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//Singleton copy(*Singleton::GetInstance());

		vector<std::thread> vthreads;
		int n = 100;
		for (int i = 0; i < n; ++i)
		{
			vthreads.push_back(std::thread([]()
			{
				//cout << std::this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}

		return 0;
	}
}

namespace hungry_man
{
	// 饿汉模式  一开始(main函数之前)就创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_inst;
		}

		Singleton(const Singleton&) = delete;
	private:
		Singleton()
		{}

		static Singleton _inst;
	};

	Singleton Singleton::_inst;
	// static对象是在main函数之前创建的，这会只有主线程，所以不存在线程安全。


	int x()
	{
		//Singleton s1;
		//Singleton s2;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//Singleton copy(*Singleton::GetInstance());

		vector<std::thread> vthreads;
		int n = 10;
		for (int i = 0; i < n; ++i)
		{
			vthreads.push_back(std::thread([]()
			{
				//cout << std::this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}

		return 0;
	}
}

//int main()
//{
//	hungry_man::x();
//
//	return 0;
//}

// 总结对比一下饿汉和懒汉的区别
// 1、懒汉模式需要考虑线程安全和释放的问题，实现相对更复杂，饿汉模式不存在以上问题，实现简单
// 2、懒汉是一种懒加载模式需要时在初始化创建对象，不会影响程序的启动。饿汉模式则相反，程序启动阶段就创建初始化实力对象，会导致程序启动慢，影响体验。
// 3、如果有多个单例类，假设有依赖关系(B依赖A)，要求A单例先创建初始化，B单例再创建初始化，那么就不能饿汉，因为无法保证创建初始化顺序，这时用懒汉我们就可以手动控制。

// 总结一下：实际中懒汉模式还是更实用一些



/////////////////////////////////////////////////////////////////////////////
// 类型转换
class A
{
public:
	virtual void f()
	{}

	int _a;
};

class B : public A
{
public:
	int _b;
};


//A* pa = &a;
//f_cast(pa);
//
//pa = &b;
//f_cast(pa);

void f_cast(A* pa)
{
	// 如果想区分pa是指向父类，还是子类对象？
	// 如果pa是指向子类对象，则转换成功，
	// 如果pa指向父类对象则转换失败返回nullptr 
	B* pb = dynamic_cast<B*>(pa);
	//B* pb = (B*)pa;
	if (pb != nullptr)
	{
		cout << "转换成功：pa指向子类对象" << endl;
		pb->_a = 1;
		pb->_b = 2;
	}
	else
	{
		cout << "转换失败：pa指向父类对象" << endl;
	}
}

int x10()
{
	int i = 1;
	double d = 8.88;
	i = d; // c语言支持相近类型的隐式类型转换 (相近类型，也就是意义相似的类型)
	cout << i << endl;

	int* p = nullptr;
	p = (int*)i; // c语言支持相近类型的强制类型转换 (不相近类型，也就是意义差别很大的类型)
	cout << p << endl;

	// C++ 兼容C语言留下来的隐式转换和显示转换，但是C++觉得C语言做得不规范，C++想规范一下
	// 标准C++为了加强类型转换的可视性，引入了四种命名的强制类型转换操作符
	// static_cast、reinterpret_cast、const_cast、dynamic_cast
	d = static_cast<double>(i);     // 对应c语言隐式类型转换 （相近类型）
	p = reinterpret_cast<int*>(i);  // 对应c语言大部分强制类型转换（不相近类型）

	volatile const int ci = 10;
	//const int ci = 10;
	int* pi = const_cast<int*>(&ci); // 对应c语言强制类型转换中去掉const属性的（不相近类型）
	//int* pi = (int*)&ci;
	*pi = 20;
	cout << *pi << endl;
	cout << ci << endl; // 这里打印是10是因为ci存储的内存被改了，但是ci被放进了寄存器，这里去寄存器中取，还是10.本质这是由于编译器对const对象存取优化机制导致。
	// 想要禁止编译器做这个优化，每次都到内存中去取值，就把volatile加上

	A a;
	B b;

	// C++中子类对象可以赋值给父类的对象、指针、引用，这个过程中会发生切片，这个过程是
	// 语法天然支持的，这个叫向上转换，都可以成功。

	// 如果是父类的指针或者引用，传给子类的指针，这个过程叫向下转换，这个过程有可能能成功
	// 要看具体情况。
	// 最后需要注意的是：dynamic_cast向下转换只能针对继承中的多态类型(父类必须包含虚函数)

	// 因为dynamic_cast如何识别父类的指针是指向父类对象还是子类对象的呢？dynamic_cast的原理
	// dynamic_cast通过去虚表的上方存储的标识信息，来判断指向父类对象还是子类对象。
	A* pa = &a;
	f_cast(pa);

	pa = &b;
	f_cast(pa);

	return 0;
}

// 总结一下：尽量少用类型转换，如果要用尽量规范一点，且知道转换后会有什么影响

class AA
{
public:
	//AA(int a)
	explicit AA(int a)
	{
		cout << "AA(int a)" << endl;
	}

	//AA(int a1, int a2)
	explicit AA(int a1, int a2)
	{
		cout << "AA(int a1, int a2)" << endl;
	}

	AA(const AA& a)
	{
		cout << "AA(const AA& a)" << endl;
	}
private:
	int _a1;
	int _a2;
};

int main()
{
	AA aa1(1);

	// 隐式转换-> A tmp(1); A a2(tmp)，再优化成直接构造
	AA aa2 = 1;
	AA aa3 = { 1, 2 }; // C++11
}