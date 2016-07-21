#inlcude "../mlibs.h"

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        int tmp = num;
        if (tmp <= 0) return false;
        while (tmp > 1) {
            if (tmp % 2 == 0) {
                tmp /= 2;
            }
            if (tmp % 3 == 0) {
                tmp /= 3;
            }
            if (tmp % 5 == 0) {
                tmp /= 5;
            }
            if (tmp % 2 != 0 && tmp % 3 != 0 && tmp % 5 != 0) {
                break;
            }
        }
        return  tmp == 1;
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

