#inlcude "../mlibs.h"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        int hashMapS[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            hashMapS[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            if (hashMapS[t[i]] == 0) {
                return false;
            } else {
                hashMapS[t[i]]--;
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

