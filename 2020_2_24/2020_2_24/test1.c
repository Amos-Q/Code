#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

char* addBinary(char* a, char* b) {
	int i = strlen(a);
	int j = strlen(b);

	int len = i > j ? i : j;
	char* res = (char*)malloc(sizeof(char) * (len + 2));
	res[++len] = 0;

	char carry = '0';
	char pa, pb;
	while (len > 1 || carry == '1') {
		pa = i > 0 ? a[--i] : '0';
		pb = j > 0 ? b[--j] : '0';
		res[--len] = pa ^ pb ^ carry; // 当前位
		carry = (pa & carry) | (pb & carry) | (pa & pb); //进位
	}
	return res + len;
}

int main()
{
	char a[] = "10";
	char b[] = "1";
	addBinary(a, b);
	system("pause");
	return 0;
}

QNode* BuyQueueNode(QDataType x)
{
	QNode* cur = (QNode*)malloc(sizeof(QNode));
	cur->_data = x;
	cur->_next = NULL;


	return cur;
}


void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}


void QueuePush(Queue* q, QDataType data)
{
	QNode* cur = BuyQueueNode(data);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = cur;
	}
	else
	{
		q->_rear->_next = cur;
		q->_rear = cur;
	}
}


void QueuePop(Queue* q)
{
	if (q->_front == NULL)
	{
		return;
	}
	else
	{
		QNode* tmp = q->_front->_next;
		free(q->_front);
		q->_front = tmp;
	}
}


QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}


QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}


int QueueSize(Queue* q)
{
	QNode* cur;
	int count = 0;
	for (cur = q->_front; cur; cur = cur->_next)
	{
		count++;
	}
	return count;
}


int QueueEmpty(Queue* q)
{
	return q->_front == NULL;
}


void QueueDestroy(Queue* q)
{
	if (q->_front == NULL)
	{
		return;
	}
	while (q->_front)
	{
		QueuePop(q);
	}
}


void QueuePrintf(Queue* q)
{
	if (q->_front == NULL)
	{
		return;
	}
	QNode* cur;
	for (cur = q->_front; cur; cur = cur->_next)
	{
		printf("%d ", cur->_data);
	}
	printf("\n");
}