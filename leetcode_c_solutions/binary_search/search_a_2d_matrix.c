bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int rows = matrixSize;
    int cols = *matrixColSize;
    int left = 0;
    int right = rows * cols - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midElement = matrix[mid / cols][mid % cols];
        if (midElement == target) {
            return true;
        }
        if (midElement < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
