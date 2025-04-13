/*
 * @lc app=leetcode id=46 lang=c
 *
 * [46] Permutations
 */

// @lc code=start

void backtrack(int* nums, int numsSize, int** result, int* returnSize, int* current, int* used, int pos) {
    if (pos == numsSize) {
        result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            used[i] = 1;
            current[pos] = nums[i];
            backtrack(nums, numsSize, result, returnSize, current, used, pos + 1);
            used[i] = 0;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Calculate n! for total number of permutations
    int total = 1;
    for (int i = 1; i <= numsSize; i++) {
        total *= i;
    }
    
    // Allocate result array
    int** result = (int**)malloc(sizeof(int*) * total);
    *returnColumnSizes = (int*)malloc(sizeof(int) * total);
    
    // Initialize arrays for backtracking
    int* current = (int*)malloc(sizeof(int) * numsSize);
    int* used = (int*)calloc(numsSize, sizeof(int));
    *returnSize = 0;
    
    // Generate permutations
    backtrack(nums, numsSize, result, returnSize, current, used, 0);
    
    // Set column sizes
    for (int i = 0; i < total; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    // Free temporary arrays
    free(current);
    free(used);
    
    return result;
}
// @lc code=end

