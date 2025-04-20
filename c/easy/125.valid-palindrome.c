/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 */

// @lc code=start
bool isPalindrome(char* s) {
    int lenght = strlen(s);
    int left = 0, right = lenght - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
// @lc code=end

