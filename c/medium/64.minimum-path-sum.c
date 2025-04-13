/*
 * @lc app=leetcode id=64 lang=c
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int *dp;
    int minSum;

    dp = (int *)calloc(m * n, sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i * n + j] = grid[i][j];
                continue;
            }

            if (i == 0) {
                dp[i * n + j] = dp[i * n + j - 1] + grid[i][j];
            } else if (j == 0) {
                dp[i * n + j] = dp[(i - 1) * n + j] + grid[i][j];
            } else {
                dp[i * n + j] = fmin(dp[i * n + j - 1], dp[(i - 1) * n + j]) + grid[i][j];
            }
        }
    }    /* code */
    minSum = dp[m * n - 1];
    free(dp);
    return minSum;
}
// @lc code=end

