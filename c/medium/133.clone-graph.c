#include <stdlib.h>

/*
 * @lc app=leetcode id=133 lang=c
 *
 * [133] Clone Graph
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
#define MAX_NODE 101

// 预分配节点和邻居数组内存池
static struct Node nodePool[MAX_NODE];
static struct Node* neighborPool[MAX_NODE][MAX_NODE];
static int nodeCount = 0;

struct Node *dfs_clone(struct Node *s, struct Node *visited[])
{
    if (!s) return NULL;

    if (visited[s->val])
        return visited[s->val];

    // 使用内存池中的节点
    struct Node *node = &nodePool[nodeCount++];
    node->val = s->val;
    node->numNeighbors = s->numNeighbors;
    node->neighbors = neighborPool[node->val];  // 使用预分配的邻居数组

    visited[s->val] = node;

    // 递归克隆邻居
    for (int i = 0; i < s->numNeighbors; i++) {
        node->neighbors[i] = dfs_clone(s->neighbors[i], visited);
    }

    return node;
}

struct Node *cloneGraph(struct Node *s)
{
    struct Node *visited[MAX_NODE] = {NULL};
    nodeCount = 0;  // 重置节点计数
    return dfs_clone(s, visited);
}
// @lc code=end