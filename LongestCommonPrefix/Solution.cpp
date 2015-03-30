#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (!strs.size())
            return string();
        else if (strs.size() == 1)
            return strs[0];
        
        int prefixLen = strs[0].length();
        int i, j;
        for (i = 1; i < strs.size(); i++) {
            prefixLen = (prefixLen > strs[i].length())? strs[i].length() : prefixLen;
            for (j = 0; j < prefixLen; j++) {
                if (strs[0][j] != strs[i][j])
                    break;
            }
            if (j == 0)
                return string();

            prefixLen = j;
        }
        return strs[0].substr(0, prefixLen);
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    vector<string> case1;
    //vector<string> case2;
    //vector<string> case3;

    string str1 = "aaaabbbbcccc";
    string str2 = "aabbbbcc";
    string str3 = "aaaabccc";
    string str4 = "aaaabccc";
    string str5 = "a";
    
    case1.push_back(str1);
    case1.push_back(str2);

    cout << sol1.longestCommonPrefix(case1) << endl;

    return 0;
}

