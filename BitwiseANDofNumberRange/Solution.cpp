#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // TLE
    //int rangeBitwiseAnd(int m, int n) {
    //    if (n < m) return 0;

    //    int ret = m;
    //    for (int i = m + 1; i <=n; i++) {
    //        ret &= i;
    //    }

    //    return ret;
    //}

    int rangeBitwiseAnd(int m, int n) {
        int offset = 0;
        while (m != 0 && n != 0) {
            if (m == n) {
                return m << offset;
            }

            m = m >> 1;
            n = n >> 1;
            offset++;
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << sol1.rangeBitwiseAnd(5, 7) << endl;

    return 0;
}

