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
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (!root) {
        return NULL;
    }
    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1;
    struct TreeNode* lastVisited = NULL;
    while (root || top != -1) {
        if (root) {
            stack[++top] = root;
            root = root->left;
        } else {
            struct TreeNode* node = stack[top];
            if (node->right && node->right != lastVisited) {
                root = node->right;
            } else {
                result[(*returnSize)++] = node->val;
                lastVisited = node;
                top--;
            }
        }
    }
    free(stack);
    return result;
}
