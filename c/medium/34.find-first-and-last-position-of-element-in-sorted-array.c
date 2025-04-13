/*
 * @lc app=leetcode id=34 lang=c
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    
    if (numsSize == 0) return result;
    
    // Find first position
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    if (left < numsSize && nums[left] == target) {
        result[0] = left;
    } else {
        return result;
    }
    
    // Find last position
    right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    result[1] = right;
    return result;
}
// @lc code=end

