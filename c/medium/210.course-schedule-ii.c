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

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    // Initialize adjacency list and in-degree array
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int** adjList = (int**)malloc(numCourses * sizeof(int*));
    int* adjListCapacities = (int*)calloc(numCourses, sizeof(int));
    int* adjListSizes = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adjList[i] = NULL; // Initialize adjacency list as NULL
    }

    // Build the graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];

        if (adjListCapacities[prereq] == adjListSizes[prereq]) {
            adjListCapacities[prereq] = adjListCapacities[prereq] == 0 ? 2 : adjListCapacities[prereq] * 2;
            adjList[prereq] = (int*)realloc(adjList[prereq], adjListCapacities[prereq] * sizeof(int));
        }

        adjList[prereq][adjListSizes[prereq]++] = course;
        inDegree[course]++;
    }

    // Initialize the queue and result array
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    int* result = (int*)malloc(numCourses * sizeof(int));
    *returnSize = 0;

    // Add courses with zero in-degree to the queue
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Process the queue
    while (front < rear) {
        int course = queue[front++];
        result[(*returnSize)++] = course;

        for (int i = 0; i < adjListSizes[course]; i++) {
            int nextCourse = adjList[course][i];
            inDegree[nextCourse]--;
            if (inDegree[nextCourse] == 0) {
                queue[rear++] = nextCourse;
            }
        }
    }

    // Check if topological sort is possible
    if (*returnSize != numCourses) {
        *returnSize = 0;
        free(result);
        result = NULL;
    }

    // Free allocated memory
    for (int i = 0; i < numCourses; i++) {
        free(adjList[i]);
    }
    free(adjList);
    free(adjListCapacities);
    free(adjListSizes);
    free(inDegree);
    free(queue);

    return result;
}
// @lc code=end

