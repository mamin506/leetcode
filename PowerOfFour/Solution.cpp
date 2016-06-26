#inlcude "../mlibs.h"

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num && (-num & num) == num && (num & 0xAAAAAAAA) == 0;
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

