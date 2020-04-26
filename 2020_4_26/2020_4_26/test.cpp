#include <iostream>
using namespace std;


class Box
{
public:
	double length;
	double breadth;
	double heigth;
};
int main()
{
	Box box1;
	Box box2;
	double volume = 0.5;
	box1.length = 1;
	box1.breadth = 2;
	box1.heigth = 3;

	box2.length = 4;
	box2.breadth = 5;
	box2.heigth = 6;

	volume = box1.length*box1.breadth*box1.heigth;
	cout << volume << endl;
}


#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(void) {
	int N;
	int nArr[100];
	int a[100];

	int datamax = 0;
	int index = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> nArr[i];
		while (nArr[i] > 10) {        //找到每个数最高位的值
			a[i] = nArr[i] / 10;
		}

	}


	for (int k = 0; k < N; k++) {
		if (datamax < a[k]) {
			datamax = a[k];
			index = k;
		}
	}
	cout << nArr[index];
	a[index] = 0;

}