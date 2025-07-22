/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* level_start = root;
    while (level_start != NULL) {
        struct Node* curr = level_start;
        while (curr != NULL) {
            if (curr->left != NULL) {
                curr->left->next = curr->right;
            }
            if (curr->right != NULL && curr->next != NULL) {
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
        }
        level_start = level_start->left;
    }

    return root;
}
