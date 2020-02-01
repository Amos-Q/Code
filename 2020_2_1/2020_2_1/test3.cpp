#define _CRT_SECURE_NO_WARNINGS 1
void frequency(String& s, char& A[], int& C[], int &k)
{
	int i, j, len = s.length();
	if (!len) { cout << "The string is empty. " << endl;  k = 0;  return; }
	else
	{
		A[0] = s[0];  C[0] = 1;  k = 1;  	/*语句s[i]是串的重载操作*/
		for (i = 1; i < len; i++) C[i] = 0;  			/*初始化*/
		for (i = 1; i < len; i++)
		{	 		/*检测串中所有字符*/
			j = 0;   while (j < k && A[j] != s[i]) j++; /*检查s[i]是否已在A[ ]中*/
			if (j == k)
			{
				A[k] = s[i]; C[k]++; k++
			}		/*s[i]从未检测过*/
			else C[j]++;			/*s[i]已经检测过*/
		}
	}
}
#include <assert.h>
template <class Type> class Queue {	//循环队列的类定义
public:
	Queue(int = 10);
	~Queue() { delete[] elements; }
	void EnQueue(Type & item);
	Type DeQueue();
	Type GetFront();
	void MakeEmpty() { length = 0; }		//置空队列
	int IsEmpty() const { return length == 0; }	//判队列空否
	int IsFull() const { return length == maxSize; }	//判队列满否
private:
	int rear, length;				//队尾指针和队列长度
	Type *elements;				//存放队列元素的数组
	int maxSize;				//队列最大可容纳元素个数
}；