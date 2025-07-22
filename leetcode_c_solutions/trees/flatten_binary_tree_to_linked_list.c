/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root){
    if (root == NULL) {
        return;
    }

    struct TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            struct TreeNode* pre = curr->left;
            while (pre->right != NULL) {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
