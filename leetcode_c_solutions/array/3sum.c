/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 3) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), (int (*)(const void *, const void *))strcmp);
    int** result = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;
                while (left < right && nums[left] == nums[left+1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right-1]) {
                    right--;
                }
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}
