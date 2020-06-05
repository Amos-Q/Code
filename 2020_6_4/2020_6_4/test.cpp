#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.resize(4);
//	for (int i = 0; i < 4; i++)
//		cin >> v[i];
//	int A = 0;
//	int B = 0;
//	int C = 0;
//	A = (v[0] + v[2]) / 2;
//	B = A - v[0];
//	C = B - v[1];
//	if ((A + B == v[2]) && (B + C == v[3]) && A >= 0 && B >= 0 && C >= 0)
//		cout << A << " " << B << " " << C;
//	else
//		cout << "No";
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int sum = 0;
	while (cin >> sum)
	{
		int s = 0;
		cin >> s;
		vector<int> v;
		while (sum >= s)
		{
			v.push_back(sum%s);
			sum /= s;
		}
		v.push_back(sum);
		for (int i = v.size() - 1; i >= 0; i--)
		{
			if (v[i] > 9)
				printf("%c", 'A' + v[i] - 10);
			else
				cout << v[i];
		}
		cout << endl;
	}
}