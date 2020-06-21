#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream> 
//#include<algorithm> 
//using namespace std;
///*    getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后
//一个位置结束
//x[]: 袋子中的所有球
//n:   球的总数
//pos: 当前搜索的位置
//sum: 到目前位置的累加和
//multi: 到目前位置的累积值 */
//
//int getLuckyPacket(int x[], int n, int pos, int sum, int multi) {
//	int count = 0;
//	//循环，搜索以位置i开始所有可能的组合    
//	for (int i = pos; i < n; i++) {
//		sum += x[i];
//		multi *= x[i];
//		if (sum > multi) {
//			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合
//			//要求的集合            
//			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
//		}
//		else if (x[i] == 1) {
//			//如何不符合要求，且当前元素值为1，则继续向后搜索            
//			count += getLuckyPacket(x, n, i + 1, sum, multi);
//		}
//		else {
//			//如何sum大于multi,则后面就没有符合要求的组合了            
//			break;
//		}
//		//要搜索下一个位置之前，首先恢复sum和multi        
//		sum -= x[i];
//		multi /= x[i];
//		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过 
//		while (i < n - 1 && x[i] == x[i + 1]) {
//			i++;
//		}
//	}
//	return count;
//}
//
//int main() {
//	int n;
//	while (cin >> n) {
//		int x[1000];
//		for (int i = 0; i < n; i++) {
//			cin >> x[i];
//		}
//		sort(x, x + n);
//		//从第一个位置开始搜索        
//		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;

//void foo(char a[41])
//{
//	cout << sizeof(a);
//}
//
//int main()
//{
//	char a[41];
//	foo(a);
//	system("pause");
//}

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

void Luck(vector<vector<int>> vv)
{
	int sum = 0;
	for (int i = 0; i < vv.size(); i++)
	{
		vector<int> v = vv[i];
		int sum1 = v[0];
		int sum2 = v[0];
		for (int j = 1; j < v.size(); j++)
		{
			sum1 += v[j];
			sum2 *= v[j];
		}
		if (sum1 > sum2)
			sum++;
	}
	cout << sum << endl;
}

void Distribute(vector<vector<int>> &vvv, vector<int> v, int n)
{
	for (int i = 0; i < v.size(); i++)
	{
		vector<int> vv;
		vv.push_back(v[i]);
		if (vvv.empty())
		{
			vv.push_back(v[i]);
			vvv.push_back(vv);
		}
		else
		{
			int len = vvv.size();
			for (int j = 0; j < vvv.size(); j++)
				vvv.push_back(vvv[j]);
			for (int j = 0; j < len; j++)
			{
				vvv[j].push_back(v[i]);
			}
			vvv.push_back(vv);
		}
	}
	for (int i = 0; i < vvv.size(); i++)
	{
		for (int j = i + 1; j < vvv.size(); j++)
		{
			if (vvv[i] == vvv[j])
			{
				vvv.erase(vvv.begin() + j);
				j--;
			}
		}
	}
}

int main()
{
	vector<vector<int>> vvv;
	vector<int> v;
	int n = 0;
	cin >> n;
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
	}
	Distribute(vvv, v, n);
	Luck(vvv);
	system("pause");
	return 0;
}