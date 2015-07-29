#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int Zeroes = 0;
        while (n >= 5) {
            Zeroes += n/5;
            n = n/5;
        }
        return Zeroes;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

