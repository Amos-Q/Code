#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkQueue.h"
int visit(QueuePtr p) {
	//visit���������������
	cout << p->data << " ";
	return OK;
}
int main() {
	LinkQueue Q;
	InitQueue(Q);
	cout << "�ն��г�ʼ���ɹ�" << endl;
	cout << "�ڶ��������β������Ԫ��" << endl;
	QElemType e;
	for (int i = 0; i < 5; i++)
	{
		cin >> e;
		EnQueue(Q, e);
	}
	cout << "�����������" << endl;
	QueueTraverse(Q, visit);
	DeQueue(Q, e);
	cout << endl;
	cout << "ɾ����ͷԪ�أ������������" << endl;
	QueueTraverse(Q, visit);
	cout << endl << "��ն���" << endl;
	ClearQueue(Q);
	cout << "�����������" << endl;
	QueueTraverse(Q, visit);
	cout << endl << "���ٶ��У�����" << endl;
	DetroyQueue(Q);
	system("pause");
	return 0;
}
