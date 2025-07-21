#include <stdio.h>
#include <stdlib.h>

// 💡 Definition of a singly linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// 🧱 Creates a new list node with a given value
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

// 📥 Appends a node to the end of a list
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

// 📋 Prints the contents of a linked list
void print_list(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// 🔁 Recursively merges two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main(void) {
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    // 🧪 Create first sorted list: 1 → 3 → 5
    append_node(&list1, 1);
    append_node(&list1, 3);
    append_node(&list1, 5);

    // 🧪 Create second sorted list: 2 → 4 → 6
    append_node(&list2, 2);
    append_node(&list2, 4);
    append_node(&list2, 6);

    printf("List 1: ");
    print_list(list1);

    printf("List 2: ");
    print_list(list2);

    // 🔄 Merge the lists
    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    print_list(merged);

    return 0;
}
