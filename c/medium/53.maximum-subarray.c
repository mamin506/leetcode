/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

// @lc code=start
//int maxSubArray(int* nums, int numsSize) {
//    int currSum = nums[0];
//    int maxSum = nums[0];
//
//    for (int i = 1; i < numsSize; i++) {
//        currSum = fmax(nums[i], currSum + nums[i]);
//        maxSum = fmax(maxSum, currSum);
//    }
//
//    return maxSum;
//}

int maxCrossingSum(int* nums, int left, int mid, int right) {
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubArrayHelper(int* nums, int left, int right) {
    if (left == right)
        return nums[left];

    int mid = (left + right) / 2    return fmax(
        fmax(maxSubArrayHelper(nums, left, mid),
             maxSubArrayHelper(nums, mid + 1, right)),
        maxCrossingSum(nums, left, mid, right)
    );
}

int maxSubArray(int* nums, int numsSize) {
    return maxSubArrayHelper(nums, 0, numsSize - 1);
}
// @lc code=end

