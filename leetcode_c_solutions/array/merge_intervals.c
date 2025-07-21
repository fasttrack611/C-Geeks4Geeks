/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (intervalsSize == 0) {
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), (int (*)(const void *, const void *))strcmp);
    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    result[*returnSize] = (int*)malloc(sizeof(int) * 2);
    (*returnColumnSizes)[*returnSize] = 2;
    result[*returnSize][0] = intervals[0][0];
    result[*returnSize][1] = intervals[0][1];
    (*returnSize)++;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[*returnSize-1][1]) {
            result[*returnSize-1][1] = (result[*returnSize-1][1] > intervals[i][1]) ? result[*returnSize-1][1] : intervals[i][1];
        } else {
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            (*returnColumnSizes)[*returnSize] = 2;
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }
    }
    return result;
}
