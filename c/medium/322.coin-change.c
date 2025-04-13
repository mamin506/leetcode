/*
 * @lc app=leetcode id=322 lang=c
 *
 * [322] Coin Change
 */

// @lc code=start
//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//int coinChange(int* coins, int coinsSize, int amount) {
//    if (amount == 0) return 0;
//    if (coinsSize == 0) return -1;
//
//    // Sort coins in ascending order
//    qsort(coins, coinsSize, sizeof(int), compare);
//
//    // If smallest coin is larger than amount
//    if (coins[0] > amount) return -1;
//
//    // If largest coin divides amount perfectly
//    if (amount % coins[coinsSize-1] == 0)
//        return amount / coins[coinsSize-1];
//
//    int* dp = (int*)calloc(amount + 1, sizeof(int));
//    for (int i = 1; i <= amount; i++) {
//        dp[i] = INT_MAX - 1;
//    }
//
//    for (int i = 0; i < coinsSize; i++) {
//        int coin = coins[i];
//        for (int j = coin; j <= amount; j++) {
//            if (dp[j - coin] != INT_MAX - 1) {
//                int newVal = dp[j - coin] + 1;
//                if (newVal < dp[j]) {
//                    dp[j] = newVal;
//                }
//            }
//        }
//    }
//
//    int result = dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
//    free(dp);
//    return result;
//}

//int coinChange(int* coins, int coinsSize, int amount) {
//    if (amount == 0) return 0;
//    if (coinsSize == 0) return -1;
//
//    // 使用visited数组来避免重复访问
//    bool* visited = (bool*)calloc(amount + 1, sizeof(bool));
//    // 使用queue来存储待访问的金额
//    int* queue = (int*)malloc((amount + 1) * sizeof(int));
//    int front = 0, rear = 0;
//
//    // 初始状态：将0加入队列
//    queue[rear++] = 0;
//    visited[0] = true;
//    int level = 0;
//
//    while (front < rear) {
//        int size = rear - front;  // 当前层的节点数
//        level++;
//
//        while (size--) {
//            int curr = queue[front++];
//
//            for (int i = 0; i < coinsSize; i++) {
//                int next = curr + coins[i];
//
//                if (next == amount) {
//                    free(visited);
//                    free(queue);
//                    return level;
//                }
//
//                if (next < amount && !visited[next]) {
//                    visited[next] = true;
//                    queue[rear++] = next;
//                }
//            }
//        }
//    }
//
//    free(visited);
//    free(queue);
//    return -1;
//}

int coinChange(int* coins, int coinsSize, int amount) {
    int *numChange = (int *)calloc(amount + 1, sizeof(int));
    int minChange;

    for (int i = 1; i <= amount; i++) {
        numChange[i] = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            if (i < coins[j] || numChange[i - coins[j]] == INT_MAX)
                continue;
            numChange[i] = fmin(numChange[i], numChange[i - coins[j]] + 1);
        }
    }

    minChange = numChange[amount] == INT_MAX ? -1 : numChange[amount];
    free(numChange);
    return minChange;
}
// @lc code=end

