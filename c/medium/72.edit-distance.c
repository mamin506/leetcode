/*
 * @lc app=leetcode id=72 lang=c
 *
 * [72] Edit Distance
 */

// @lc code=start
int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    if (!len1) return len2;
    if (!len2) return len1;
    
    // dp[i][j] represents the edit distance between word1[0..j-1] and word2[0..i-1]
    int *dp = (int *)calloc((len2 + 1) * (len1 + 1), sizeof(int));
    
    // Initialize first row
    for (int j = 0; j <= len1; j++) {
        dp[j] = j;
    }
    
    // Initialize first column
    for (int i = 0; i <= len2; i++) {
        dp[i * (len1 + 1)] = i;
    }
    
    // Fill the dp table
    for (int i = 1; i <= len2; i++) {
        for (int j = 1; j <= len1; j++) {
            if (word1[j-1] == word2[i-1]) {
                dp[i * (len1 + 1) + j] = dp[(i-1) * (len1 + 1) + (j-1)];
            } else {
                int replace = dp[(i-1) * (len1 + 1) + (j-1)];
                int delete = dp[i * (len1 + 1) + (j-1)];
                int insert = dp[(i-1) * (len1 + 1) + j];
                dp[i * (len1 + 1) + j] = 1 + fmin(replace, fmin(delete, insert));
            }
        }
    }
    
    int result = dp[len2 * (len1 + 1) + len1];
    free(dp);
    return result;
}
// @lc code=end

