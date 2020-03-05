#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root) {
	if (!root)   return 0;

	int l = minDepth(root->left);
	int r = minDepth(root->right);	//递归分别计算左右子树的最小深度

	if (l == 0 || r == 0) return 1 + l + r;	//当前子树只有一个子树的情况

	return 1 + ((l < r) ? l : r);
}

#define bool int
#define true 1
#define false 0
bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL)
		return true;

	if (root->left && root->left->val != root->val)
		return false;

	if (root->right && root->right->val != root->val)
		return false;

	// root root->left root->right 都是相等的
	// 递归左子树 递归右子树
	return  isUnivalTree(root->left) && isUnivalTree(root->right);
}