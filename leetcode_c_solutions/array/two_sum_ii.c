/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSumII(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int) * 2);
    int left = 0;
    int right = numbersSize - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return NULL;
}
