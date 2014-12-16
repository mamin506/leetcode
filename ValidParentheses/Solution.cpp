#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for (string::iterator it=s.begin(); it != s.end(); it++) {
            if (*it == '(' || *it == '{' || *it == '[') {
                tmp.push(*it);
            } else {
                if (!tmp.empty()) {
                    if ((tmp.top() == '(' && *it == ')') || (tmp.top() == '{' && *it == '}') || (tmp.top() == '[' && *it == ']'))
                        tmp.pop();
                    else
                        return false;
                } else {
                    return false;
                }
            }
        }

        if (tmp.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    
    cout << sol1.isValid("{[()]}") << endl;
    cout << sol1.isValid("{[(]}") << endl;

    return 0;
}

