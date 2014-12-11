#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int *results = new int[n];

        for (int i = 0; i < n; i++) {
            if (i == 0)
                results[i] = 1;
            else if (i == 1)
                results[i] = 2;
            else
                results[i] = results[i-1] + results[i-2];
        }

        return results[n-1];
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.climbStairs(1) << endl;
    cout << sol1.climbStairs(2) << endl;
    cout << sol1.climbStairs(3) << endl;
    cout << sol1.climbStairs(4) << endl;
    cout << sol1.climbStairs(5) << endl;
    cout << sol1.climbStairs(6) << endl;

    return 0;
}

