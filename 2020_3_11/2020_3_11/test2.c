#define _CRT_SECURE_NO_WARNINGS 1
int sum(struct TreeNode* root)
{
    int s = 0;
    if (root == NULL)
        return 0;
    else
        s = 1 + sum(root->left) + sum(root->right);
    return s;
}


void Inorder(struct TreeNode* root, int* arr,int* i)
{
    if (root != NULL)
    {
        arr[++(*i)] = root->val;
        Inorder(root->left, arr,i);
        Inorder(root->right,arr,i);
    }
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int s = sum(root);
    *returnSize = s;
    int* arr = (int*)malloc(sizeof(int)*s);
    int i = -1;
    Inorder(root,arr,&i);
    return arr;
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
    return true;
    if(p && q == NULL)
    return false;
    if(q && p == NULL)
    return false;
    if(p->val == q->val)
    {
        return isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
    return true;
    return isSameTree(root->left,root->right);
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
    return true;
    if(p && q == NULL)
    return false;
    if(q && p == NULL)
    return false;
    if(p->val == q->val)
    {
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    return false;
}
struct TreeNode* invertTree(struct TreeNode* root){
    if(root != NULL)
    {
        struct TreeNode* tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}