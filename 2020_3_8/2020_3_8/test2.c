typedef struct StackNode{
    struct TreeNode* thisNode;
    struct StackNode* next;
} stackNode;

typedef struct NodeOfList{
    int val;
    struct NodeOfList* next;
} listNode;

typedef struct TreeNode treeNode;

void pushToStack(stackNode** stack, treeNode* currentNode){
    stackNode* node=malloc(sizeof(stackNode));
    node->thisNode=currentNode;
    node->next=*stack;
    *stack=node;
}

void pushToList(listNode** list, int x){
    listNode* node=malloc(sizeof(listNode)); 
    node->val=x;
    node->next=*list;
    *list=node;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    if(root==0) return 0;
    treeNode* traverse=root;
    stackNode* stackTop=0,*tmpStack;
    listNode* tmp=0,*tmpList;
    while(1){ 
        if(traverse->left){
            pushToStack(&stackTop,traverse);
            traverse=traverse->left;
            stackTop->thisNode->left=0;
        }           
        else if(traverse->right){
            pushToStack(&stackTop,traverse);
            traverse=traverse->right;
            stackTop->thisNode->right=0;
        }
        else{
            pushToList(&tmp,traverse->val);
            *returnSize=*returnSize+1;
            if(stackTop){
                traverse=stackTop->thisNode;
                tmpStack=stackTop;
                stackTop=stackTop->next;
                free(tmpStack);
            }
            else break;
        }
    }
    int i=*returnSize;
    int* res=malloc(*returnSize *sizeof(int));
    while(tmp){
        res[--i]=tmp->val;
        tmpList=tmp;
        tmp=tmp->next;
        free(tmpList);
    }
    return res;
}

typedef struct StackNode{
    struct TreeNode* thisNode;
    struct StackNode* next;
} stackNode;

typedef struct NodeOfList{
    int val;
    struct NodeOfList* next;
} listNode;

typedef struct TreeNode treeNode;

void pushToStack(stackNode** stack, treeNode* currentNode){
    stackNode* node=malloc(sizeof(stackNode));
    node->thisNode=currentNode;
    node->next=*stack;
    *stack=node;
}

void pushToList(listNode** list, int x){
    listNode* node=malloc(sizeof(listNode)); 
    node->val=x;
    node->next=*list;
    *list=node;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    if(root==0) return 0;
    treeNode* traverse=root;
    stackNode* stackTop=0,*tmpStack;
    listNode* tmp=0,*tmpList;
    while(1){ 
        if(traverse->left){
            pushToStack(&stackTop,traverse);
            traverse=traverse->left;
            stackTop->thisNode->left=0;
        }           
        else{
            pushToList(&tmp,traverse->val);
            *returnSize=*returnSize+1;
            if(traverse->right)
                traverse=traverse->right;
            else if(stackTop){
                traverse=stackTop->thisNode;
                tmpStack=stackTop;
                stackTop=stackTop->next;
                free(tmpStack);
            }
            else break;
        }
    }
    int i=*returnSize;
    int* res=malloc(*returnSize *sizeof(int));
    while(tmp){
        res[--i]=tmp->val;
        tmpList=tmp;
        tmp=tmp->next;
        free(tmpList);
    }
    return res;
}

