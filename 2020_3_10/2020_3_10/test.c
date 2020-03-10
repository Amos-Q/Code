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

void Inorder(struct TreeNode* root, int* arr,int i)
{
	if (root != NULL)
	{
		++i;
		arr[i] = root->val;
		Inorder(root->lchild, arr,i);
		Inorder(root->rchild,arr,i);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int s = sum(root);
	*returnSize = s;
	int* arr = (int*)malloc(sizeof(int)*s);
	int i = -1;
	Inorder(root, arr,i);
	return returnSize;
}