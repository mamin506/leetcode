#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        // Time Limit Exceeded
        //int uniquePaths(int m, int n) {
        //    if (m == 1 || n == 1)
        //        return 1;
        //    return uniquePaths(m-1,n) + uniquePaths(m, n-1);
        //}
        
        // O(100*100)
        //int uniquePaths(int m, int n) {
        //    int map[101][101];
        //    map[1][1] = 1;
        //    for (int i = 1; i <= 100; i++) {
        //        map[i][1] = 1;
        //        map[1][i] = 1;
        //    }
        //    for (int i = 2; i <= 100; i++) {
        //        for (int j = 2; j <= 100; j++) {
        //            map[i][j] = map[i][j-1] + map[i-1][j];
        //        }
        //    }
        //    return map[m][n];
        //}

        // O(m*n)
        int uniquePaths(int m, int n) {
            int[][] results = new int[m][n];
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0 || j == 0)
                        results[i][j] = 1;
                    else
                        results[i][j] = results[i][j-1] + results[i-1][j];
                }
            }
            return results[m-1][n-1];
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.uniquePaths(3, 3) << endl;
    cout << sol1.uniquePaths(4, 3) << endl;
    cout << sol1.uniquePaths(3, 4) << endl;
    cout << sol1.uniquePaths(3, 7) << endl;
    cout << sol1.uniquePaths(23, 20) << endl;

    return 0;
}

