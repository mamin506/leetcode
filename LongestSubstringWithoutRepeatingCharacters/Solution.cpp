#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        // solution 1
        int lengthOfLongestSubstring(string s) {
            if (s.length() == 0) return 0;
            if (s.length() == 1) return 1;
            int left = 0, right = 1;
            int ret = 1;

            int i;
            for (left = 0, right = 1; right < s.length(); ++right) {
                for (i = left; i < right; ++i) {
                    if (s[right] == s[i]) {
                        left = i+1;
                        break;
                    }
                }
                if (ret < right - left + 1) {
                    ret = right - left + 1;
                }
            }
            return ret;
        }

        // try map method
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

