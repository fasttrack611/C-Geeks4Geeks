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
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (!root) {
        return NULL;
    }
    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1;
    struct TreeNode* curr = root;
    while (curr || top != -1) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        result[(*returnSize)++] = curr->val;
        curr = curr->right;
    }
    free(stack);
    return result;
}
