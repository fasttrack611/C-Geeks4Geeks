#include <stdio.h>

// Function to reverse a portion of the array
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate the array to the right by k steps
void rotate(int* nums, int numsSize, int k) {
    if (numsSize <= 1 || k % numsSize == 0) return;

    k %= numsSize; // Handle cases where k > numsSize

    reverse(nums, 0, numsSize - 1);     // Reverse entire array
    reverse(nums, 0, k - 1);            // Reverse first k elements
    reverse(nums, k, numsSize - 1);     // Reverse remaining elements
}

// Utility function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    printf("Original array:\n");
    printArray(nums, numsSize);

    rotate(nums, numsSize, k);

    printf("Array after rotating right by %d steps:\n", k);
    printArray(nums, numsSize);

    return 0;
}
