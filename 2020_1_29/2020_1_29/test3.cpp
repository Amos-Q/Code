#define _CRT_SECURE_NO_WARNINGS 1
#include < iostream> 
 
using namespace std;
template 
class Point
{
protected:
        T x, y;
public   :
        Point(T a, T b)
        {
               x = a;
               y = b;
                       }
        void show()
        {
        cout<<"x = "<< x <<", y = "<< y << endl;
                       }
};
 
template 
class Rectangle : public Point
{
        private:
               T h, w;
        public :
        Rectangle(T a, T b, T c, T d) : Point(a, b)
        {h = c;
         w = d;
                       }
void show(){
cout<<"x = "<< x <<", y = "<< y <<"; h = "<< h <<", w = "<< w << endl;
                       }
};
void main()
{
        Point  a(3, 4);
        Rectangle  b(5.1, 6.2, 7.3, 8.4);
        a.show();
        b.show();
 
        Point  & ra = b;//子类对象 初始化父类的引用
        ra.show();
 
        Point  * p = &b;//子类对象的地址，赋给指向父类的指针
        p->show();
 
        Rectangle  * pb = &b;//子类指针pb
        pb->show();
 
        a = b;                         //派生类对象的属性值，更新父类对象的属性值
        a.show();
}