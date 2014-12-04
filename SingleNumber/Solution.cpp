#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int singleNumber(int[] A) {
            int ret = 0;
            for (int i = 0; i < A.length; i++) {
                ret = ret ^ A[i];
            }
            return ret;
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    int case1[7] = {10, 20, 10, 45, 67, 45, 57};
    sol1.singleNumber(case1);

    return 0;
}

