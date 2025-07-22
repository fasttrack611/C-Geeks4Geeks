/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct {
    struct TreeNode** stack;
    int top;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* iterator = (BSTIterator*)malloc(sizeof(BSTIterator));
    iterator->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    iterator->top = -1;

    while (root != NULL) {
        iterator->stack[++(iterator->top)] = root;
        root = root->left;
    }

    return iterator;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* node = obj->stack[(obj->top)--];
    int result = node->val;

    if (node->right != NULL) {
        node = node->right;
        while (node != NULL) {
            obj->stack[++(obj->top)] = node;
            node = node->left;
        }
    }

    return result;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/
