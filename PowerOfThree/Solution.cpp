#inlcude "../mlibs.h"

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        // 1162261467 is 3^19, the bigest power of three in the range of integer(-2^31 ~ 2^31-1)
        return 1162261467%n == 0;
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

