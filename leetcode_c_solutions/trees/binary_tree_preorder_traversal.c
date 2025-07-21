/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (!root) {
        return NULL;
    }
    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct TreeNode* curr = stack[top--];
        result[(*returnSize)++] = curr->val;
        if (curr->right) {
            stack[++top] = curr->right;
        }
        if (curr->left) {
            stack[++top] = curr->left;
        }
    }
    free(stack);
    return result;
}
