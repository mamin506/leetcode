#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

#define _M 1000
#define _D 500
#define _C 100
#define _L 50
#define _X 10
#define _V 5
#define _I 1

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        int i;
        int last = _M;

        for (i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case 'M':
                ret = (last >= _M ? ret + _M : ret + _M - (last << 1));
                last = _M;
                break;
            case 'D':
                ret = (last >= _D ? ret + _D : ret + _D - (last << 1));
                last = _D;
                break;
            case 'C':
                ret = (last >= _C ? ret + _C : ret + _C - (last << 1));
                last = _C;
                break;
            case 'L':
                ret = (last >= _L ? ret + _L : ret + _L - (last << 1));
                last = _L;
                break;
            case 'X':
                ret = (last >= _X ? ret + _X : ret + _X - (last << 1));
                last = _X;
                break;
            case 'V':
                ret = (last >= _V ? ret + _V : ret + _V - (last << 1));
                last = _V;
                break;
            case 'I':
                ret = (last >= _I ? ret + _I : ret + _I - (last << 1));
                last = _I;
                break;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

