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
	//给非空队列进行入队操作
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
	//把非空队列的除最后一个元素之外的剩余元素全部入队空队列
	Queue* pEmpty = &obj->q1, *pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) != 0)
		比特科技
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
	//队尾元素出队
	QueuePop(pNonEmpty);

	return top;
}
/** Get the top element. */
int myStackTop(MyStack* obj) {
	//获取非空队列的队尾元素
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