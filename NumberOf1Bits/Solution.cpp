#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        uint32_t tmp = n;
        for (int i = 1; i <= 32; i++) {
            if (tmp % 2 == 1) {
                ret++;
            }
            tmp = n >> i;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << sol1.hammingWeight(11) << endl;
    cout << sol1.hammingWeight(32) << endl;
    cout << sol1.hammingWeight(65535) << endl;
    cout << sol1.hammingWeight(0xFFFFFFFF) << endl;

    return 0;
}

