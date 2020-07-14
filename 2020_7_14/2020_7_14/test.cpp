#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int sum = 0;
//
//void Sum(vector<vector<char>> &v, int x, int y)
//{
//	if (v[x][y] == '#')
//		return;
//	sum++;
//	v[x][y] = '#';
//	Sum(v, x - 1, y);
//	Sum(v, x + 1, y);
//	Sum(v, x, y - 1);
//	Sum(v, x, y + 1);
//}
//
//void Judge(vector<vector<char>> &v)
//{
//	int x, y;
//	for (int i = 1; i < v.size() - 1; i++)
//	{
//		for (int j = 1; j < v[i].size() - 1; j++)
//		{
//			if (v[i][j] == '@')
//			{
//				x = i;
//				y = j;
//				break;
//			}
//			if (v[i][j - 1] == '#'&&v[i][j + 1] == '#'&&v[i + 1][j] == '#'&&v[i - 1][j] == '#')
//			{
//				v[i][j] = '#';
//			}
//		}
//	}
//	Sum(v, x, y);
//	cout << sum << endl;
//	sum = 0;
//}
//
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		vector<vector<char>> v((m + 2), vector<char>((n + 2), '#'));
//		for (int i = 1; i < m + 1; i++)
//		{
//			for (int j = 1; j < n + 1; j++)
//			{
//				cin >> v[i][j];
//			}
//		}
//		Judge(v);
//	}
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int N, M, K;
//double waysum = 0;
//double worrysum = 0;
//
//void Sum(vector<vector<int>> vv, int x, int y)
//{
//	if (x > N || y > M)
//		return;
//	if (x == N && y == M)
//		waysum++;
//	if (vv[x][y] == 1)
//		worrysum++;
//	Sum(vv, x + 1, y);
//	Sum(vv, x, y + 1);
//}
//
//int main()
//{
//	while (cin >> N >> M >> K)
//	{
//		vector<vector<int>> vv(N + 1, vector<int>(M + 1, 0));
//		for (int i = 0; i < K; i++)
//		{
//			int x, y;
//			cin >> x >> y;
//			vv[x][y] = 1;
//		}
//		Sum(vv, 1, 1);
//		printf("%.2f\n", worrysum / waysum);
//		waysum = 0;
//		worrysum = 0;
//	}
//}


#include <iostream>
#include <cstring>
using namespace std;
int map[26][26];
double dp[26][26];
int N, M, K;
void init()
{
	memset(map, 0, sizeof(map));
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			dp[i][j] = 0;
}
int judge(int x, int y)
{
	return x <= N && x >= 1 && y <= M && y >= 1;
}
int main()
{
	while (scanf("%d%d%d", &N, &M, &K) != EOF)
	{
		init();
		for (int i = 0; i < K; i++)
		{
			int x;
			int y;
			scanf("%d%d", &x, &y);
			map[x][y] = 1;
		}
		dp[1][1] = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] == 1)
					dp[i][j] = 0;
				if (judge(i + 1, j) && judge(i, j + 1))
				{
					dp[i + 1][j] += dp[i][j] * 0.5;
					dp[i][j + 1] += dp[i][j] * 0.5;
				}
				else if (judge(i + 1, j))
					dp[i + 1][j] += dp[i][j];
				else if (judge(i, j + 1))
					dp[i][j + 1] += dp[i][j];

			}
		}
		printf("%.2lf\n", dp[N][M]);
	}
	return 0;
}