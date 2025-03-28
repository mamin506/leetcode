/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array
    if (nums1Size > nums2Size) {
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }

    int totalLength = nums1Size + nums2Size;
    int half = (totalLength + 1) / 2;

    int left = 0, right = nums1Size;

    while (left <= right) {
        int i = (left + right) / 2; // Partition index for nums1
        int j = half - i; // Partition index for nums2

        int maxLeftX = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRightX = (i == nums1Size) ? INT_MAX : nums1[i];

        int maxLeftY = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRightY = (j == nums2Size) ? INT_MAX : nums2[j];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Found the correct partition
            if (totalLength % 2 == 0) {
                return (fmax(maxLeftX, maxLeftY) + fmin(minRightX, minRightY)) / 2;
            } else {
                return fmax(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            right = i - 1; // Move partition in nums1 to the left
        } else {
            left = i + 1; // Move partition in nums1 to the right
        }
    }

    return 0.0; // This line should never be reached
}
// @lc code=end

