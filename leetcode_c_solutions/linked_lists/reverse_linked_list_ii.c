/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy;

    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }

    struct ListNode* start = pre->next;
    struct ListNode* then = start->next;

    for (int i = 0; i < right - left; i++) {
        start->next = then->next;
        then->next = pre->next;
        pre->next = then;
        then = start->next;
    }

    return dummy->next;
}
