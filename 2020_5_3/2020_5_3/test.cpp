#define _CRT_SECURE_NO_WARNINGS 1
//#include <map>
//map<int, string> mapStudent;
//
///*����*/
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
///*�������*/
////method 1 : pair���� (VC-��pragma warning (disable:4786) )
//mapStudent.insert(pair<int, string>(1, "1111");
//mapStudent.insert(pair<int, string>(2, "2222");
//mapStudent.insert(pair<int, string>(3, "3333");
//
////method 2: value_type����
//mapStudent.insert(map<int, string>::value_type(1, "1111"));
//mapStudent.insert(map<int, string>::value_type(2, "2222"));
//mapStudent.insert(map<int, string>::value_type(3, "3333"));
//
////method 3: �������
//mapStudent[1] = "1111";
//mapStudent[2] = "2222";
//mapStudent[3] = "3333";
//// ��һ�ֺ͵ڶ��ַ���Ч��һ��, ��keyһ����ʱ��, ���ܲ���
////������ķ�ʽ����, ���渲��ǰ���ֵ
//
////����жϲ���ɹ�
//pair<map<int, string>::iterator, bool> insertState;
//insertState = mapStudent.insert(map<int, string>::value_type(1, "1111"));
//if (insertState.second == true) //insert success!
//else // insert fail!
//
//
///*����*/
//map<int, string>::iterator iter;
//iter = mapStudent.find(1);
//if (iter != mapStudent.end()) cout << iter->second << endl;
//else cout << "Can't find" << endl;
//
///*ɾ��*/
//
////method 1
//map<int, string>::iterator iter;
//iter = mapStudent.find(1);
//mapStudent.erase(iter);
//
//// method 2
//int n = mapStudent.erase(1);//���ɾ���˻᷵��1�����򷵻�0  
//
//mapStudent.erase(mapStudent.begin(), mapStudent.end());  //һ�´��������map���  
#include<set>    
#include<iostream>    
using namespace std;
int main()
{
	set<int>s;
	set<int> s1{ 9,8,1,2,3,4,5,5,5,6,7,7 }; //�Զ����򣬴�С����,�޳���ͬ��
	set<string> s2{ "hello","sysy","school","hello" }; //�ֵ�������
	s1.insert(9); //�����ֵ�ˣ�do nothing
	s2.insert("aaa"); //û������ַ�������Ӳ�������

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



	//s.end()û��ֵ
	cout << "s.begain()   " << *s.begin() << endl;
	//lower_bound()--����ָ����ڣ�����ڣ�ĳֵ�ĵ�һ��Ԫ�صĵ�����
	cout << "lower_buond  3  " << *s.lower_bound(3) << endl;

	//upper_bound()--���ش���ĳ��ֵԪ�صĵ�����
	cout << "upper_bound  3  " << *s.upper_bound(3) << endl;

	//find()--����һ��ָ�򱻲��ҵ�Ԫ�صĵ�����
	cout << "find()  3   " << *s.find(3) << endl;
	int a[] = { 1,2,3 };
	//Example:
	/*set<int> s1(a,a+3);
	set<int>::iterator iter;
	if((iter = s1.find(2)) != s1.end())
	{
		cout<<*iter<<endl;//���Ϊ2
	}
	*/

	cout << "s.size()  " << s.size() << endl;
	return 0;
	/*ɾ��*/
	s.erase(iterator), ɾ����λ��iteratorָ���ֵ
		s.erase(first, second), ɾ����λ��first��second֮���ֵ
		s.erase(key_value), ɾ����ֵkey_value��ֵ


}