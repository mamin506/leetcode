/*
 * @lc app=leetcode id=684 lang=c
 *
 * [684] Redundant Connection
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int unionFind(int *parent, int i)
{
    int root = parent[i];

    // With path compression
    if (parent[root] != root) {
        return parent[i] = unionFind(parent, root);
    }

    return root;
}

void unionUnite(int *parent, int i, int j)
{
    parent[unionFind(parent, i)] = unionFind(parent, j);
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));
    int parent[1001];

    for (int i = 0; i < edgesSize; i++)
        parent[i] = i;

    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        if (unionFind(parent, a) == unionFind(parent, b)) {
            result[0] = a;
            result[1] = b;
            *returnSize = 2;
            return result;
        }

        unionUnite(parent, a, b);
    }

    *returnSize = 0;
    return NULL;
}
// @lc code=end

