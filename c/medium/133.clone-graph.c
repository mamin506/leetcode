#include <stdlib.h>

/*
 * @lc app=leetcode id=133 lang=c
 *
 * [133] Clone Graph
 */

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

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

static struct Node nodePool[MAX_NODE];
static struct Node* neighborPool[MAX_NODE][MAX_NODE];
static int nodeCount;

struct Node *dfs_clone(struct Node *s, struct Node *visited[])
{
    if (!s) return NULL;
    
    if (visited[s->val])
        return visited[s->val];

    struct Node *node = &nodePool[nodeCount++];
    node->val = s->val;
    node->numNeighbors = s->numNeighbors;
    node->neighbors = neighborPool[node->val];

    visited[s->val] = node;

    for (int i = 0; i < s->numNeighbors; i++) {
        node->neighbors[i] = dfs_clone(s->neighbors[i], visited);
    }

    return node;
}

struct Node *cloneGraph(struct Node *s)
{
    if (!s) return NULL;
    
    struct Node *visited[MAX_NODE] = {NULL};
    nodeCount = 0;
    return dfs_clone(s, visited);
}
// @lc code=end