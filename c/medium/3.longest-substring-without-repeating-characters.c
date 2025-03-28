/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
int lengthOfLongestSubstring(char* s) {
    int maxLength = 0;
    int start = 0; // Start index of the current substring
    int charIndex[128] = {0}; // Store the last index of each character

    for (int i = 0; s[i] != '\0'; i++) {
        char currentChar = s[i];
        // If the character is already in the substring, move the start index
        if (charIndex[currentChar] > start) {
            start = charIndex[currentChar];
        }
        // Update the last index of the character
        charIndex[currentChar] = i + 1; // Store next index to avoid repeat

        // Calculate max length
        maxLength = (maxLength > (i - start + 1)) ? maxLength : (i - start + 1);
    }
    return maxLength;
}
// @lc code=end

