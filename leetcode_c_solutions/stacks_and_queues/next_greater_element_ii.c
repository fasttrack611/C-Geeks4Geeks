/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = -1;
    }
    int* stack = (int*)malloc(numsSize * 2 * sizeof(int));
    int top = -1;
    for (int i = 0; i < numsSize * 2; i++) {
        int num = nums[i % numsSize];
        while (top != -1 && nums[stack[top]] < num) {
            result[stack[top--]] = num;
        }
        if (i < numsSize) {
            stack[++top] = i;
        }
    }
    free(stack);
    return result;
}
