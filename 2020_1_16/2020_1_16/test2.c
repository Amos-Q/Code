#define _CRT_SECURE_NO_WARNINGS 1
typedef struct {
	Queue q1;
	Queue q2;

} MyStack;
/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}
/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//���ǿն��н�����Ӳ���
	if (QueueEmpty(&obj->q1) != 0)
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}
/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	//�ѷǿն��еĳ����һ��Ԫ��֮���ʣ��Ԫ��ȫ����ӿն���
	Queue* pEmpty = &obj->q1, *pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) != 0)
		���ؿƼ�
	{
	pEmpty = &obj->q2;
	pNonEmpty = &obj->q1;
	}

		while (QueueSize(pNonEmpty) > 1)
		{
			QueuePush(pEmpty, QueueFront(pNonEmpty));
			QueuePop(pNonEmpty);
		}

	int top = QueueFront(pNonEmpty);
	//��βԪ�س���
	QueuePop(pNonEmpty);

	return top;
}
/** Get the top element. */
int myStackTop(MyStack* obj) {
	//��ȡ�ǿն��еĶ�βԪ��
	Queue* pEmpty = &obj->q1, *pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) != 0)
	{
		pEmpty = &obj->q2;
		pNonEmpty = &obj->q1;
	}

	return QueueBack(pNonEmpty);
}
/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return !(QueueEmpty(&obj->q1) | QueueEmpty(&obj->q2));
}
void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}