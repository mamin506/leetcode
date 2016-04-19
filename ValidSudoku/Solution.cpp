#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../mlibs.h"

using namespace std;

class Solution {
    public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool validLine[9][9] = {false}, validColumn[9][9] = {false}, validBlock[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i/3 + j/3 * 3;
                    if (validLine[i][num] || validColumn[j][num] || validBlock[k][num]) {
                        return false;
                    }
                    validLine[i][num] = validColumn[j][num] = validBlock[k][num] = true;
                }
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    return 0;
}

