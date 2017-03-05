#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        vector<int> longest(s.length(), 0);
        int max=0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    longest[i] = (i-2)? longest[i-2] + 2 : 2;
                } else {
                    if (i - 1 - longest[i-1] >= 0 && s[i - 1 - longest[i-1]] == '(') {
                        longest[i] = longest[i-1] + 2 + (i - 2 - longest[i-1]? longest[i - 2 - longest[i-1]] : 0);
                    }
                }
            }
            if (longest[i] > max) {
                max = longest[i];
            }
        }

        return max;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    
    cout << sol1.longestValidParentheses("(())()") << endl;
    cout << sol1.longestValidParentheses("(()") << endl;

    return 0;
}

