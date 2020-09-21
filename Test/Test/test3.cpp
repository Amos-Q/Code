//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
using namespace std;
////
////int main()
////{
////	int n;
////	while (cin >> n)
////	{
////		string s;
////		getchar();
////		getline(cin,s);
////		if (n >= s.size())
////		{
////			reverse(s.begin(), s.end());
////			cout << s << endl;
////		}
////		else
////		{
////			int i = 0;
////			while(i < s.size()-n)
////			{
////				reverse(s.begin() + i, s.begin() + i + n);
////				i += n;
////			}
////			reverse(s.begin() + i, s.end());
////			cout << s << endl;
////		}
////	}
////}
//
////int main()
////{
////	int T;
////	while (cin >> T)
////	{
////		for (int i = 0; i < T; i++)
////		{
////			vector<int> c(3);
////			for (int j = 0; j < 3; j++)
////			{
////				cin >> c[j];
////			}
////			vector<vector<int>> cc(c[1], vector<int>(3));
////			for (int x = 0; x < c[1]; x++)
////			{
////				for (int y = 0; y < 3; y++)
////				{
////					cin >> cc[x][y];
////				}
////			}
////			set<int> s;
////			for (int x = 0; x < c[0]; x++)
////			{
////				s.insert(x + 1);
////			}
////			set<int> st;
////			for (int x = 0; x < c[1]; x++)
////			{
////				if (cc[x][2] <= c[2])
////				{
////					if (st.empty())
////					{
////						st.insert(cc[x][0]);
////						st.insert(cc[x][1]);
////					}
////					else
////					{
////						for (auto e : st)
////						{
////							for (int p = 0; p <= x; p++)
////							{
////								if (e == cc[p][0] || e == cc[p][1])
////								{
////									st.insert(cc[x][0]);
////									st.insert(cc[x][1]);
////								}
////							}
////						}
////					}
////				}
////			}
////
////			if (s.size() != st.size())
////				cout << "No" << endl;
////			else
////			{
////				int flag = 1;
////				set<int>::iterator it1;
////				set<int>::iterator it2;
////				for (it1 = s.begin(), it2 = st.begin(); it1 != s.end(); it1++, it2++)
////				{
////					if (*it1 != *it2)
////					{
////						flag = -1;
////						cout << "No" << endl;
////						break;
////					}
////				}
////				if (flag == 1)
////					cout << "Yes" << endl;
////			}
////		}
////	}
////}
//
//
//
////void qs(vector<int>v,int begin,int end)
////{
////	if (begin < end)
////	{
////		int piont = v[begin];
////		int l = begin;
////		int r = end;
////		while (l < r)
////		{
////			while (v[end] >= piont && l < r)
////				r--;
////			v[l] = v[r];
////			while (v[l] <= piont && l < r)
////				l++;
////			v[r] = v[l];
////		}
////		v[l] = piont;
////		qs(v, begin, l - 1);
////		qs(v, l + 1, end);
////	}
////}
//
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//};
//// 类中仅有成员函数
//struct A2 {
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//struct A3
//{
//private:
//	class A1;
//};
//
//union A4
//{
//	char a;
//	int b;
//};
//
//int main()
//{
//	stack<char> s;
//	s.push(1);
//	s.push(2);
//
//	//cout << sizeof(A1) << endl;
//	//cout << sizeof(A2) << endl;
//	//cout << sizeof(A3) << endl;
//	//A4 u
//	//u.b = 1;
//	//cout << (int)u.a << endl;
//}

//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//#include <stack>
//#include <string>
//using namespace std;
//
//
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
//int max(int a, int b)
//{
//	if (a > b)
//		return a;
//	else
//		return b;
//}
//int longestValidParenthe(string s) {
//	stack<int> st;
//	st.push(-1);
//	int maxl = 0;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '(')
//			st.push(i);
//		else {
//			st.pop();
//			if (st.empty())
//				st.push(i);
//			else {
//				maxl = max(maxl, i - st.top());
//			}
//		}
//	}
//	return maxl;
//}
///******************************结束写代码******************************/
//
//
//int main() {
//	int res;
//
//	string _s;
//	getline(cin, _s);
//
//	res = longestValidParenthe(_s);
//	cout << res << endl;
//
//	return 0;
//
//}

//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//
//using namespace std;
//
//
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
//vector < int > findNumber(int num) {
//	vector<int> v;
//	int count = 0;
//	while (num > 1) {
//		v.push_back(num % 2);
//		num /= 2;
//	}
//	v.push_back(num);
//	for (int i = 0; i < v.size(); i++) {
//		if (v[i] == 1)
//			count++;
//	}
//	int ln = num - 1;
//	int hn = num + 1;
//	vector<int> l(64);
//	vector<int> h(64);
//	
//	vector<int> ls;
//	vector<int> hs; 
//
//	int countl = 0;
//	int counth = 0;
//
//	vector<int> out;
//
//	for (int i = 0; i < 64; i++) {
//		h[i] = h[i] + num + 1;
//		while (h[i] > 1) {
//			hs.push_back(h[i] % 2);
//			h[i] /= 2;
//		}
//		hs.push_back(h[i]);
//		for (int j = 0; j < hs.size(); j++) {
//			if (hs[i] == 1)
//				counth++;
//		}
//		if (counth == count) {
//			out.push_back(h[i]);
//			break;
//		}
//	}
//	
//	for (int i = 0; i < 64; i++) {
//		l[i] = num - 1 - i;
//		while (l[i] > 1) {
//			ls.push_back(l[i] % 2);
//			l[i] /= 2;
//		}
//		ls.push_back(l[i]);
//		for (int j = 0; j < ls.size(); j++) {
//			if (ls[i] == 1)
//				counth++;
//		}
//		if (countl == count) {
//			out.push_back(l[i]);
//			break;
//		}
//	}
//
//	return out;
//}
///******************************结束写代码******************************/
//
//
//int main() {
//	vector < int > res;
//
//	int _num;
//	cin >> _num;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//
//
//	res = findNumber(_num);
//	for (int res_i = 0; res_i < res.size(); res_i++) {
//		cout << res[res_i] << endl;;
//	}
//
//	return 0;
//
//}



//string GetCommon(string str1, string str2) {
//	// write code here
//	if (str1.size() < str2.size())
//		swap(str1, str2);
//	vector<string> v;
//	int begin1 = 0;
//	int begin2 = 0;
//	for (int i = 0; i < str1.size(); i++) {
//		for (int j = 0; j < str2.size(); j++) {
//			if (str1[i] == str2[j]) {
//				string s;
//				begin1 = i;
//				begin2 = j;
//				while (str1[i] == str2[j] && i < str1.size()&j < str2.size()) {
//					s += str1[i];
//					i++;
//					j++;
//				}
//				v.push_back(s);
//				j = begin2;
//				i = begin1;
//			}
//		}
//	}
//	int l = 0;
//	int maxadd = 0;
//	for (int i = 0; i < v.size(); i++) {
//		if (v[i].size() > l) {
//			l = v[i].size();
//			maxadd = i;
//		}
//	}
//	return v[maxadd];
//}
//
//int main()
//{
//	string s1 = "abccade";
//	string s2 = "dgcadde";
//	cout << GetCommon(s1, s2) << endl;
//}

//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};
//
//vector<vector<int> > printNode(TreeNode* node) {
//	// write code here
//	vector<vector<int>> vv;
//	queue<TreeNode*> q;
//	vector<int> v;
//	q.push(node);
//	while (!q.empty())
//	{
//		while (q.size()) {
//			v.push_back((q.front)->val);
//		}
//		vv.push_back(v);
//		q.push((q.front)->left);
//		q.push((q.front)->right);
//		q.pop();
//	}
//	return vv;
//}
//
//int main()
//{
//	TreeNode * n;
//	printNode(n);
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Judge(vector<vector<int>> &vv, int i, int j, int m, int n)
//{
//
//		vv[i][j] = 0;
//		if (vv[i - 1][j] >= 0 && i-1>=0)
//		{
//			Judge(vv, i - 1, j, m, n);
//		}
//		if (vv[i + 1][j] >= 0 &&i+1<m)
//		{
//			Judge(vv, i + 1, j, m, n);
//		}
//		if (vv[i][j-1] >= 0 && j-1 >= 0)
//		{
//			Judge(vv, i, j-1, m, n);
//		}
//		if (vv[i][j+1] >= 0 && j+1 <n)
//		{
//			Judge(vv, i, j+1, m, n);
//		}
//
//}
//
//int dps(vector<vector<int>> vv,int m,int n)
//{
//	int count = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (vv[i][j] == 1) {
//					Judge(vv,i,j,m,n);
//					count++;
//				}
//			}
//		}
//}
//
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		vector<vector<int>> vv(m, vector<int>(n));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> vv[i][j];
//			}
//		}
//		dps(vv, m, n);
//	}
//}

bool Same(vector<int>req, vector<int> q)
{
	for (int i = 0; i < 3; i++) {
		if (req[i] != q[i]) {
			return false;
		}
	}
	return true;
}
vector<int> getTriggerTime(vector<vector<int>>  increase, int increaseRowLen, int increaseColLen, vector<vector<int>>  requirements, int requirementsRowLen, int requirementsColLen) {
	// write code here
	int C = 0;
	int R = 0;
	int H = 0;
	vector<vector<int>> qj(requirementsRowLen, vector<int>(3));
	for (int i = 0; i < requirementsRowLen; i++) {
		for (int j = 0; j < 3; j++) {
			qj[i][j] = requirements[i][j];
		}
	}
	int b = 0;
	vector<int> v(requirementsRowLen, -1);
	int time = 0;
	for (int i = 0; i < increaseRowLen; i++) {
		C += increase[i][0];
		R += increase[i][1];
		H += increase[i][2];
		time++;
		for (int j = 0; j < requirementsRowLen; j++) {
			while (C >= qj[b][0] && R >= qj[b][1] && H >= qj[b][2]) {
			v[j] = time;
			}
		}
	}
	vector<int> out(requirementsRowLen, -1);
	for (int i = 0; i < requirementsRowLen; i++) {
		for (int j = 0; j < requirementsRowLen; j++) {
			if (Same(requirements[i], qj[j]))
				out[i] = v[j];
		}
	}
	return out;
}

int main()
{
	vector<vector<int>> increase = { {2,8,4} ,{2,5,0},{10,9,8} };
	vector<vector<int>>requirements = { {2,11,3},{15,10,7},{9,17,12},{8,1,14} };
	getTriggerTime(increase,3, 3,requirements, 4, 3);
}