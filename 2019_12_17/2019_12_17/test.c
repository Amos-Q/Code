#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
struct nodespace {
	int teskid;   // ����� 
	int begin;    // ��ʼ��ַ 
	int size;     // ��С 
	int status;   // ״̬ 0����ռ�ã�1������� 
	struct nodespace *next;  // ��ָ�� 
};

void initNode(struct nodespace *p) {
	if (p == NULL) {	//���Ϊ�����´���һ�� 
		p = (struct nodespace*)malloc(sizeof(struct nodespace));
	}
	p->teskid = -1;
	p->begin = 0;
	p->size = 640;
	p->status = 1;
	p->next = NULL;
}

/*
*  �״���Ӧ�㷨
*/
void myMalloc1(int teskid, int size, struct nodespace *node) {
	while (node != NULL) {
		if (node->status == 1) {  //���еĿռ� 
			if (node->size > size) {  //������С��ʣ��ռ�������� 
				//�����ʣ��Ŀռ� 
				struct nodespace *p = (struct nodespace*)malloc(sizeof(struct nodespace));
				p->begin = node->begin + size;
				p->size = node->size - size;
				p->status = 1;
				p->teskid = -1;
				//����Ŀռ� 
				node->teskid = teskid;
				node->size = size;
				node->status = 0;
				//�ı�ڵ������ 
				p->next = node->next;
				node->next = p;
				break;
			}
			else if (node->size == size) { //����ռ�Ϳ��пռ��С���ʱ 
				node->teskid = teskid;
				node->size = size;
				node->status = 0;
				break;
			}
		}
		if (node->next == NULL) {
			printf("����ʧ�ܣ�û���㹻�Ŀռ䣡\n");
			break;
		}
		node = node->next;
	}
}

/*
* �����Ӧ�㷨
*/
void myMalloc2(int teskid, int size, struct nodespace *node) {
	//��ѿ�ָ�� 
	struct nodespace *q = NULL;
	//�����ҵ���һ�����������Ŀ��п� 
	while (node != NULL) {
		if (node->status == 1 && node->size >= size) {
			q = node;
			break;
		}
		//�����һ��Ϊ����˵��û�п��������Է��� 
		if (node->next == NULL) {
			printf("����ʧ�ܣ�û���㹻�Ŀռ䣡\n");
			break;
		}
		else {
			node = node->next;
		}

	}
	//����Ѱ����ѵĿ��п� 
	while (node != NULL) {
		if (node->status == 1 && node->size >= size && node->size < q->size) {  //���еĿռ� 
			q = node;
		}
		node = node->next;
	}
	if (q->size > size) {  			//��ѿ��п�Ĵ�С���������С 
		//�����ʣ��Ŀռ� 
		struct nodespace *p = (struct nodespace*)malloc(sizeof(struct nodespace));
		p->begin = q->begin + size;
		p->size = q->size - size;
		p->status = 1;
		p->teskid = -1;
		//����Ŀռ� 
		q->teskid = teskid;
		q->size = size;
		q->status = 0;
		//�ı�ڵ������ 
		p->next = q->next;
		q->next = p;
	}
	else if (q->size == size) {  	//��ѿ��п�ռ��С���������
		q->teskid = teskid;
		q->size = size;
		q->status = 0;
	}
}

void myFree(int teskid, struct nodespace *node) {
	if (node->next == NULL && node->teskid == -1) {
		printf("��û�з����κ�����\n");
	}

	while (node != NULL) {
		if (node->status == 1 && node->next->status == 0 && node->next->teskid == teskid) {  //�ͷſռ����һ��ռ����ʱ 
			node->size = node->size + node->next->size;
			struct nodespace *q = node->next;
			node->next = node->next->next;
			free(q);
			if (node->next->status == 1) { //��һ���ռ��ǿ��пռ�ʱ 
				node->size = node->size + node->next->size;
				struct nodespace *q = node->next;
				node->next = node->next->next;
				free(q);
			}
			break;
		}
		else if (node->status == 0 && node->teskid == teskid) {  //�ͷſռ�Ϳ��пռ䲻����ʱ 
			node->status = 1;
			node->teskid = -1;
			if (node->next != NULL && node->next->status == 1) { //��һ���ռ��ǿ��пռ�ʱ 
				node->size = node->size + node->next->size;
				struct nodespace *q = node->next;
				node->next = node->next->next;
				free(q);
			}
			break;
		}
		else if (node->next == NULL) {  //����id��ƥ��ʱ 
			printf("û�д�����\n");
			break;
		}
		node = node->next;
	}


}

void printNode(struct nodespace *node) {
	printf("                        �ڴ����                        \n");
	printf(" -------------------------------------------------------\n");
	printf("| ��ʼ��ַ\t������ַ\t��С\t״̬\t����id\t|\n");
	while (node != NULL) {
		if (node->status == 1) {
			printf("| %d\t\t%d\t\t%dKB\tfree\t ��\t|\n", node->begin + 1, node->begin + node->size, node->size);
		}
		else {
			printf("| %d\t\t%d\t\t%dKB\tbusy\t %d\t|\n", node->begin + 1, node->begin + node->size, node->size, node->teskid);
		}
		node = node->next;
	}
	printf(" -------------------------------------------------------\n");
}

void destory(struct nodespace *node) {
	struct nodespace *q = node;
	while (node != NULL) {
		node = node->next;
		free(q);
		q = node;
	}
}

void menu() {
	printf("1.�����ڴ�\n");
	printf("2.�����ڴ�\n");
	printf("3.�鿴�ڴ����\n");
	printf("4.�˳�\n");
	printf("������ѡ��:");
}

int main() {
	// nodeΪ�����ռ� 
	struct nodespace *init = (struct nodespace*)malloc(sizeof(struct nodespace));
	struct nodespace *node = NULL;
	initNode(init);			//��ʼ������ 
	node = init; 			//ָ������ͷ 
	int option;
	int teskid;
	int size;
	while (1) {
		printf("��ѡ��ģʽ��\n 1.��ʾģʽ\n 2.����ģʽ\n 3.�˳�\n");
		scanf("%d", &option);
		if (option == 1) {	//��ʾģʽ 
			while (1) {		//ѭ��ѡ��ʵ�ֵ��㷨 
				printf("��ѡ���㷨��\n 1.�״���Ӧ�㷨\n 2.�����Ӧ�㷨\n 3.�˳�\n");
				scanf("%d", &option);
				if (option == 1) {			//�״���Ӧ�㷨 
					printf("��ҵ1 ����130 KB\n");
					myMalloc1(1, 130, node);		//��ҵ1 ����130 KB
					printNode(node);
					printf("��ҵ2 ����60 KB\n");
					myMalloc1(2, 60, node);		//��ҵ2 ����60 KB
					printNode(node);
					printf("��ҵ3 ����100 KB\n");
					myMalloc1(3, 100, node);		//��ҵ3 ����100 KB
					printNode(node);
					printf("��ҵ2 �ͷ�60 KB\n");
					myFree(2, node);			//��ҵ2 �ͷ�60 KB
					printNode(node);
					printf("��ҵ4 ����200 KB\n");
					myMalloc1(4, 200, node);		//��ҵ4 ����200 KB
					printNode(node);
					printf("��ҵ3 �ͷ�100 KB\n");
					myFree(3, node);			//��ҵ3 �ͷ�100 KB
					printNode(node);
					printf("��ҵ1 �ͷ�130 KB\n");
					myFree(1, node);			//��ҵ1 �ͷ�130 KB
					printNode(node);
					printf("��ҵ5 ����140 KB\n");
					myMalloc1(5, 140, node);		//��ҵ5 ����140 KB
					printNode(node);
					printf("��ҵ6 ����60 KB\n");
					myMalloc1(6, 60, node);		//��ҵ6 ����60 KB
					printNode(node);
					printf("��ҵ7 ����50 KB\n");
					myMalloc1(7, 50, node);		//��ҵ7 ����50 KB
					printNode(node);
					printf("��ҵ6 �ͷ�60 KB\n");
					myFree(6, node);			//��ҵ6 �ͷ�60 KB
					printNode(node);
					destory(node);	//��������
					initNode(init);	//���³�ʼ�� 
					node = init;	//����ָ��ͷ 
				}
				else if (option == 2) {		//�����Ӧ�㷨 
					printf("��ҵ1 ����130 KB\n");
					myMalloc2(1, 130, node);		//��ҵ1 ����130 KB
					printNode(node);
					printf("��ҵ2 ����60 KB\n");
					myMalloc2(2, 60, node);		//��ҵ2 ����60 KB
					printNode(node);
					printf("��ҵ3 ����100 KB\n");
					myMalloc2(3, 100, node);		//��ҵ3 ����100 KB
					printNode(node);
					printf("��ҵ2 �ͷ�60 KB\n");
					myFree(2, node);			//��ҵ2 �ͷ�60 KB
					printNode(node);
					printf("��ҵ4 ����200 KB\n");
					myMalloc2(4, 200, node);		//��ҵ4 ����200 KB
					printNode(node);
					printf("��ҵ3 �ͷ�100 KB\n");
					myFree(3, node);			//��ҵ3 �ͷ�100 KB
					printNode(node);
					printf("��ҵ1 �ͷ�130 KB\n");
					myFree(1, node);			//��ҵ1 �ͷ�130 KB
					printNode(node);
					printf("��ҵ5 ����140 KB\n");
					myMalloc2(5, 140, node);		//��ҵ5 ����140 KB
					printNode(node);
					printf("��ҵ6 ����60 KB\n");
					myMalloc2(6, 60, node);		//��ҵ6 ����60 KB
					printNode(node);
					printf("��ҵ7 ����50 KB\n");
					myMalloc2(7, 50, node);		//��ҵ7 ����50 KB
					printNode(node);
					printf("��ҵ6 �ͷ�60 KB\n");
					myFree(6, node);			//��ҵ6 �ͷ�60 KB
					printNode(node);
					destory(node);	//��������
					initNode(init);	//���³�ʼ�� 
					node = init;	//����ָ��ͷ 
				}
				else if (option == 3) {		//�˳�
					break;
				}
				else {
					printf("���������������������룡\n");
				}
			}
		}
		else if (option == 2) {	//����ģʽ 
			while (1) {		//ѭ��ѡ��ʹ�õ��㷨 
				printf("��ѡ���㷨��\n 1.�״���Ӧ�㷨\n 2.�����Ӧ�㷨\n 3.�˳�\n");
				scanf("%d", &option);
				int n = option;		//���ѡ����㷨��n == 1 ��ʾ�״���Ӧ�㷨, n == 2��ʾ�����Ӧ�㷨 
				if (option != 3) {
					while (1) {
						menu();		//��ӡ��Ҫ���еĲ��� 
						scanf("%d", &option);
						if (option == 1 && n == 1) {			//�״���Ӧ 
							printf("����������id�Լ�����Ŀռ��С:\n");
							scanf("%d%d", &teskid, &size);
							myMalloc1(teskid, size, node);
							printNode(node);
						}
						else if (option == 1 && n == 2) {	//�����Ӧ 
							printf("����������id�Լ�����Ŀռ��С:\n");
							scanf("%d%d", &teskid, &size);
							myMalloc2(teskid, size, node);
							printNode(node);
						}
						else if (option == 2) {
							printf("����������id:\n");
							scanf("%d", &teskid);
							myFree(teskid, node);
							printNode(node);
						}
						else if (option == 3) {
							printNode(node);
						}
						else if (option == 4) {
							destory(node);	//��������
							initNode(init);	//���³�ʼ�� 
							node = init;	//����ָ��ͷ 
							break;
						}
						else {
							printf("���������������������룡\n");
							continue;
						}
					}
				}
				else if (option == 3) {
					destory(node);	//��������
					initNode(init);	//���³�ʼ�� 
					node = init;	//����ָ��ͷ 
					break;
				}
				else {
					printf("���������������������룡\n");
				}
			}

		}
		else if (option == 3) {	//�˳�  
			destory(node);
			return 0;
		}
		else {
			printf("���������������������룡\n");
			continue;
		}
	}
	return 0;
}