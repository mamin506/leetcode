#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        const array<string, 10> encoding {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string ans;
        vector<string> result;

        letterCombinations(digits, result, ans, encoding);

        return result;
    }

    void letterCombinations(string digits, vector<string>& result, string ans, const array<string, 10>& encoding) {
        if (ans.length() == digits.length()) {
            result.push_back(ans);
            return;
        }
        for (const char& ch : encoding[digits[ans.size()] - '0']) {
            ans.push_back(ch);
            letterCombinations(digits, result, ans, encoding);
            ans.pop_back();
        }
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    sol1.letterCombinations(string("2"));

    return 0;
}

