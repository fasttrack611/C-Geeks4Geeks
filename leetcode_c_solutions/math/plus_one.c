/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }

    *returnSize = digitsSize + 1;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    result[0] = 1;
    for (int i = 0; i < digitsSize; i++) {
        result[i + 1] = digits[i];
    }

    return result;
}
