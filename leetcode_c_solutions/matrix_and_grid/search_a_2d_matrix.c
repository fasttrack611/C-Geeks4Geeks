bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrixSize == 0) {
        return false;
    }

    int rows = matrixSize;
    int cols = *matrixColSize;
    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_val = matrix[mid / cols][mid % cols];

        if (mid_val == target) {
            return true;
        } else if (mid_val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}
