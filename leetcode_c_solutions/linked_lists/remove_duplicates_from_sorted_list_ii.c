/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy;

    while (head != NULL) {
        if (head->next != NULL && head->val == head->next->val) {
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            pre->next = head->next;
        } else {
            pre = pre->next;
        }
        head = head->next;
    }

    return dummy->next;
}
