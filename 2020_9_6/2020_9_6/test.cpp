#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n, p, q;
//	while (cin >> n >> p >> q)
//	{
//		vector<int> A(p);
//		for (int i = 0; i < p; i++)
//		{
//			cin >> A[i];
//		}
//		vector<int> B(q);
//		for (int i = 0; i < q; i++)
//		{
//			cin >> B[i];
//		}
//		vector<int> N(n + 1);
//		for (int i = 0; i < A.size(); i++)
//		{
//			N[A[i]] += 1;
//		}
//		for (int i = 0; i < B.size(); i++)
//		{
//			N[B[i]] += 2;
//		}
//		int a = 0;
//		int b = 0;
//		int c = 0;
//		for (int i = 0; i < N.size(); i++)
//		{
//			if (N[i] == 1)
//				a++;
//			if (N[i] == 2)
//				b++;
//			if (N[i] == 3)
//				c++;
//		}
//		cout << a << ' ' << b << ' ' << c << endl;
//	}
//}


//#include <iostream>
//#include <string>
//#define Min(a,b) ((a)>(b)?(b):(a))
//using namespace std;
//
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		int bl = 0;
//		int sl = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] >= 'A' && s[i] <= 'Z')
//			{
//				bl++;
//			}
//			else
//				sl++;
//		}
//		if ((bl == 0) || (sl == 0) || (bl == sl))
//			cout << 0 << endl;
//		else
//		{
//			int c = abs(bl - sl) - 1;
//			cout << Min((c), Min(bl, sl)) << endl;
//		}
//	}
//}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> v(n);
//		int child = 0;
//		int flag = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//			if (v[i] == 1)
//				child++;
//			if (v[i] >= 2)
//				flag = 1;
//		}
//		if (child >= 2 && flag == 1)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int x;
//		int out = 0;
//		int c = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			for (int j = 1; j <= n; j++)
//			{
//				out ^= ((i + 1) % j);
//			}
//			x ^= out;
//			c ^= x;
//		}
//		cout << c << endl;
//	}
//}



//#include<iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int i = 0;
//		int j = 0;
//		string s;
//		getline(cin, s);
//		vector<int> out;
//		/*for (i = 0; i < n; i++)
//		{
//			if (out.empty())
//				out.push_back(v[i]);
//			else
//			{
//				for (j = 0; j < out.size(); j++)
//				{
//					if (out[j] == v[i])
//					{
//						out.erase(out.begin() + j);
//						reverse(out.begin(), out.end());
//						out.push_back(v[i]);
//						reverse(out.begin(), out.end());
//						break;
//					}
//				}
//				if (j == out.size())
//				{
//					reverse(out.begin(), out.end());
//					out.push_back(v[i]);
//					reverse(out.begin(), out.end());
//				}
//			}
//		}
//		for (i = 0; i < out.size(); i++)
//		{
//			cout << out[i] << endl;
//		}*/
//	}
//}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

static int i = 1;
int Sum(int n)
{
	int out = 0;
	for (int j = 1; j <= n; j++)
	{
		out ^= (i % j);
	}
	i++;
	return out;
}

int main()
{
	int n;
	while (cin >> n)
	{
		string s;
		getline(cin, s);
		int end;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			int j = 0;
			int sum = 0;
			int out = 0;
			while (s[i] != ' ')
			{
				sum = s[i] * 10 * j;
				j++;
			}
			sum ^= Sum(n);
			end ^= sum;
		}
		cout << end << endl;
	}
}