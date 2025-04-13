/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 */

// @lc code=start
int divide(int dividend, int divisor) {
    long long ldividend = labs((long long)dividend);
    long long ldivisor = labs((long long)divisor);
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    long long result = 0;
    while (ldividend >= ldivisor) {
        long long temp = ldivisor;
        long long multiple = 1;

        // Keep doubling divisor while it's less than dividend
        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        ldividend -= temp;
        result += multiple;
    }

    result *= sign;
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;
    return result;
}
// @lc code=end
