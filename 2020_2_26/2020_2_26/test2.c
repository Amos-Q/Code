#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
 #include <stdlib.h>
 
 typedef struct TreeNode{
     char ch;
     struct TreeNode *lchild, *rchild;
 }Tree, *PTree;//�������ڵ�Ľṹ��
 void createBiTree(PTree *p)//����������
 {
     char ch;
     scanf("%c", &ch);
     getchar();//��ʱ%c��ȡ���ǵ����ַ����������Ǹ�getchar������һ��
     if(ch == '#')
          *p = NULL;
     else
     {
         *p = (PTree)malloc(sizeof(Tree));
         (*p) -> ch = ch;
         printf("������%c��������\n", ch);
         createBiTree(&(*p) -> lchild);
         printf("������%c��������\n", ch);
         createBiTree(&(*p) -> rchild);
     }
 
 }
 void preOrderTraverse(PTree p)//ǰ�����
 {
     if(p == NULL)
         return ;
     printf("%c ", p -> ch);
     preOrderTraverse(p -> lchild);
     preOrderTraverse(p -> rchild);
 }
 void InOrderTraverse(PTree p)//�������
 {
     if(p == NULL)
         return;
     InOrderTraverse(p -> lchild);
     printf("%c ", p -> ch);
     InOrderTraverse(p -> rchild);
 }
 void BackOrderTraverse(PTree p)//��������
 {
     if(p == NULL)
         return ;
     BackOrderTraverse(p -> lchild);     BackOrderTraverse(p -> rchild);
     printf("%c ", p -> ch);
 }
 int main()
 {
     PTree pt;
     createBiTree(&pt);
     preOrderTraverse(pt);
     printf("\n");
     InOrderTraverse(pt);
     printf("\n");
     BackOrderTraverse(pt);
     printf("\n");
     return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define N 20
 
//���������Ľṹ���ʾ��ʽ
typedef struct tree
{
    char ch;
    struct tree *lchild;
	struct tree *rchild;
}BitTree;
 
//���������������õݹ�ķ���
//��ǰ��������롣 �� A # #(#��ʾ����)
BitTree *CreateTree()
{
	BitTree *bt;
    char str; 
    scanf("%c",&str);
    if (str=='#')
        return NULL;
    else
    {
        bt=(BitTree *)malloc(sizeof(BitTree));
        bt->ch=str;
        bt->lchild=CreateTree();
        bt->rchild=CreateTree();
        return bt;
    }
}
 
//ǰ������ķǵݹ�ʵ��
/*
 ˼�룺����ջ��ʵ�֣�������ջ��֮��ջ�ǿգ����������Ÿ��ڵ���ҽ���ջ��
 ֮����ڵ��ջ�����ţ�����ջ��Ԫ�أ������,
 �˽����ҽ���ջ��֮����ڵ��ջ������ջ��Ԫ�أ������...һֱ������ȥ��
 ֱ��ջΪ�ա�
 */
void PreOrder(BitTree *bt)
{
    BitTree **s;
	BitTree *p;
	int top=-1;
	//����ջ��
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//��ʼ��ջ��
	s[++top]=bt;
	//�ǵݹ�ǰ�������
	while(top!=-1)
	{
		p=s[top--];
		printf("%c ",p->ch);    //ջ���ص㣬�Ƚ������
		if(p->rchild)
			s[++top]=p->rchild;
		if(p->lchild)
			s[++top]=p->lchild;
	}
	free(s);
}
 
 
//����������ǵݹ�ʵ��
/*
 ˼�룺����ջ���Ӹ��ڵ㿪ʼѭ����ֻҪ�����ӽڵ����ջ��ֱ�����ӽڵ�Ϊ�ա�
 ���ŵ���ջ��������жϸý���Ƿ������ӽڵ㣬
 �������ջ����û�м�����ջ�������ӽڵ��������жϸýڵ��Ƿ������ӽڵ㣬
 �����ջ��ֱ�����ӽڵ�Ϊ�գ��������ӽڵ�û��
 ���ӽڵ㣬��ջ���жϵ����Ľڵ㣬�Ƿ������ӽڵ㣬�������ջ��û�м�����ջ��
 ������Ҫ�жϸս�ջ������ڵ㣬�Ƿ������ӽڵ㣬
 �����ջ��û���������ջ���ظ���ȥ....
 ջ�գ����ж�������
 */
void InOrder(BitTree *bt)
{
	BitTree **s;
    BitTree *p,*q;
    int top=-1;
	//����ջ��
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//�ǵݹ����������
    if(bt)
    {
        while(bt)   //һֱ����������ֱ���ý������ӿ�Ϊֹ��
        {
            s[++top]=bt;   //���������Ӵ���ջ�У�
            bt=bt->lchild;     //ָ����һ����������
        }
        while(top!=-1)  //ջ��ʱ����ѭ����
        {
            p=s[top--];//�տ�ʼ����pָ�����½ǵ����ӣ���������ý��ĸ���㣻
            printf("%c ",p->ch);  //������½ǵĽ�㣻
            while(p->rchild)  //�����ƶ�������û���ҽ�㣻
            {
                s[++top]=p->rchild;   //�����������������ջ��
                q=p->rchild;		  //�����������㸳��q��
                while(q->lchild)      //�жϽ��q��û����������
                {
                    s[++top]=q->lchild;  //����������������������������������������ջ��
                    q=q->lchild;
                }
                break;   //������ǰѭ�����ص��ڶ���whileѭ�������ղŵĲ��裻
            }
        }
    }
}
 
//����������ǵݹ�ʵ��
/*
 �㷨˼��:����ջ��ʵ�֡��Ӹ���㿪ʼ,ֻҪ���ӽڵ�ǿ�,���ջ,ֱ�����ӽڵ�
 Ϊ��Ϊֹ��ȡ��ջ��Ԫ��(ֻ��ȡ,���ǵ�ջ),�ж�:
 1:ȡ����ջ��Ԫ���Ƿ������ӽڵ�,�������ӽڵ��Ƿ񱻷��ʹ�,����������(������
 �ڵ�,�������ӽڵ㱻���ʹ�),������ý�㣬ͬʱ��ջ,���Ҽ�¼�¸÷��ʵĽڵ㡣
 2:ȡ����ջ��Ԫ�أ��������ӽڵ㣬��δ�����ʹ�����ָ������ƶ������ӽڵ㣬
 �ظ�һ��ʼ�Ƿ������ӽڵ���жϡ�
*/
void PostOrder(BitTree *bt)
{	
	BitTree **s;
	BitTree *p;
    int top=-1;
	//����ջ��
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//�ǵݹ���������
    do
    {
        while(bt)     //һֱ����������ֱ���������������ӿ�Ϊֹ��
        {
            s[++top]=bt;     //���������Ӵ���ջ�У�
            bt=bt->lchild;   //ָ����һ����������
        }
        p=NULL;
        while(top!=-1)
        {
            bt=s[top];
            if(bt->rchild==p)  //p:��ʾΪnull���������ӽڵ㱻���ʹ���;
            {
                printf("%c ",bt->ch);   //������������
                top--;           //����Ժ�top--��
                p=bt;  //p��¼�¸ոշ��ʵĽڵ�;
            }
            else
            {
                bt=bt->rchild;   //������������㣻
                break;
            }
        }
    }while(top!=-1);
}
 
int main()
{
????printf("����˳�����������(#��ʾ�ý����ӽ��Ϊ��):\n");
    BitTree *btr=CreateTree();
    printf("ǰ������ǵݹ�ʵ�֣�\n");
    PreOrder(btr);
    printf("\n");
    printf("��������ǵݹ�ʵ�֣�\n");
    InOrder(btr);
    printf("\n");
    printf("��������ǵݹ�ʵ�֣�\n");
    PostOrder(btr);
    printf("\n");
    return 0;
}