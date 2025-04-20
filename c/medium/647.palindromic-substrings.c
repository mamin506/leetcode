/*
 * @lc app=leetcode id=647 lang=c
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
int countSubstrings(char* s) {
    // Get the length of the string
    int n = strlen(s);

    // Edge case: empty string
    if (n == 0) {
        return 0;
    }

    // Create a 2D DP table where dp[i][j] indicates if substring s[i...j] is a palindrome
    bool dp[n][n];

    // Initialize DP table with false
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = false;
        }
    }

    // Count of palindromic substrings
    int count = 0;

    // Base case 1: All single characters are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        count++;
    }

    // Base case 2: Check for palindromes of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            count++;
        }
    }

    // Check for palindromes of length 3 or more
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // ending index of current substring

            // A substring is palindrome if first and last characters match
            // and the substring between them is also a palindrome
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                count++;
            }
        }
    }

    return count;
}
// @lc code=end

