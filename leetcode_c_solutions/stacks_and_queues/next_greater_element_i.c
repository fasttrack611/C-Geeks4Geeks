/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size;
    int* result = (int*)malloc(nums1Size * sizeof(int));
    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1;
    int* map = (int*)calloc(10001, sizeof(int));

    for (int i = 0; i < nums2Size; i++) {
        while (top != -1 && nums2[i] > stack[top]) {
            map[stack[top--]] = nums2[i];
        }
        stack[++top] = nums2[i];
    }

    for (int i = 0; i < nums1Size; i++) {
        result[i] = map[nums1[i]] ? map[nums1[i]] : -1;
    }

    free(stack);
    free(map);
    return result;
}
