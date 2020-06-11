#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Judge(string s)
{
	vector<int> v;
	v.resize(57);
	int i = 0;
	while (i < s.size())
	{
		if (v[s[i] - 'A'] == 0)
		{
			v[s[i] - 'A']++;
			cout << s[i];
		}
		i++;
	}
}

int main()
{
	string str;
	cin >> str;
	Judge(str);
	system("pause");
	return 0;
}