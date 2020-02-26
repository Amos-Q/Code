#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct tree{
	char date;
	struct tree *lchild;
	struct tree *rcjild;
}tree,*shu;
shu xjl(){
	char b;
    shu p;
       scanf("%c",&b);
	   if(b=='$'){
	     p=NULL;
	   }
	   else{
	     p=(shu)malloc(sizeof(tree));
		 p->date=b;
		 p->lchild=xjl();
		 p->rcjild=xjl();
	   } 
	   return p;
   } 
void xbl( shu p ){
	if(p!=NULL){
    printf("%c\n",p->date);
	xbl(p->lchild);
	xbl(p->rcjild);
	}
}
shu zjl(){
	char b;
    shu t;
       scanf("%c",&b);
	   if(b=='$'){
	     t=NULL;
	   }
	   else{
	     t=(shu)malloc(sizeof(tree));
		 t->lchild=zjl(); 
		 t->date=b;
		 t->rcjild=zjl();
	   } 
	   return t;
}
void zbl( shu t ){
	if(t!=NULL){
		zbl(t->lchild);
        printf("%c\n",t->date);
	    zbl(t->rcjild);
	}
}
shu hjl(){
	char b;
    shu f;
       scanf("%c",&b);
	   if(b=='$'){
	     f=NULL;
	   }
	   else{
	     f=(shu)malloc(sizeof(tree));
		 f->lchild=hjl(); 
		 f->date=b;
		 f->rcjild=hjl();
	   } 
	   return f;
}
void hbl( shu f ){
	if(f!=NULL){
	hbl(f->lchild);
	hbl(f->rcjild);
	printf("%c\n",f->date);
	}
}
void cd(){
	int n;
	shu f;
	shu t;
	shu p;
	printf("***************************\n");
	printf("  请选择你要执行的功能：\n\n" );
	printf("  1、先序遍历建立二叉树\n\n");
	printf("  2、中序遍历建立二叉树\n\n");
	printf("  3、后序遍历建立二叉树\n\n");
	printf("  4、退出\n\n");
	printf("  5、返回主菜单\n\n");
	printf("***************************\n");
	scanf("%d",&n);
	getchar();
	switch(n){
	case 1: 
		printf("请输入建立先序遍历二叉树数据：\n");
		printf("----------------------------\n");
		p=xjl();
		printf("----------------------------\n");
		printf("输出的先序遍历为：\n");
		printf("----------------------------\n");
		xbl(p);
		printf("----------------------------\n");
		break;
	case 2:
		printf("请输入建立中序遍历二叉树数据：\n");
     	printf("-----------------------------\n");
		p=zjl();
		printf("-----------------------------\n");
		printf("输出的中序遍历为：\n");
		printf("-----------------------------\n");
		zbl(t);
		printf("-----------------------------\n");
		break;
	case 3:
		printf("请输入建立中序遍历二叉树数据：");
     	printf("-----------------------------\n");
		p=hjl();
		printf("-----------------------------\n");
		printf("输出的后序遍历为：\n");
		printf("-----------------------------\n");
		hbl(f);
		printf("-----------------------------\n");
		break;
	case 4:
	    break;
	case 5:
		cd();
		break;
	
	}
}
int main(){
	int n;
	shu p;
	shu t;
	shu f;
    cd();
return 0;
}

