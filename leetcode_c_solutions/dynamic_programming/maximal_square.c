int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0) {
        return 0;
    }

    int rows = matrixSize;
    int cols = *matrixColSize;
    int** dp = (int**)malloc(sizeof(int*) * (rows + 1));
    for (int i = 0; i <= rows; i++) {
        dp[i] = (int*)calloc(cols + 1, sizeof(int));
    }

    int max_side = 0;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = fmin(fmin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                max_side = fmax(max_side, dp[i][j]);
            }
        }
    }

    for (int i = 0; i <= rows; i++) {
        free(dp[i]);
    }
    free(dp);

    return max_side * max_side;
}
