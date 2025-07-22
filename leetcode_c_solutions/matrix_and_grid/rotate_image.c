void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i; j < *matrixColSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][*matrixColSize - 1 - j];
            matrix[i][*matrixColSize - 1 - j] = temp;
        }
    }
}
