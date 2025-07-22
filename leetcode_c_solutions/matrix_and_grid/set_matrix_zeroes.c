void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    for (int j = 0; j < *matrixColSize; j++) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < *matrixColSize; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowHasZero) {
        for (int j = 0; j < *matrixColSize; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColHasZero) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}
