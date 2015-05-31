#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        auto ita = a.rbegin();
        auto itb = b.rbegin();
        unsigned char carry = 0;

        while (ita != a.rend() || itb != b.rend() || carry) {
            carry = carry + ((ita == a.rend())? 0 : *(ita++) - '0') + ((itb == b.rend())? 0 : *(itb++) - '0');
            ret = char(carry%2 + '0') + ret;
            carry /= 2;
        }

        return ret;
    }

};

int main(int argc, char *argv[]) {
    Solution sol1;

    sol1.addBinary("111", "1");

    return 0;
}

