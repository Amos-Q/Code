#define _CRT_SECURE_NO_WARNINGS 1
//构造一个空队列
Status InitQueue(LinkQueue &Q);

//销毁队列Q，Q不再存在
Status DetroyQueue(LinkQueue &Q);

//将Q清为空队列
Status ClearQueue(LinkQueue &Q);

//若Q为空队列，则返回TRUE，否则返回FLASE
Status QueueEmpty(LinkQueue Q);

//返回Q的元素个数
int QueueLenth(LinkQueue Q);

//若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
Status GetHead(LinkQueue Q, QElemType &e);

//插入元素e为Q的新的队尾元素
Status EnQueue(LinkQueue &Q, QElemType e);

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK
Status DeQueue(LinkQueue &Q, QElemType &e);

//对队列所有元素依次进行visit（）操作
Status QueueTraverse(LinkQueue Q, Status(*visit)(QueuePtr));
