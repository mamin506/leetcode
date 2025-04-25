/*
 * @lc app=leetcode id=215 lang=c
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *nums, int numsSize, int i)
{
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    if (left < numsSize && nums[largest] < nums[left])
        largest = left;

    if (right < numsSize && nums[largest] < nums[right])
        largest = right;

    if (largest != i) {
        swap(&nums[largest], &nums[i]);
        heapify(nums, numsSize, largest);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // Build a max heap
    for (int i = numsSize / 2 - 1; i >= 0; i--)
        heapify(nums, numsSize, i);

    // Extract elements from the heap
    for (int i = numsSize - 1; i >= numsSize - k; i--) {
        swap(&nums[0], &nums[i]);
        heapify(nums, i, 0);
    }

    // Return the k-th largest element
    return nums[numsSize - k];
}
// @lc code=end

