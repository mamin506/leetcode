#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            int map[101][101];
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (obstacleGrid[i][j] == 1)
                        map[i][j] = 0;
                    if (i == 0 && j == 0)
                        map[i][j] = 1;
                    else if (i == 0)
                        map[i][j] = map[i][j-1];
                    else if (j == 0)
                        map[i][j] = map[i-1][j];
                    else
                        map[i][j] = map[i][j-1] + map[i-1][j];
                }
            }
            return map[m-1][n-1];
                
        }
};

char obst[3][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << sol1.uniquePathsWithObstacles(

    return 0;
}

