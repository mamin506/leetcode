/*
 * @lc app=leetcode id=91 lang=c
 *
 * [91] Decode Ways
 */

// @lc code=start

bool isEncodeNumber(char *s, int i)
{
    int tmp;

    if (s[i - 1] == '0')
        return false;

    tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
    return tmp <= 26;
}

int numDecodings(char* s) {
    int n = strlen(s);
    int *dp = (int *)malloc(n * sizeof(int));

    if (s[0] == '0')
        return 0;

    if (n == 1)
        return 1;

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0' && s[i - 1] == '0')
            return 0;

        if (s[i] == '0') {
            if (!isEncodeNumber(s, i))
                return 0;
            dp[i] = (i == 1) ? 1 : dp[i - 2];
        } else if (isEncodeNumber(s, i)) {
            dp[i] = dp[i - 1] + ((i == 1)? 1 : dp[i - 2]);
        } else {
            dp[i] = dp[i - 1];
        }
    }

    return dp[n - 1];
}
// @lc code=end

