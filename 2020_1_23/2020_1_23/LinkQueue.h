#define _CRT_SECURE_NO_WARNINGS 1
//����һ���ն���
Status InitQueue(LinkQueue &Q);

//���ٶ���Q��Q���ٴ���
Status DetroyQueue(LinkQueue &Q);

//��Q��Ϊ�ն���
Status ClearQueue(LinkQueue &Q);

//��QΪ�ն��У��򷵻�TRUE�����򷵻�FLASE
Status QueueEmpty(LinkQueue Q);

//����Q��Ԫ�ظ���
int QueueLenth(LinkQueue Q);

//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status GetHead(LinkQueue Q, QElemType &e);

//����Ԫ��eΪQ���µĶ�βԪ��
Status EnQueue(LinkQueue &Q, QElemType e);

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK
Status DeQueue(LinkQueue &Q, QElemType &e);

//�Զ�������Ԫ�����ν���visit��������
Status QueueTraverse(LinkQueue Q, Status(*visit)(QueuePtr));
