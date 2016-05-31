#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string ret(s.rbegin(), s.rend());
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

