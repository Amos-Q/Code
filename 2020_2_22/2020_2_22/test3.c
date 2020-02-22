#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char *name;
	int grade;
	int age;
	struct node *next;
} *StackNode, node;

typedef struct Stack {
	StackNode top;
	StackNode bottom;
} Stack;

//��ʼ��ջ
void init(Stack *pstack);
//ѹջ
void push(Stack *pstack, StackNode pnode);
//��ջ
StackNode pop(Stack *pstack);
//�Ƿ�Ϊ��
int isEmpty(Stack *pstack);
//���
void ClearAll(Stack *pstack);

#include"stack.h"

void init(Stack *pstack) {
	pstack->top = (StackNode)malloc(sizeof(node));
	if (pstack->top == NULL) {
		printf("�����ڴ�ʧ�ܣ�\n");
		return;
	}

	pstack->bottom = pstack->top;
	pstack->top->next = NULL;
}

int isEmpty(Stack *pstack) {

	if (pstack == NULL) {
		printf("ջ�����ڣ� \n");
		return 0;
	}
	else {
		if (pstack->top == pstack->bottom)
			return 1;
		else
			return 0;
	}
}

void push(Stack *pstack, StackNode pnode) {
	if (pstack == NULL)
		printf("����ջ�����ڣ�\n");
	pnode->next = pstack->top;
	pstack->top = pnode;
}

StackNode pop(Stack *pstack) {
	StackNode result = NULL;
	if (isEmpty(pstack)) {
		printf("ջΪ�գ���ջʧ�ܣ�\n");
	}
	else {
		result = pstack->top;
		pstack->top = pstack->top->next;
	}
	return result;
}

void ClearAll(Stack *pstack) {
	if (isEmpty(pstack))
		return;
	StackNode p = pstack->top;
	StackNode q = NULL;

	while (p != pstack->bottom) {
		q = p->next;
		free(p);
		p = q;
	}
	pstack->top = pstack->bottom;
}

void print(Stack *pstack) {
	if (pstack == NULL)
		printf("����ջ�����ڣ�");
	else if (pstack->top == pstack->bottom) {
		printf("ջΪ��!\n");
	}
	else {
		StackNode p = pstack->top;
		while (p != pstack->bottom) {
			printf("������%s\t�꼶��%d\t���䣺%d\n", p->name, p->grade, p->age);
			p = p->next;
		}
	}
}

int main() {
	Stack *pstack;
	init(pstack);
	StackNode pnode = (StackNode)malloc(sizeof(node));
	pnode->name = "karno";
	pnode->grade = 100;
	pnode->age = 23;

	push(pstack, pnode);
	print(pstack);

	StackNode result = pop(pstack);
	print(pstack);


	return 0;
}
