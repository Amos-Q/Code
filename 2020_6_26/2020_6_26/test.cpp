#define _CRT_SECURE_NO_WARNINGS 1

//class Solution {
//private:
//	bool isPath(char *matrix, vector<char> flags, char* str, int x, int y, int rows, int cols)
//	{
//		if (x < 0 || x >= rows || y < 0 || y >= cols) //越界的点
//			return false;
//		if (matrix[x*cols + y] == *str  &&  flags[x*cols + y] == 0)
//		{
//			flags[x*cols + y] = 1;
//			if (*(str + 1) == 0)  // 字符串结尾了（最后一个满足的）
//				return true;
//			bool condition = isPath(matrix, flags, (str + 1), x, y - 1, rows, cols) ||
//				isPath(matrix, flags, (str + 1), x - 1, y, rows, cols) ||
//				isPath(matrix, flags, (str + 1), x, y + 1, rows, cols) ||
//				isPath(matrix, flags, (str + 1), x + 1, y, rows, cols);
//			if (condition == false)
//				flags[x*cols + y] = 0;
//			return condition;
//		}
//		else
//			return false;
//	}
//public:
//	bool hasPath(char* matrix, int rows, int cols, char* str)
//	{
//		vector<char> flags(rows*cols, 0);
//		bool condition = false;
//		for (int i = 0; i < rows; i++)
//			for (int j = 0; j < cols; j++)
//			{
//				condition = (condition || isPath(matrix, flags, str, i, j, rows, cols));
//			}
//		return condition;
//	}
//};


//class Solution {
//public:
//	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
//	{
//		int count = num.size() - size + 1;
//		vector<int> result;
//		if (size == 0 || num.size() == 0) {
//			return result;
//		}
//		for (int i = 0; i < count; i++) {
//			int max_number = *max_element(num.begin() + i, num.begin() + size + i);
//			result.push_back(max_number);
//		}
//		return result;
//	}
//};


//思路：二叉搜索树按照中序遍历的顺序打印出来正好就是排序好的顺序。
//     所以，按照中序遍历顺序找到第k个结点就是结果。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
	int count = 0;
public:
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
		if (pRoot) {
			TreeNode *ret = KthNode(pRoot->left, k);
			if (ret) return ret;
			if (++count == k) return pRoot;
			ret = KthNode(pRoot->right, k);
			if (ret) return ret;
		}
		return nullptr;
	}
};
