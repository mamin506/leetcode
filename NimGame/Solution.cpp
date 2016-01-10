#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>

#define MAGIC 4

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        int check_point = n % MAGIC;
        if (check_point == 0) {
            return false;
        } else {
            return true;
        }
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

