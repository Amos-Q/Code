#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> numbers;
//	numbers.push_back(1);
//	numbers.push_back(2);
//	numbers.push_back(3);
//	numbers.push_back(2);
//	numbers.push_back(2);
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		int num = 0;
//		for (int j = 0; j < numbers.size(); j++)
//		{
//			if (numbers[j] == numbers[i])
//				++num;
//			if (num >= (numbers.size() / 2))
//			{
//				cout << numbers[i];
//			}
//		}
//	}
//	cout << 0;
//}

//
//#include <iostream>
//#include <string>
//using namespace std;

//int main()
//{
//	string str;
//	cin >> str;
//	int nums1 = 0;
//	int nums2 = 0;
//	int begin1 = 0;
//	int begin2 = 0;
//	for(int i = 0;i<str.size();i++)
//	{
//		nums1 = 0;
//		while(i < str.size() && str[i] >= '0' && str[i] <= '9')
//		{
//			if (nums1 == 0)
//				begin1 = i;
//			nums1++;
//			i++;
//		}
//		if (nums1 > nums2)
//		{
//			nums2 = nums1;
//			begin2 = begin1;
//		}
//	}
//	while(nums2)
//	{
//		cout << str[begin2];
//		begin2++;
//		nums2--;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	printf("%2.4s","hellostrr");
//	printf("%4.4d", 10862);
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str1;
//	string str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int ascll[128] = { 0 };
//	for (int i = 0; i < str2.size(); i++)
//	{
//		ascll[str2[i]]++;
//	}
//	string ret;
//	for (int i = 0; i < str1.size(); i++)
//	{
//		if (ascll[str1[i]] == 0)
//			ret += str1[i];
//	}
//	cout << ret;
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(3 * n);
		long sum = 0;
		for (int i = 0; i < n * 3; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		for (int i = 3 * n - 2; i >= n; i -= 2)
		{
			sum += v[i];
		}
		cout << sum;
	}
	return 0;
}