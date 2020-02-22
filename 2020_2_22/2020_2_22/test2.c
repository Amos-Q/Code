#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int count(int num, int k) {
	int i = 0, count = 0;
	for (i = 0; i < k; i++) {
		if (num & 1)
			count++;
		num >>= 1;
	}
	return count;
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int size = 1, i = 0, j = 0, k = 0;
	int t = (int)pow(2, numsSize);
	*returnSize = t;
	int** result = (int**)malloc(t * sizeof(int*));
	returnColumnSizes[0] = (int*)malloc(t * sizeof(int));
	for (i = 0; i < t; i++) {
		returnColumnSizes[0][i] = count(i, numsSize);
		result[i] = (int*)malloc(returnColumnSizes[0][i] * sizeof(int));
		k = i;
		size = 0;
		for (j = 0; j < numsSize; j++) {
			if (k & 1)
				result[i][size++] = nums[j];
			k >>= 1;
		}
	}
	return result;
}
#define RET_SIZE 500
int* rightSideView(struct TreeNode* root, int* returnSize) {
	int *ret = (int*)malloc(sizeof(int) * RET_SIZE);
	int retSize = 0;
	struct TreeNode* stack[RET_SIZE];
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}
	stack[0] = root;
	int front = 0;
	int top = 0;
	int nextLevel = 0;
	int curCount = 1;
	while (top - front > -1) {
		struct TreeNode* pNode = stack[front];
		if (pNode->left != NULL) {
			stack[++top] = pNode->left;
			++nextLevel;
		}
		if (pNode->right != NULL) {
			stack[++top] = pNode->right;
			++nextLevel;
		}
		++front;
		--curCount;
		if (curCount == 0) {
			ret[retSize++] = pNode->val;
			curCount = nextLevel;
			nextLevel = 0;
		}
	}
	*returnSize = retSize;
	return ret;
}