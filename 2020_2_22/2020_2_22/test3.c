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

//³õÊ¼»¯Õ»
void init(Stack *pstack);
//Ñ¹Õ»
void push(Stack *pstack, StackNode pnode);
//µ¯Õ»
StackNode pop(Stack *pstack);
//ÊÇ·ñÎª¿Õ
int isEmpty(Stack *pstack);
//Çå¿Õ
void ClearAll(Stack *pstack);

#include"stack.h"

void init(Stack *pstack) {
	pstack->top = (StackNode)malloc(sizeof(node));
	if (pstack->top == NULL) {
		printf("·ÖÅäÄÚ´æÊ§°Ü£¡\n");
		return;
	}

	pstack->bottom = pstack->top;
	pstack->top->next = NULL;
}

int isEmpty(Stack *pstack) {

	if (pstack == NULL) {
		printf("Õ»²»´æÔÚ£¡ \n");
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
		printf("´íÎó£ºÕ»²»´æÔÚ£¡\n");
	pnode->next = pstack->top;
	pstack->top = pnode;
}

StackNode pop(Stack *pstack) {
	StackNode result = NULL;
	if (isEmpty(pstack)) {
		printf("Õ»Îª¿Õ£¬µ¯Õ»Ê§°Ü£¡\n");
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
		printf("´íÎó£ºÕ»²»´æÔÚ£¡");
	else if (pstack->top == pstack->bottom) {
		printf("Õ»Îª¿Õ!\n");
	}
	else {
		StackNode p = pstack->top;
		while (p != pstack->bottom) {
			printf("ÐÕÃû£º%s\tÄê¼¶£º%d\tÄêÁä£º%d\n", p->name, p->grade, p->age);
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
