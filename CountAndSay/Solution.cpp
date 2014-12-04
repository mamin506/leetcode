#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string prev = "1";

        for (int i = 2; i <= n; i++) {
            char curChar = prev[0];
            int times = 1;
            string tmpstr;
            prev.push_back('#');
            for (int j = 1; j < prev.length(); j++) {
                if (prev[j] == curChar)
                    times++;
                else {
                    tmpstr += to_string(times);
                    tmpstr.push_back(curChar);
                    curChar = prev[j];
                    times = 1;
                }
            }
            prev = tmpstr;
        }
        return prev;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.countAndSay(0) << endl;
    cout << sol1.countAndSay(1) << endl;
    cout << sol1.countAndSay(2) << endl;
    cout << sol1.countAndSay(3) << endl;
    cout << sol1.countAndSay(4) << endl;
    cout << sol1.countAndSay(5) << endl;
    cout << sol1.countAndSay(6) << endl;
    cout << sol1.countAndSay(7) << endl;

    return 0;
}

