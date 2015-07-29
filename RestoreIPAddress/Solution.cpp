#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddress(string s) {
        vector<string> ret;

        if (s.length() > 12 || s.length() < 4) {
            return ret;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < i + 4; j++) {
                for (int k = j + 1; k < j + 4; k++) {
                    checkIpAddress(i, j, k, s, ret);
                }
            }
        }
        
        printResult(ret);
        return ret;
    }

    void checkIpAddress(int p1, int p2, int p3, string s, vector<string> &ret) {
        // length check
        if (p3 >= s.length()-1 || s.length() - 4 > p3) return;

        // insert dots
        s.insert(p1+1, ".");
        s.insert(p2+2, ".");
        s.insert(p3+3, ".");

        cout << s << endl;

        if ( isValidField(s.substr(0, p1+1)) ||
             isValidField(s.substr(p1+2, p2-p1)) ||
             isValidField(s.substr(p2+3, p3-p2)) ||
             isValidField(s.substr(p3+4)) ) {
            return;
        }

        ret.push_back(s);
    }

    bool isValidField(string s) {
        if ((s[0] == '0' && s.length() != 1) || stoi(s) > 255)
            return true;

        return false;
    }

    void printResult(vector<string> &ret) {
        for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++) {
            cout << *it << endl;
        }
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    sol1.restoreIpAddress("12123");

    return 0;
}

