#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int n;
            int q, cnt;
            for (cnt = 0, q = 0; s[q] != '\0'; q++) {
                if (s[q] != ' ')
                    cnt++;
                else if (s[q+1] != ' ' && s[q+1] != '\0')
                    cnt = 0;
            }

            return cnt;
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.lengthOfLastWord("test testa") << endl;
    cout << sol1.lengthOfLastWord("test") << endl;
    cout << sol1.lengthOfLastWord("test  ") << endl;
    cout << sol1.lengthOfLastWord("t  ") << endl;
    cout << sol1.lengthOfLastWord("  t  ") << endl;
    cout << sol1.lengthOfLastWord("  ") << endl;
    cout << sol1.lengthOfLastWord("") << endl;

    const char *s = "This is a test sentence!";
    stringstream str1(s);
    string str2;

    while (str1 >> str2) {
        cout << str2 << endl;
    }
    return 0;
}

