void dfs(char** grid, int i, int j, int gridSize, int* gridColSize) {
    if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, i + 1, j, gridSize, gridColSize);
    dfs(grid, i - 1, j, gridSize, gridColSize);
    dfs(grid, i, j + 1, gridSize, gridColSize);
    dfs(grid, i, j - 1, gridSize, gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (gridSize == 0) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, gridSize, gridColSize);
            }
        }
    }
    return count;
}
