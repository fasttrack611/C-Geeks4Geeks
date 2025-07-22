/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSumHelper(struct TreeNode* root, int* maxSum) {
    if (root == NULL) {
        return 0;
    }

    int left = fmax(0, maxPathSumHelper(root->left, maxSum));
    int right = fmax(0, maxPathSumHelper(root->right, maxSum));

    *maxSum = fmax(*maxSum, left + right + root->val);

    return fmax(left, right) + root->val;
}

int maxPathSum(struct TreeNode* root){
    int maxSum = INT_MIN;
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}
