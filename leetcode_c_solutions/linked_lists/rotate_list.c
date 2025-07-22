/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int len = 1;
    struct ListNode* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
        len++;
    }

    curr->next = head;
    k %= len;

    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }

    head = curr->next;
    curr->next = NULL;

    return head;
}
