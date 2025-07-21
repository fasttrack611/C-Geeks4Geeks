/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (!root) {
        return NULL;
    }
    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    struct TreeNode** queue = (struct TreeNode**)malloc(1000 * sizeof(struct TreeNode*));
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    while (head != tail) {
        int size = tail - head;
        result[*returnSize] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;
        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[head++];
            result[*returnSize][i] = curr->val;
            if (curr->left) {
                queue[tail++] = curr->left;
            }
            if (curr->right) {
                queue[tail++] = curr->right;
            }
        }
        (*returnSize)++;
    }
    free(queue);
    return result;
}
