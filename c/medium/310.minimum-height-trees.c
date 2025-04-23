/*
 * @lc app=leetcode id=310 lang=c
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void updateGraph(int *graph, int n, int *nodeDegree, int *queue, int *head, int *tail) {
    if (*tail - *head == 1)
        return;

    if (*tail - *head == 2 && *tail == n)
        return;

    int count = *tail - *head;
    for (int k = 0; k < count; k++)
    {
        int i = queue[(*head)++];
        int j;

        nodeDegree[i] = 0;
        j = graph[i];
        graph[j] ^= i;
        nodeDegree[j]--;
        if (nodeDegree[j] == 1)
        {
            queue[(*tail)++] = j;
        }
    }
    updateGraph(graph, n, nodeDegree, queue, head, tail);
}

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));

    if (n == 1) {
        result[0] = 0;
        *returnSize = 1;
        return result;
    }

    if (n == 2) {
        result[0] = 0;
        result[1] = 1;
        *returnSize = 2;
        return result;
    }

    int nodeDegree[20000] = {0};
    int graph[20000] = {0};
    int queue[20000];
    int head = 0, tail = 0;

    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        graph[a] ^= b;
        graph[b] ^= a;
        nodeDegree[a]++;
        nodeDegree[b]++;
    }

    for (int i = 0; i < n; i++) {
        if (nodeDegree[i] == 1) {
            queue[tail++] = i;
        }
    }

    updateGraph(graph, n, nodeDegree, queue, &head, &tail);

    *returnSize = tail - head;
    for (int i = 0; i < *returnSize; i++) {
        result[i] = queue[head + i];
    }

    return result;
}
// @lc code=end

