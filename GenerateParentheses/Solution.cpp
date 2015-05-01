#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    vector<string> ret;

    vector<string> generateParenthesis(int n) {
        genParent("", n, n);

        printResult();
        return ret;
    }

    void genParent(string tmp, int lRemain, int rRemain) {
        // reject condition
        if (lRemain < 0 || rRemain < 0 || (lRemain > rRemain)) return;
        //accept condition
        if (lRemain == 0 && rRemain == 0) ret.push_back(tmp);

        genParent(tmp + '(', lRemain - 1, rRemain);

        genParent(tmp + ')', lRemain, rRemain - 1);
    }

    void printResult() {
        vector<string>::iterator it;

        for (it = ret.begin(); it != ret.end(); it++) {
            cout << *it << endl;
        }
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    sol1.generateParenthesis(3);

    return 0;
}

