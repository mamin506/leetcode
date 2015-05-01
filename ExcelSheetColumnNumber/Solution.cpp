#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();

        if (len == 0) return 0;

        int ret = 0;

        for (int i = 0; i < len; i++) {
            ret = ret * 26 + (s[i] - 'A' + 1);
        }
        
        return ret;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << sol1.titleToNumber("A") << endl;
    cout << sol1.titleToNumber("C") << endl;
    cout << sol1.titleToNumber("AB") << endl;
    cout << sol1.titleToNumber("AC") << endl;

    return 0;
}

