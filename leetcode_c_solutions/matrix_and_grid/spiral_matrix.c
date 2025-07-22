/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int m = matrixSize;
    int n = *matrixColSize;
    int* result = (int*)malloc(sizeof(int) * m * n);
    *returnSize = m * n;

    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result[k++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[k++] = matrix[i][right];
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[k++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[k++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}
