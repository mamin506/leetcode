#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //int rob(vector<int> &num) {
    //    int pre = 0, pre_2 = 0;
    //    for (int i = 0; i < num.size(); i++) {
    //        pre_2 = max(pre_2+num[i], pre);     // the max amount of money I can rob after the i house has been robbed
    //        swap(pre, pre_2);                   // prepare for the next rob
    //    }
    //    return pre;
    //}
 
    int rob(vector<int> &num) {
        if (num.size() == 0) return 0;

        vector<vector<int> > rob(2);
        rob[0].assign(num.size(), 0);
        rob[1].assign(num.size(), 0);

        rob[1][0] = num[0];
        int sum = 0;

        for (int i = 1; i < num.size(); i++) {
            rob[0][i] = max(rob[0][i-1], rob[1][i-1]);
            rob[1][i] = rob[0][i-1] + num[i-1];
        }
        return max(rob[0][num.size() - 1], rob[1][num.size() - 1]);
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

