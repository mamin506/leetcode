#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        // O(n^3)
        //string longestPalindrome(string s) {
        //    int n = s.length();
        //    if (s.length() == 0)
        //        return 0;
        //    int start, end;
        //    int max_index, max_lps = 0;
        //    string result;
        //    for (int i = 0; i < n; i++) {
        //        for (int j = 1; j < n - i; j++) {
        //            start =  i;
        //            end = i + j;
        //            while (start <= end && s[start] == s[end]) {
        //                start++;
        //                end--;
        //            }
        //            if (start >= end) {
        //                if (j + 1 > max_lps) {
        //                    max_index = i;
        //                    max_lps = j + 1;
        //                }
        //            }
        //        }
        //    }
        //    result = s.substr(max_index, max_lps);
        //    return result;
        //}

        // O(n^2)
        //string longestPalindrome(string s) {
        //    int len[1000][1000];
        //    string tmp;
        //    int max_index, max_lps = 0;
        //    int n = s.length();
        //
        //    for (int i = 0; i < n; i++)
        //        len[i][i] = 1;
        //
        //    for (int mSubStrLen = 2; mSubStrLen <= n; mSubStrLen++) {
        //        for (int i = 0; i < s.length() - mSubStrLen + 1; i++) {
        //            int j = i + mSubStrLen - 1;
        //            if (s[i] == s[j] && mSubStrLen == 2) {
        //                len[i][j] = 2;
        //                if (mSubStrLen > max_lps) {
        //                    max_index = i;
        //                    max_lps = mSubStrLen;
        //                }
        //            } else if (s[i] == s[j] && mSubStrLen == len[i+1][j-1] + 2) {
        //                len[i][j] = mSubStrLen;
        //                if (mSubStrLen > max_lps) {
        //                    max_index = i;
        //                    max_lps = mSubStrLen;
        //                }
        //            }
        //        }
        //    }
        //    tmp = s.substr(max_index, max_lps);
        //    return tmp;
        //}

        // O(n^2)
        //string longestPalindrome(string s) {
        //    int max_index, max_lps = 1;
        //    int n = s.length();
        //    
        //    for (int i = 0; i < n; i++) {
        //        int low = i - 1;
        //        int high = i;
        //        // s.length() is even
        //        while (low >= 0 && high < n && s[low] == s[high]) {
        //            if (high - low + 1 > max_lps) {
        //                max_index = low;
        //                max_lps = high - low + 1;
        //            }
        //            low--;
        //            high++;
        //        }
        //
        //        low = i - 1;
        //        high = i + 1;
        //        // s.length() is odd
        //        while (low >= 0 && high < n && s[low] == s[high]) {
        //            if (high - low + 1 > max_lps) {
        //                max_index = low;
        //                max_lps = high - low + 1;
        //            }
        //            low--;
        //            high++;
        //        }
        //    }
        //    return s.substr(max_index, max_lps);
        //}

        // O(n)
        string longestPalindrome(string s) {
            string T = addBoundaries(s, '#');
            int n = T.length();
            int *p = new int[n];
            int c = 0, r = 0;
            for (int i = 1; i < n; i++) {
                int i_mirror = 2*c - i;
                if (r > i) {
                    p[i] = (p[i_mirror] > r - i)? r - i : p[i_mirror];
                }
                else {
                    p[i] = 0;
                }

                int left, right;
                while (T[i - 1 - p[i]] == T[i + 1 + p[i]]) p[i]++;

                if (i + p[i] > r) {
                    r = i + p[i];
                    c = i;
                }
            }
            int max = 0;
            for (int i = 1; i < n; i++) {
                if (p[i] > max) {
                    max = p[i];
                    c = i;
                }
            }
            return removeBoundaries(T.substr(c - max, 2*max + 1));
        }

        string addBoundaries(string cs, char inst) {
            if (cs.length() == 0)
                return "^$";

            // add "^" and "$" in the begin and end to avoid array boundary check
            string cs2 = "^";
            for (int i = 0; i < cs.length(); i++) {
                cs2 = cs2 + inst + cs[i];
            }
            cs2 += inst;
            return cs2 + "$";
        }
        
        string removeBoundaries(string cs) {
            if (cs.length() == 0)
                return "";

            string cs2 = "";
            for (int i = 1; i < cs.length(); i += 2) {
                cs2 += cs[i];
            }
            return cs2;
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.longestPalindrome("abcdcba") << endl;
    cout << sol1.longestPalindrome("daddssadsdsdfs") << endl;
    cout << sol1.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
    cout << sol1.longestPalindrome("dfasdfasdfasdfasdfffdssasfasdfffffffdssss") << endl;
    cout << sol1.longestPalindrome("xaxaxaxaxaxa") << endl;
    cout << sol1.longestPalindrome("test1tset") << endl;
    cout << sol1.longestPalindrome("abac") << endl;

    return 0;
}

