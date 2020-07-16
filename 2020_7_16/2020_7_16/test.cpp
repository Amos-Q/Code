#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <math.h>
//using namespace std;
//int len = 0;
//
//int Len(string s1, string s2, int l1, int l2)
//{
//	int i = 0;
//	while (i < s2.size())
//	{
//		if (s1[i] == s2[i])
//		{
//			i++;
//		}
//		else if (s1[i] < s2[i])
//		{
//			len += (s2[i] - s1[i])*pow(26, (l2 - i - 1));
//			s1[i] = s2[i];
//		}
//		else
//		{
//			len -= (s1[i] - s2[i])*pow(26, (l2 - i - 1));
//			s1[i] = s2[i];
//		}
//	}
//	return len - 1;
//}
//
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		int len1, len2;
//		cin >> len1 >> len2;
//		cout << Len(s1, s2, len1, len2) << endl;
//		len = 0;
//	}
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string A, B;
	while (cin >> A >> B) {
		int aLength = A.length();
		int bLength = B.length();
		vector<vector<int> > dp(aLength, vector<int>(bLength, 0));
		// 初始化边界
		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i < aLength; i++) {
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < bLength; j++) {
			dp[0][j] = (A[0] == B[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}
		// 计算
		for (int i = 1; i < aLength; i++) {
			for (int j = 1; j < bLength; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (A[i] == B[j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[aLength - 1][bLength - 1] << endl;
	}

	return 0;
}