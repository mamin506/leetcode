#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret;
        int i;
        for (i = 0; i < 32; i++) {
            ret = ret << 1;
            if (n % 2 == 1) {
                ret++;
            }
            n = n >> 1;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    uint32_t tmp;
    tmp = 43261596;

    cout << sol1.reverseBits(tmp) << endl;

    return 0;
}

