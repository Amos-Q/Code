#define _CRT_SECURE_NO_WARNINGS 1
#include < iostream >
using namespace std;
class Basic//基类
{
protected:
	double  r;
public :
	Basic() { r = 0; }
	Basic(double a) :r(a) {}
};
class Circular : public Basic//从基类派生圆类
{
protected:
	double area;
public :
	Circular(double a)
	{
		r = a;
		area = area = 3.1415926 * r * r;
	}
	double getArea()//返回圆面积
	{
		return area;
	}
};
class Column : public Circular//从圆类派生圆柱类
{
protected:
	double h;
	double cubage;
public  :
	Column(double a, double b) : Circular(a) {
		h = b;
		cubage = getArea() * h;
	}
	double getCubage()//返回圆柱体积函数{
		return cubage;
}
};
void main()
{
	Circular circular(45);
	Column column(12, 10);
	cout << "圆的面积：" << circular.getArea() << endl;
	cout << "圆柱的体积：" << column.getCubage() << endl;
}