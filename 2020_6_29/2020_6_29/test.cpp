#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool HasPathCore(vector<vector<int>> data, int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &res) {
	bool hasPath = false;
	int rows = data.size();
	int cols = data[0].size();
	if (row == rows - 1 && col == cols - 1) {
		vector<int> cur(2);
		cur[0] = rows - 1, cur[1] = cols - 1;
		res.push_back(cur);
		return true;
	}
	if (row >= 0 && row < rows && col >= 0 && col < cols && data[row][col] == 0 && visited[row][col] == false) {
		visited[row][col] = true;
		vector<int> cur(2);
		cur[0] = row, cur[1] = col;
		res.push_back(cur);
		hasPath = HasPathCore(data, row, col - 1, visited, res) ||
			HasPathCore(data, row - 1, col, visited, res) ||
			HasPathCore(data, row + 1, col, visited, res) ||
			HasPathCore(data, row, col + 1, visited, res);
		if (!hasPath) {
			visited[row][col] = false;
		}
	}
	return hasPath;
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> data;
		vector<vector<bool>> visited;
		for (int i = 0; i < n; ++i) {
			vector<int> row;
			vector<bool> row2;
			for (int j = 0; j < m; ++j) {
				int temp;
				cin >> temp;
				row.push_back(temp);
				row2.push_back(false);
			}
			data.push_back(row);
			visited.push_back(row2);
		}
		vector<vector<int>> res;
		int pathlength = 0;
		if (HasPathCore(data, 0, 0, visited, res)) {
			for (int i = 0; i < res.size(); ++i) {
				vector<int> cur = res[i];
				cout << '(' << cur[0] << ',' << cur[1] << ')' << endl;
			}
		}
	}
	return 0;
}


//class Bonus {
//public:
//	int getMost(vector<vector<int> > board) {
//		int dp[6][6];
//		dp[0][0] = board[0][0];
//		for (int i = 1; i < 6; i++)
//			dp[0][i] = dp[0][i - 1] + board[0][i];
//		for (int i = 1; i < 6; i++)
//			dp[i][0] = dp[i - 1][0] + board[i][0];
//		for (int i = 1; i < 6; i++)
//		{
//			for (int j = 1; j < 6; j++)
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
//			}
//		}
//		return dp[5][5];
//	}
//};