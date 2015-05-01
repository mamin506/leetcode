#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {

        if (board.size() < 3 || board[0].size() < 3) return;

        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] != 'X')
                visit(i, 0, board);

            if (board[i][board[0].size()-1] != 'X')
                visit(i, board[0].size()-1, board);
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] != 'X')
                visit(0, i, board);

            if (board[board.size()-1][i] != 'X')
                visit(board.size()-1, i, board);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    void visit(int i, int j, vector<vector<char>> &board) {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        board[i][j] = '#';
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            if (i > 0 && board[i-1][j] == 'O') {
                q.emplace(i-1, j);
                board[i-1][j]='#';
            }

            if (j < board[0].size()-1 && board[i][j+1] == 'O') {
                q.emplace(i, j+1);
                board[i][j+1]='#';
            }

            if (i < board.size()-1 && board[i+1][j] == 'O') {
                q.emplace(i+1, j);
                board[i+1][j]='#';
            }

            if (j > 0 && board[i][j-1] == 'O') {
                q.emplace(i, j-1);
                board[i][j-1]='#';
            }
        }
    }

    // dfs dosen't work. cause a small stack.
    //void visit(int i, int j, vector<vector<char> > &board, char visitedSign) {
    //    if (board[i][j] == 'x' || board[i][j] == visitedSign)
    //        return;
    //    
    //    board[i][j] = visitedSign;
    //    
    //    //visit up side
    //    if (i - 1 >= 0)
    //        visit(i-1, j, board, visitedSign);

    //    //visit down side
    //    if (i + 1 < board.size())
    //        visit(i+1, j, board, visitedSign);
    //    
    //    //visit left side
    //    if (j - 1 >= 0)
    //        visit(i, j-1, board, visitedSign);

    //    //visit right side
    //    if (j + 1 < board[i].size())
    //        visit(i, j+1, board, visitedSign);
    //}
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}


