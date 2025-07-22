/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void kthSmallestHelper(struct TreeNode* root, int* k, int* result) {
    if (root == NULL) {
        return;
    }

    kthSmallestHelper(root->left, k, result);

    (*k)--;
    if (*k == 0) {
        *result = root->val;
        return;
    }

    kthSmallestHelper(root->right, k, result);
}

int kthSmallest(struct TreeNode* root, int k){
    int result = 0;
    kthSmallestHelper(root, &k, &result);
    return result;
}
