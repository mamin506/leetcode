/*
 * @lc app=leetcode id=30 lang=c
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int len = strlen(s);
    int wordLen = strlen(words[0]);
    int totalLen = wordsSize * wordLen;
    int* result = (int*)malloc(len * sizeof(int));
    int *currentCount = (int *)malloc(wordsSize * sizeof(int));

    *returnSize = 0;
    if (len == 0 || wordsSize == 0 || wordLen == 0 || totalLen > len) {
        return result;
    }

    int* wordCount = (int*)malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        wordCount[i] = 0;
        for (int j = 0; j < len; j++) {
            if (strcmp(words[i], s + j) == 0) {
                wordCount[i]++;
            }
        }
    }

    for (int i = 0; i <= len - totalLen; i++) {
        int j;
        for (j = 0; j < wordsSize; j++) {
            currentCount[j] = 0;
        }
        for (j = 0; j < wordsSize; j++) {
            if (strcmp(s + i + j * wordLen, words[j]) == 0) {
                currentCount[j]++;
            }
        }
        for (j = 0; j < wordsSize; j++) {
            if (currentCount[j] != wordCount[j]) {
                break;
            }
        }
        if (j == wordsSize) {
            result[(*returnSize)++] = i;
        }
    }
    free(wordCount);
    free(currentCount);
    return result;
}
// @lc code=end

