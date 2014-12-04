#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;

        return numTrees(n-1) * (4 * n - 2) / (n + 1);
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << sol1.numTrees(1) << endl;
    cout << sol1.numTrees(2) << endl;
    cout << sol1.numTrees(3) << endl;
    cout << sol1.numTrees(4) << endl;
    cout << sol1.numTrees(5) << endl;
    cout << sol1.numTrees(6) << endl;

    return 0;
}

