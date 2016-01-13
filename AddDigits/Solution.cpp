#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int ret = 0;

        while (num > 0) {
            ret += num % 10;
            num /= 10;
        }
        
        if (ret < 10) {
            return ret;
        } else {
            return addDigits(ret);
        }
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

