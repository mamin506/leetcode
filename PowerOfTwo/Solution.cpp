#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1 || n == 2) return true;

        if (n%2 == 1 || n == 0) return false;

        return isPowerOfTwo(n/2);
    }
        
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

