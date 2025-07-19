#include <stdio.h>
#include "linked_list.c"

void test_create_and_display() {
    printf("Testing create and display...\n");
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);
    display(); // Expected output: 1 2 3
}

void test_reverse_display() {
    printf("Testing reverse display...\n");
    reverse_display(head); // Expected output: 3 2 1
    printf("\n");
}

void test_count() {
    printf("Testing count...\n");
    printf("Number of nodes: %d\n", count()); // Expected output: 3
}

void test_insert_at_beginning() {
    printf("Testing insert at beginning...\n");
    insert_at_beginning(0);
    display(); // Expected output: 0 1 2 3
}

void test_insert_at_end() {
    printf("Testing insert at end...\n");
    insert_at_end(4);
    display(); // Expected output: 0 1 2 3 4
}

void test_insert_at_middle() {
    printf("Testing insert at middle...\n");
    insert_at_middle(5, 3);
    display(); // Expected output: 0 1 5 2 3 4
}

void test_delete_first() {
    printf("Testing delete first...\n");
    delete_first();
    display(); // Expected output: 1 5 2 3 4
}

void test_delete_last() {
    printf("Testing delete last...\n");
    delete_last();
    display(); // Expected output: 1 5 2 3
}

void test_delete_middle() {
    printf("Testing delete middle...\n");
    delete_middle(2);
    display(); // Expected output: 1 2 3
}

void test_search() {
    printf("Testing search...\n");
    printf("Position of 2: %d\n", search(2)); // Expected output: 2
    printf("Position of 5: %d\n", search(5)); // Expected output: -1
}

void test_to_string() {
    printf("Testing to string...\n");
    char *str = to_string();
    printf("String representation: %s\n", str); // Expected output: 1 2 3
    free(str);
}

void test_to_array() {
    printf("Testing to array...\n");
    int *arr = to_array();
    printf("Array representation: ");
    for (int i = 0; i < count(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Expected output: 1 2 3
    free(arr);
}

void test_merge() {
    printf("Testing merge...\n");
    struct node *list1 = NULL;
    insert_at_end(1);
    insert_at_end(3);
    insert_at_end(5);
    list1 = head;
    head = NULL;
    insert_at_end(2);
    insert_at_end(4);
    insert_at_end(6);
    struct node *list2 = head;
    head = NULL;
    head = merge(list1, list2);
    display(); // Expected output: 1 2 3 4 5 6
}

void test_detect_and_remove_loop() {
    printf("Testing detect and remove loop...\n");
    // Create a loop
    head->next->next->next->next->next = head->next->next;
    detect_and_remove_loop();
    display(); // Expected output: 1 2 3 4 5 6
}

int main() {
    test_create_and_display();
    test_reverse_display();
    test_count();
    test_insert_at_beginning();
    test_insert_at_end();
    test_insert_at_middle();
    test_delete_first();
    test_delete_last();
    test_delete_middle();
    test_search();
    test_to_string();
    test_to_array();
    head = NULL;
    test_merge();
    test_detect_and_remove_loop();
    return 0;
}
