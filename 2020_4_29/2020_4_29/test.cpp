#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1;
	string s2("Hello");
	string s3(s2,2);
	string s4("hello", 2);
	string s5(10, 'a');
	string s6(s2, 1, 4);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	system("pause");
	return 0;
}