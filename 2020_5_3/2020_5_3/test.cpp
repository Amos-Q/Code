#define _CRT_SECURE_NO_WARNINGS 1
//#include <map>
//map<int, string> mapStudent;
//
///*遍历*/
////method 1
//map<int, string>::iterator iter;
//for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
//	cout << iter->first << " " << iter->second << endl;
//}
//
////method 2
//int mapSize = mapStudent.size();
//for (int i = 1; i <= mapSize; i++) {
//	cout << mapStudent[i] << endl;
//}
//
//
///*插入操作*/
////method 1 : pair插入 (VC-＃pragma warning (disable:4786) )
//mapStudent.insert(pair<int, string>(1, "1111");
//mapStudent.insert(pair<int, string>(2, "2222");
//mapStudent.insert(pair<int, string>(3, "3333");
//
////method 2: value_type数据
//mapStudent.insert(map<int, string>::value_type(1, "1111"));
//mapStudent.insert(map<int, string>::value_type(2, "2222"));
//mapStudent.insert(map<int, string>::value_type(3, "3333"));
//
////method 3: 数组插入
//mapStudent[1] = "1111";
//mapStudent[2] = "2222";
//mapStudent[3] = "3333";
//// 第一种和第二种方法效果一样, 当key一样的时候, 不能插入
////而数组的方式可以, 后面覆盖前面的值
//
////如何判断插入成果
//pair<map<int, string>::iterator, bool> insertState;
//insertState = mapStudent.insert(map<int, string>::value_type(1, "1111"));
//if (insertState.second == true) //insert success!
//else // insert fail!
//
//
///*查找*/
//map<int, string>::iterator iter;
//iter = mapStudent.find(1);
//if (iter != mapStudent.end()) cout << iter->second << endl;
//else cout << "Can't find" << endl;
//
///*删除*/
//
////method 1
//map<int, string>::iterator iter;
//iter = mapStudent.find(1);
//mapStudent.erase(iter);
//
//// method 2
//int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0  
//
//mapStudent.erase(mapStudent.begin(), mapStudent.end());  //一下代码把整个map清空  
#include<set>    
#include<iostream>    
using namespace std;
int main()
{
	set<int>s;
	set<int> s1{ 9,8,1,2,3,4,5,5,5,6,7,7 }; //自动排序，从小到大,剔除相同项
	set<string> s2{ "hello","sysy","school","hello" }; //字典序排序
	s1.insert(9); //有这个值了，do nothing
	s2.insert("aaa"); //没有这个字符串，添加并且排序

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		printf("%d\n", *it);
	}



	//s.end()没有值
	cout << "s.begain()   " << *s.begin() << endl;
	//lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
	cout << "lower_buond  3  " << *s.lower_bound(3) << endl;

	//upper_bound()--返回大于某个值元素的迭代器
	cout << "upper_bound  3  " << *s.upper_bound(3) << endl;

	//find()--返回一个指向被查找到元素的迭代器
	cout << "find()  3   " << *s.find(3) << endl;
	int a[] = { 1,2,3 };
	//Example:
	/*set<int> s1(a,a+3);
	set<int>::iterator iter;
	if((iter = s1.find(2)) != s1.end())
	{
		cout<<*iter<<endl;//输出为2
	}
	*/

	cout << "s.size()  " << s.size() << endl;
	return 0;
	/*删除*/
	s.erase(iterator), 删除定位器iterator指向的值
		s.erase(first, second), 删除定位器first和second之间的值
		s.erase(key_value), 删除键值key_value的值


}