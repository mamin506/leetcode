/*
 * @lc app=leetcode id=207 lang=c
 *
 * [207] Course Schedule
 */

// @lc code=start
// Structure for adjacency list
typedef struct Node {
    int course;
    struct Node* next;
} Node;

// Function to add a new edge to the adjacency list
void addEdge(Node** adjList, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->course = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Free the adjacency list
void freeAdjList(Node** adjList, int numCourses) {
    for (int i = 0; i < numCourses; i++) {
        Node* current = adjList[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(adjList);
}

int dfs(Node** adjList, int* visited, int course) {
    if (visited[course] == 1) {
        return 1; // Cycle detected
    }
    if (visited[course] == 2) {
        return 0; // Already visited
    }

    visited[course] = 1; // Mark as visiting
    
    // Traverse the adjacency list for the current course
    Node* current = adjList[course];
    while (current) {
        if (dfs(adjList, visited, current->course)) {
            return 1; // Cycle detected in the DFS
        }
        current = current->next;
    }
    
    visited[course] = 2; // Mark as visited
    return 0;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    if (prerequisitesSize == 0)
        return true;

    int *visited = (int*)calloc(numCourses, sizeof(int)); // Initialize to 0
    
    // Create adjacency list
    Node** adjList = (Node**)calloc(numCourses, sizeof(Node*)); // Initialize to NULL
    
    // Build the graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0]; // course
        int b = prerequisites[i][1]; // prerequisite
        addEdge(adjList, b, a); // b -> a
    }

    // DFS to detect cycles
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (dfs(adjList, visited, i)) {
                // Free allocated memory
                free(visited);
                freeAdjList(adjList, numCourses);
                return false;
            }
        }
    }
    
    // Free allocated memory
    free(visited);
    freeAdjList(adjList, numCourses);
    return true; // No cycles detected
}
// @lc code=end

