#define Min1(a,b) (a < b ? a : b)
#define Min(a, b, c) (a < b ? Min1(a ,c) : Min1(b , c))
//#include <iostream>
//#include <string>
//using namespace std;
//
//int Sum(string str1, string str2, int k1, int k2, int len1, int len2) {
//	if (len1 - k1 == 0)
//		return len2 - k2;
//	else if (len2 - k2 == 0)
//		return len1 - k1;
//	else 
//	{
//		if (str1[k1] == str2[k2])
//			return Sum(str1, str2, k1 + 1, k2 + 1, len1, len2);
//		else 
//		{ 
//			int a = Sum(str1, str2, k1 + 1, k2 + 1, len1, len2) + 1;
//			int b = Sum(str1, str2, k1, k2 + 1, len1, len2) + 1;
//			int c = Sum(str1, str2, k1 + 1, k2, len1, len2) + 1;
//			return Min(a, b, c);
//		}
//	}
//}
//
//int main() {
//	string str1;
//	string str2;
//	while (cin >> str1 >> str2)
//		cout << Sum(str1, str2, 0, 0, str1.size(), str2.size());
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Judge(char s1, char s2)
{
	if (s1 == s2)
		return 0;
	else
		return 1;
}

int Sum(string s1, string s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= len2; j++) {
		dp[0][j] = j;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = Min((dp[i - 1][j] + 1), (dp[i][j - 1] + 1), (dp[i - 1][j - 1] + Judge(s1[i - 1], s2[j - 1])));
		}
	}
	return dp[len1][len2];
}

int main() 
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
		cout << Sum(s1, s2) << endl;
	system("pause");
	return 0;
}