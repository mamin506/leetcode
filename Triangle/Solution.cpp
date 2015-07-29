#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if (row == 0) return 0;
        if (row == 1) return triangle[0][0];

        int *dp = new int[row];
        int min = INT_MAX;

        dp[0] = triangle[0][0];

        for (int i = 1; i < row; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == i) {
                    dp[j] = dp[j-1] + triangle[i][i];
                } else if (j == 0) {
                    dp[0] += triangle[i][0]; 
                } else {
                    dp[j] = triangle[i][j] + ((dp[j] > dp[j-1])? dp[j-1] : dp[j]); 
                }
            }
        }

        for (int i = 0; i < row; i++) {
            if (min > dp[i]) min = dp[i];
        }

        return min;
    }
    
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    
    vector<vector<int> > case1;
    vector<int> row;

    case1.push_back(row);
    case1.push_back(row);
    case1.push_back(row);
    case1.push_back(row);

    case1[0].push_back(2);

    case1[1].push_back(3);
    case1[1].push_back(4);

    case1[2].push_back(6);
    case1[2].push_back(5);
    case1[2].push_back(7);

    case1[3].push_back(4);
    case1[3].push_back(1);
    case1[3].push_back(8);
    case1[3].push_back(3);

    cout << sol1.minimumTotal(case1) << endl;

    return 0;
}

