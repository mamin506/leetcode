/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start
#include <stdlib.h> // For malloc and NULL

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));
    if (!result) return NULL; // Handle memory allocation failure

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2; // Set the size of the returned array
                return result;
            }
        }
    }

    *returnSize = 0; // In case no solution is found
    return NULL; // Return NULL if no solution exists
}
// @lc code=end

