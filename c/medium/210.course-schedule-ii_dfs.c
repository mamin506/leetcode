#include <stddef.h> // For NULL

/*
 * @lc app=leetcode id=210 lang=c
 *
 * [210] Course Schedule II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Node {
    int inEdge;
    int solved;
    struct edgeNode *next;
};

struct edgeNode {
    int course;
    struct edgeNode *next;
};

void addEdge(struct Node *node, struct edgeNode *edge)
{
    edge->next = node->next;
    node->next = edge;
}

void delEdge(struct Node *node, int i)
{
    struct edgeNode *edge;

    while (node[i].next != NULL) {
        edge = node[i].next;

        node[i].next = edge->next;
        node[edge->course].inEdge--;
        free(edge);
    }
}

void buildCourseGraph(struct Node *courses, int **prerequisites, int prerequisitesSize)
{
    int pre, post;

    for (int i = 0; i < prerequisitesSize; i++) {
        post = prerequisites[i][0];
        pre = prerequisites[i][1];

        struct edgeNode *edge = (struct edgeNode *)malloc(sizeof(struct edgeNode));
        printf("pre %d post %d\n", pre, post);
        edge->course = post;
        courses[post].inEdge++;
        addEdge(&courses[pre], edge);
    }
}

void topologySortUtil(struct Node *courses, int course, int *visited, int *stack, int *stackSize, int *hasCycle)
{
    struct edgeNode *edge;

    if (*hasCycle) return; // Stop further processing if a cycle is detected

    visited[course] = 1; // Mark the course as being visited

    edge = courses[course].next;
    while (edge != NULL) {
        if (visited[edge->course] == 1) {
            *hasCycle = 1; // Cycle detected
            return;
        } else if (visited[edge->course] == 0) {
            // DFS
            topologySortUtil(courses, edge->course, visited, stack, stackSize, hasCycle);
        }
        edge = edge->next;
    }

    visited[course] = 2; // Mark the course as fully processed
    stack[*stackSize] = course;
    (*stackSize)++;
}

int *topologySort1(struct Node *courses, int numCourses, int *returnSize)
{
    int *visited = (int *)calloc(numCourses, sizeof(int));
    int *stack = (int *)malloc(numCourses * sizeof(int));
    int *result = (int *)malloc(numCourses * sizeof(int));
    int stackSize = 0;
    int hasCycle = 0;

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            topologySortUtil(courses, i, visited, stack, &stackSize, &hasCycle);
        }
        if (hasCycle) {
            *returnSize = 0;
            free(visited);
            free(stack);
            free(result);
            return NULL; // Return NULL if a cycle is detected
        }
    }

    for (int i = 0; i < stackSize; i++) {
        result[i] = stack[stackSize - i - 1];
    }

    *returnSize = stackSize;
    free(visited);
    free(stack);
    return result;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    struct Node * courses = (struct Node *)calloc(numCourses, sizeof(struct Node));
    int *result;

    if (prerequisites == NULL || prerequisitesSize == 0) {
        result = (int *)malloc(numCourses * sizeof(int));
        *returnSize = numCourses;
        for (int i = 0; i < numCourses; i++) {
            result[i] = i;
        }
        free(courses); // Free allocated memory for courses
        return result;
    }

    buildCourseGraph(courses, prerequisites, prerequisitesSize);
    result = topologySort1(courses, numCourses, returnSize);

    free(courses); // Free allocated memory for courses
    return result;
}
// @lc code=end

