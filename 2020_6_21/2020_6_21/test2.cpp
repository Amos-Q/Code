#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream> 
//#include<algorithm> 
//using namespace std;
///*    getLuckyPacket:�ӵ�ǰλ�ÿ�ʼ��������Ҫ�����ϣ�һֱ���������
//һ��λ�ý���
//x[]: �����е�������
//n:   �������
//pos: ��ǰ������λ��
//sum: ��Ŀǰλ�õ��ۼӺ�
//multi: ��Ŀǰλ�õ��ۻ�ֵ */
//
//int getLuckyPacket(int x[], int n, int pos, int sum, int multi) {
//	int count = 0;
//	//ѭ����������λ��i��ʼ���п��ܵ����    
//	for (int i = pos; i < n; i++) {
//		sum += x[i];
//		multi *= x[i];
//		if (sum > multi) {
//			//�ҵ�����Ҫ�����ϣ���1�������ۼӺ�����ֵ�����Ƿ��з���
//			//Ҫ��ļ���            
//			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
//		}
//		else if (x[i] == 1) {
//			//��β�����Ҫ���ҵ�ǰԪ��ֵΪ1��������������            
//			count += getLuckyPacket(x, n, i + 1, sum, multi);
//		}
//		else {
//			//���sum����multi,������û�з���Ҫ��������            
//			break;
//		}
//		//Ҫ������һ��λ��֮ǰ�����Ȼָ�sum��multi        
//		sum -= x[i];
//		multi /= x[i];
//		//������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������ 
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
//		//�ӵ�һ��λ�ÿ�ʼ����        
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