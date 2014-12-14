#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        //one line input don't need to convert
        if (nRows == 1) return s;

        string ret = "";
        
        int len = s.length();
        int t_dis = 2 * (nRows - 1);
        
        // first line
        for (int i = 0; i < len; i += t_dis) {
            ret += s[i];
        }

        // lines in the middle if have
        for (int l = 1; l < nRows-1; l++) {
            int next = 2*l;
            for (int i = l; i < len; i += next) {
                ret += s[i];
                next = t_dis - next;
            }
        }

        // last line
        for (int i = nRows-1; i < len; i += t_dis) {
            ret += s[i];
        }

        return ret;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << sol1.convert("PAYPALISHIRING", 3) << endl;
    cout << sol1.convert("I am who I am", 1) << endl;
    cout << sol1.convert("IiLaOmVmEiYnOmU", 2) << endl;
    cout << sol1.convert("ABCD", 4) << endl;

    return 0;
}

