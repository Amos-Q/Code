#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkQueue.h"
int visit(QueuePtr p) {
	//visit函数用来输出队列
	cout << p->data << " ";
	return OK;
}
int main() {
	LinkQueue Q;
	InitQueue(Q);
	cout << "空队列初始化成功" << endl;
	cout << "在队列中依次插入五个元素" << endl;
	QElemType e;
	for (int i = 0; i < 5; i++)
	{
		cin >> e;
		EnQueue(Q, e);
	}
	cout << "输出整个队列" << endl;
	QueueTraverse(Q, visit);
	DeQueue(Q, e);
	cout << endl;
	cout << "删除队头元素，输出整个队列" << endl;
	QueueTraverse(Q, visit);
	cout << endl << "清空队列" << endl;
	ClearQueue(Q);
	cout << "输出整个队列" << endl;
	QueueTraverse(Q, visit);
	cout << endl << "销毁队列，结束" << endl;
	DetroyQueue(Q);
	system("pause");
	return 0;
}
