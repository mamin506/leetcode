#inlcude "../mlibs.h"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char hashMapS[256] = {0}, hashMapT[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            if (hashMapS[s[i]] == 0) {
                hashMapS[s[i]] = t[i];
            } else if (hashMapS[s[i]] != t[i]) {
                return false;
            }

            if (hashMapT[t[i]] == 0) {
                hashMapT[t[i]] = s[i];
            } else if (hashMapT[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    if (sol1.isIsomorphic("egg", "goo")) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}

