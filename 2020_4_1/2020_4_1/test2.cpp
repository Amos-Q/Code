#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
long long n, m;
int a[100000]
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		int high = n, low = 1;
		while (low < high) {
			int mid = (low + high) / 2;
			if (a[mid] == x) {
				cout << x << endl;
				break;
			}//	1	2 5 6 8	100
			if (a[mid] > x) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
	}
	//cout<<"low"<<low<<endl;
	if (ads(a[low] - x) < ads(a[low - 1] - x)) {
		cout << a[low] << endl;
	}
	else {
		cout << a[low - 1] << endl;
	}
	return 0;
}



