#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string keepAlphaNum (string s) {
            string tmp = "";
            for (int i = 0; i < s.length(); i++) {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                    tmp += s[i];
            }
            return tmp;
        }

        string toLowerCase(string s) {
            string tmp = "";
            for (int i = 0; i < s.length(); i++) {
                if (s[i] >= 'A' && s[i] <= 'Z')
                    tmp += s[i] - 'A' + 'a';
                else
                    tmp += s[i];
            }

            return tmp;
        }

        bool longestPalindrome(string s) {
            string T = keepAlphaNum(s);
            T = toLowerCase(T);
            int low = 0;
            int high = T.length() - 1;
            
            while (T[low] == T[high]) {
                low++;
                high--;
            }
        
            if (low < high)
                return false;

            return true;
        }

};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.longestPalindrome("abcdcba") << endl;
    cout << sol1.longestPalindrome("daddssadsdsdfs") << endl;
    cout << sol1.longestPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol1.longestPalindrome("a.") << endl;
    cout << sol1.longestPalindrome("dfasdfasdfasdfasdfffdssasfasdfffffffdssss") << endl;
    cout << sol1.longestPalindrome("xaxaxaxaxaxa") << endl;
    cout << sol1.longestPalindrome("test1tset") << endl;
    cout << sol1.longestPalindrome("abac") << endl;

    return 0;
}

