#include <assert.h>
//namespace fxd
//{
//	class string
//	{
//	public:
//		string()
//			:_str(nullptr)
//		{}
//
//		string(char* str)
//			:_str(str)
//		{}
//
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//	private:
//		char* _str;
//	};
//
//	void test_string1()
//	{
//		string s1("hello");
//		string s2;
//
//		for (size_t i = 0; i < s1.size(); ++i)
//		{
//			s1[i] += 1;
//			cout << s1[i] << " ";
//		}
//		cout << endl;
//	}
//}


//namespace fxd
//{
//	// 面试题：实现一个简单的string  -> 深浅拷贝问题
//	class string
//	{
//	public:
//	/*	string()
//			:_str(new char[1])
//		{
//			_str[0] = '\0';
//		}
//
//		string(char* str)
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}*/
//
//		string(char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		// string s2(s1)  -> 深拷贝
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// 实现一下
//		// s1 = s3
//		// s1 = s1
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				char* tmp = new char[strlen(s._str) + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				_str = tmp;
//			}
//
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//	};
//
//	void test_string1()
//	{
//		string s1("hello");
//		string s2;
//
//		for (size_t i = 0; i < s1.size(); ++i)
//		{
//			s1[i] += 1;
//			cout << s1[i] << " ";
//		}
//		cout << endl;
//
//		for (size_t i = 0; i < s2.size(); ++i)
//		{
//			s2[i] += 1;
//			cout << s2[i] << " ";
//		}
//		cout << endl;
//	}
//
//	void test_string2()
//	{
//		string s1("hello");
//		string s2(s1);
//
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//
//		string s3("world");
//		s1 = s3;
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//	}
//}

namespace fxd
{
	// 实现一个支持增删查改的string
	class string
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		// string s2("hello");
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// 拷贝构造和赋值大家作业完成

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}

		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}

		// 将容量扩展到n
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}

				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		void push_back(char ch)
		{
			// 空间满了则进行增容
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity* 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			// 空间不够增容
			size_t len = strlen(str);
			if (_size + len > _capacity)  // 注意这不能按2倍去增，因为不一定够
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		// s1 += 'a'
		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}

		// s1 += "aaaaaa"
		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}

			int end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);

			// 1.如果空间不够先进行增容
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// 挪动数据
			int end = _size;
			while (end >= pos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			/*for (size_t i = 0; i < len; ++i)
			{
			_str[pos++] = str[i++];
			}*/
			strncpy(_str + pos, str, len);

			_size += len;

			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len >= _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[i-len] = _str[i];
					++i;
				}

				_size -= len;
			}

			return *this;
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			char* p = strstr(_str, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}

		// s1 < s2
		bool operator<(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}

		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
	private:
		char*   _str;
		size_t  _size;     // 已经有多少个有效字符
		size_t  _capacity; // 能存多少个有效字符  \0不是有效字符

		static size_t npos;
	};

	size_t string::npos = -1;

	// getline
	istream& operator>>(istream& in, string& s)
	{
		while (1)
		{
			char ch;
			//in >> ch;
			ch = in.get();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}

		return in;
	}

	ostream& operator<< (ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			cout << s[i];
		}

		return out;
	}

	void test_string1()
	{
		string s1;
		string s2("hello");
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		// 三种遍历方式
		for (size_t i = 0; i < s2.size(); ++i)
		{
			s2[i] += 1;
			cout << s2[i] << " ";
		}
		cout << endl;

		string::iterator it2 = s2.begin();
		while (it2 != s2.end())
		{
			*it2 -= 1;
			cout << *it2 << " ";
			++it2;
		}
		cout << endl;

		// 范围for是由迭代器支持的，也就是说这段代码最终会被编译器替换成迭代器
		// iterator begin() end()
		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello");
		s1.push_back(' ');
		s1.push_back('w');
		s1.push_back('o');
		s1.append("rld xxxxxxxxxxxxxxxxxxxxxxxxx");
		cout << s1 << endl;

		string s2;
		s2 += "hello";
		s2 += ' ';
		s2 += "world";
		cout << s2 << endl;
	}

	void test_string3()
	{
		string s1("hello");
		s1.insert(1, 'x');
		s1.insert(1, "xyz");
		//cout << s1 << endl;

		string s2("hello");
		s2.reserve(10);
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;

		s2.resize(8, 'x');
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;;

		s2.resize(18, 'a');
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;

		s2.resize(2);
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;
	}

	void test_string4()
	{
		string s1("helloworld");
		s1.erase(5, 2);
		cout << s1 << endl;

		s1.erase(5, 4);
		cout << s1 << endl;

		string s2("abcdabcdef");
		cout << s2.find("cde") << endl;
		cout << s2.find("cdex") << endl;
	}

	void test_string5()
	{
		string s;
		cin >> s;

		cout << s;
	}
}

namespace fxd_copy
{
	// C++ 的一个常见面试题是让你实现一个 String 类，
	// 限于时间，不可能要求具备 std::string 的功能，但至少要求能正确管理资源。 -> 构造+析构+拷贝+operator=
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}

		// 深拷贝 - 传统写法
		// string s2(s1)
		/*	string(const string& s)
				:_str(new char[strlen(s._str)+1])
				{
				strcpy(_str, s._str);
				}*/

		// 深拷贝 - 现代写法  -- 简洁
		// string s2(s1)
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		// s1 = s2;
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				swap(_str, tmp._str);
			}

			return *this;
		}*/

		// s1 = s2;
		// 这里最巧的就是传值操作
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		/*	string& operator=(const string& s)
			{
			if (this != &s)
			{
			char* tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			}
			return *this;
			}*/
		
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		size_t size()
		{
			return strlen(_str);
		}

		char& operator[](size_t i)
		{
			return _str[i];
		}
	private:
		char* _str;
	};

	void test_string1()
	{
		string s1("hello");
		string s2(s1);
		for (size_t i = 0; i < s2.size(); ++i)
		{
			cout << s2[i];
		}
		cout << endl;

		string s3("world");
		s1 = s3;
		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i];
		}
		cout << endl;
	}
}
