#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != '0' && grid[i][j] != '#') {
                    count++;
                    visit(i, j, grid);
                }
            }
        }

        return count;
    }

    void visit(int i, int j, vector<vector<char> > &grid) {
        if (grid[i][j] == '0' || grid[i][j] == '#')
            return;
        
        grid[i][j] = '#';
        
        //visit up side
        if (i - 1 >= 0)
            visit(i-1, j, grid);

        //visit down side
        if (i + 1 < grid.size())
            visit(i+1, j, grid);
        
        //visit left side
        if (j - 1 >= 0)
            visit(i, j-1, grid);

        //visit right side
        if (j + 1 < grid[i].size())
            visit(i, j+1, grid);
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

