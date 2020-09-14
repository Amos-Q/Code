#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//int Judge(string s)
//{
//	int flagint = 0;
//	int flagchar = 0;
//	int flagA = 0;
//	int flaga = 0;
//	if (s.size() < 8 || s.size() > 120)
//		return 1;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] >= '0' && s[i] <= '9')
//		{
//			flagint = 1;
//		}
//		else if (s[i] >= 'a' && s[i] <= 'z')
//		{
//			flaga = 1;
//		}
//		else if (s[i] >= 'A' && s[i] <= 'Z')
//		{
//			flagA = 1;
//		}
//		else
//			flagchar = 1;
//	}
//	if (flagint == 1 && flagchar == 1 && flagA == 1 && flaga == 1)
//		return 0;
//	else
//		return 2;
//
//}
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		cout << Judge(s) << endl;
//	}
//}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> vv{ {'A','B','C','E'},
{'S','F','C','S'},
{'A','D','E','E'} };

//bool dfs(vector<vector<char>> &board, string word, int i, int j, int w) {
//	if (i < 0 || i >= board.size() || j < 0 || j <= board[0].size() || board[i][j] != word[w])
//		return false;
//	if (w == word.size() - 1)
//		return true;
//	char temp = board[i][j];
//	board[i][j] = 0;
//	if (dfs(board, word, i - 1, j, w + 1) || dfs(board, word, i + 1, j, w + 1) || dfs(board, word, i, j - 1, w + 1) || dfs(board, word, i, j + 1, w + 1)) {
//		return true;
//	}
//	board[i][j] = temp;
//	return false;
//}
//
//bool Judge(vector<vector<char>> &board, string word) {
//	for (int i = 0; i < board.size(); i++) {
//		for (int j = 0; j < board[0].size(); j++) {
//			if (dfs(board, word, i, j, 0))
//				return true;
//		}
//	}
//	return false;
//}
//int main()
//{
//	string word;
//	while (cin >> word)
//	{
//		cout << Judge(board, word) << endl;
//	}
//}

bool dfs(string s,int i,int j,int x)
{
	if (vv[i][j] != s[x])
		return false;
	if (x + 1 >= s.size())
		return true;
	char tmp = vv[i][j];
	vv[i][j] = '0';
	x++;
	if ((j > 0 && dfs(s, i, j - 1, x)) || (j + 1 < vv[0].size() && dfs(s, i, j + 1, x)) || (i > 0 && dfs(s, i - 1, j, x)) || (i + 1 < vv.size() && dfs(s, i + 1, j, x)))
		return true;
	vv[i][j] = tmp;
	return false;
}

bool Judge(string s)
{
	if (vv.size() == 0 || vv[0].size() == 0)
	{
		return false;
	}
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[0].size(); j++)
		{
			if (vv[i][j] == s[0])
			{
				if (dfs(s, i, j, 0))
					return "true";
			}
		}
	}
	return "false";
}

int main()
{
	string word;
	while (cin >> word)
	{
		cout << Judge(word) << endl;
	}
}