#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Creates a new list node with a given value.
 */
struct ListNode* create_node(int value) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

/**
 * Adds two numbers represented as linked lists (reversed order).
 * Each node contains a single digit. Returns a new linked list.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = {0, NULL};   // Dummy head node
    struct ListNode* tail = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        tail->next = create_node(sum % 10);
        tail = tail->next;
    }

    return dummy.next;
}

/**
 * Utility function: prints a linked list.
 */
void print_list(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

/**
 * Utility function: inserts a new node at the end of the list.
 */
void append_node(struct ListNode** head_ref, int value) {
    struct ListNode* new_node = create_node(value);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct ListNode* current = *head_ref;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

int main(void) {
    // Construct list l1 = 2 -> 4 -> 3 (represents 342)
    struct ListNode* l1 = NULL;
    append_node(&l1, 2);
    append_node(&l1, 4);
    append_node(&l1, 3);

    // Construct list l2 = 5 -> 6 -> 4 (represents 465)
    struct ListNode* l2 = NULL;
    append_node(&l2, 5);
    append_node(&l2, 6);
    append_node(&l2, 4);

    printf("Input List 1: ");
    print_list(l1);
    printf("Input List 2: ");
    print_list(l2);

    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Sum List:     ");
    print_list(result);

    // Memory cleanup can be added if desired
    return 0;
}
