#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void display() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverse_display(struct node *ptr) {
    if (ptr == NULL) {
        return;
    }
    reverse_display(ptr->next);
    printf("%d ", ptr->data);
}

int count() {
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void insert_at_beginning(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void insert_at_middle(int data, int position) {
    int c = count();
    if (position < 1 || position > c + 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insert_at_beginning(data);
        return;
    }
    if (position == c + 1) {
        insert_at_end(data);
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    struct node *ptr = head;
    for (int i = 1; i < position - 1; i++) {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void delete_first() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
}

void delete_last() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *ptr = head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

void delete_middle(int position) {
    int c = count();
    if (position < 1 || position > c) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        delete_first();
        return;
    }
    if (position == c) {
        delete_last();
        return;
    }
    struct node *ptr = head;
    for (int i = 1; i < position - 1; i++) {
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

int search(int data) {
    struct node *ptr = head;
    int position = 1;
    while (ptr != NULL) {
        if (ptr->data == data) {
            return position;
        }
        ptr = ptr->next;
        position++;
    }
    return -1;
}

char *to_string() {
    int c = count();
    char *str = (char *)malloc(sizeof(char) * (c * 2));
    struct node *ptr = head;
    int i = 0;
    while (ptr != NULL) {
        sprintf(str + i, "%d ", ptr->data);
        i += 2;
        ptr = ptr->next;
    }
    return str;
}

int *to_array() {
    int c = count();
    int *arr = (int *)malloc(sizeof(int) * c);
    struct node *ptr = head;
    int i = 0;
    while (ptr != NULL) {
        arr[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }
    return arr;
}

struct node *merge(struct node *list1, struct node *list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct node *result = NULL;
    if (list1->data <= list2->data) {
        result = list1;
        result->next = merge(list1->next, list2);
    } else {
        result = list2;
        result->next = merge(list1, list2->next);
    }
    return result;
}

void detect_and_remove_loop() {
    struct node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow == fast) {
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}
