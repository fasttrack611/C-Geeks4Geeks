/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void getMinimumDifferenceHelper(struct TreeNode* root, int* minDiff, int* prev) {
    if (root == NULL) {
        return;
    }

    getMinimumDifferenceHelper(root->left, minDiff, prev);

    if (*prev != -1) {
        *minDiff = fmin(*minDiff, root->val - *prev);
    }
    *prev = root->val;

    getMinimumDifferenceHelper(root->right, minDiff, prev);
}

int getMinimumDifference(struct TreeNode* root){
    int minDiff = INT_MAX;
    int prev = -1;
    getMinimumDifferenceHelper(root, &minDiff, &prev);
    return minDiff;
}
