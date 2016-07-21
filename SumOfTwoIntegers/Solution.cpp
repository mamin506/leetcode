#inlcude "../mlibs.h"

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;

        while (b != 0) {
            sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }
        return sum;
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

