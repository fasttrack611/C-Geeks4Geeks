#include <stdio.h>
#include <string.h>

#define NAME_SIZE 20
#define ADDRESS_SIZE 50
#define BRANCH_SIZE 50

struct student {
    char name[NAME_SIZE];
    int roll_no;
    char address[ADDRESS_SIZE];
    char branch[BRANCH_SIZE];
};

// Function to initialize a student
void init_student(struct student *obj, const char *name, int roll_no, const char *address, const char *branch) {
    strncpy(obj->name, name, NAME_SIZE - 1);
    obj->name[NAME_SIZE - 1] = '\0'; // Ensure null-termination
    obj->roll_no = roll_no;
    strncpy(obj->address, address, ADDRESS_SIZE - 1);
    obj->address[ADDRESS_SIZE - 1] = '\0';
    strncpy(obj->branch, branch, BRANCH_SIZE - 1);
    obj->branch[BRANCH_SIZE - 1] = '\0';
}

// Function to print student details
void print_student(const struct student *obj) {
    printf("Name: %s\n", obj->name);
    printf("Roll_No: %d\n", obj->roll_no);
    printf("Address: %s\n", obj->address);
    printf("Branch: %s\n", obj->branch);
}

int main() {
    struct student obj;
    init_student(&obj, "Aleem_Shariff", 30, "Bangalore", "Computer Science And Engineering");
    print_student(&obj);

    return 0;
}
