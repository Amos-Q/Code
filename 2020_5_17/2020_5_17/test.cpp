#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <string>
using namespace std;
class AClass
{
public:
	int num;
	string name;
};
struct AStruct
{
	int num;
	string name;
};
void TestStruct()
{
	//类的使用
	AClass Ac;
	vector<AClass> vc;
	Ac.num = 10;
	Ac.name = "name";
	vc.push_back(Ac);
	AClass d;
	for (vector<AClass>::iterator it = vc.begin(); it < vc.end(); ++it)
	{
		d = *it;
		cout << d.num << endl;
	}
	//结构体的使用
	AStruct As;
	vector<AStruct> vs;
	As.num = 10;
	As.name = "name";
	vs.push_back(As);
	AStruct ds;
	for (vector<AStruct>::iterator it = vs.begin(); it < vs.end(); ++it)
	{
		ds = *it;
		cout << ds.num << endl;
	}
}
void TestPoint()
{
	//类的使用
	AClass *Ac = new AClass;
	vector<AClass *> vc;
	Ac->num = 10;
	Ac->name = "name";
	vc.push_back(Ac);
	AClass *d;
	for (vector<AClass*>::iterator it = vc.begin(); it < vc.end(); ++it)
	{
		d = *it;
		cout << d->num << endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	TestStruct();
	TestPoint();
	int n;
	cin >> n;
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	for (vector<int>::size_type ix = 0; ix != v.size(); ix++) {
		printf("%d\t", v[ix]);
	}
	printf("\n");

	//在开始插入10,10,10
	v.insert(v.begin(), 3, 10);
	for (vector<int>::size_type ix = 0; ix != v.size(); ix++) {
		printf("%d\t", v[ix]);
	}
	printf("\n");

	//删除第二个10
	int i = 0;
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		i++;
		if (i == 2) {
			v.erase(it);
			break;
		}
	}

	for (vector<int>::size_type ix = 0; ix != v.size(); ix++) {
		printf("%d\t", v[ix]);
	}
	printf("\n");


	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//利用下标      
	for (vector<int>::size_type ix = 0; ix != v.size(); ix++) {
		printf("%d\t", v[ix]);
	}
	printf("\n");

	//利用迭代器
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		printf("%d\t", *it);
	}
	printf("\n");


	return 0;
}