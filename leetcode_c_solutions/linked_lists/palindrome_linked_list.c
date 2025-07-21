/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        struct ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    if (fast) {
        slow = slow->next;
    }
    while (slow) {
        if (slow->val != prev->val) {
            return false;
        }
        slow = slow->next;
        prev = prev->next;
    }
    return true;
}
