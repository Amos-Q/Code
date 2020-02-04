#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/*
Input  : apple Banana Sentence on
Output : on Banana sentence apple
*/

int main()
{
	vector<string> wordSet;
	string str;

	cout <<
		"Please enter a sentence that contains at least one word beginning with 'a 'and one word ending with 'n' : "
		<< endl;

	while (true)
	{
		cin >> str;
		if (str == "%") { break; }
		wordSet.push_back(str);
	}

	string Exchange1, Exchange2;
	int ExchangeNum1, ExchangeNum2;
	for (size_t i = 0; i < wordSet.size(); i++)
	{
		if (wordSet[i][0] == 'a')
		{
			Exchange1 = wordSet[i];
			ExchangeNum1 = i;
		}
		if (wordSet[i][wordSet[i].size() - 1] == 'n')
		{
			Exchange2 = wordSet[i];
			ExchangeNum2 = i;
		}
	}
	/*No error reporting procedure added*/
	wordSet[ExchangeNum2] = Exchange1;
	wordSet[ExchangeNum1] = Exchange2;

	for (size_t i = 0; i < wordSet.size(); i++)
	{
		cout << wordSet[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}