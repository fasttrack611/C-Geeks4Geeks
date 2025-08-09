/*C Program: Check for Duplicates Using Sorting */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to check for duplicates
bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

// Main function to test the logic
int main() {
    int nums[] = {3, 1, 4, 2, 3};  // Sample input
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, numsSize)) {
        printf("Duplicate found.\n");
    } else {
        printf("No duplicates.\n");
    }

    return 0;
}
