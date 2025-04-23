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

void unionUnite(int *parent, int *rank, int i, int j)
{
    int iRoot = unionFind(parent, i);
    int jRoot = unionFind(parent, j);

    if (iRoot == jRoot)
        return;

    if (rank[iRoot] < rank[jRoot]) {
        parent[iRoot] = jRoot;
    } else if (rank[jRoot] < rank[iRoot]) {
        parent[jRoot] = iRoot;
    } else {
        parent[jRoot] = iRoot;
        rank[iRoot]++;
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));
    int parent[1001];
    int rank[1001];

    for (int i = 0; i < edgesSize; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        if (unionFind(parent, a) == unionFind(parent, b)) {
            result[0] = a;
            result[1] = b;
            *returnSize = 2;
            return result;
        }

        unionUnite(parent, rank, a, b);
    }

    *returnSize = 0;
    return NULL;
}
// @lc code=end

