#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (auto& w: version1) if (w == '.') w = ' ';
        for (auto& w: version2) if (w == '.') w = ' ';

        istringstream s1(version1), s2(version2);

        while (true) {
            int v1, v2;
            if (!(s1 >> v1)) v1 = 0;
            if (!(s2 >> v2)) v2 = 0;

            if (!v1 && !v2) return 0;
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
        }

        return 1;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
   
    cout << sol1.compareVersion("12.34", "0.123") << endl;
    cout << endl;
    cout << sol1.compareVersion("0.1", "1.1") << endl;
    cout << endl;
    cout << sol1.compareVersion("1", "1.1") << endl;
    cout << endl;
    cout << sol1.compareVersion("1.1", "1.1") << endl;
    cout << endl;
    cout << sol1.compareVersion("1.20", "1.101") << endl;
    cout << endl;
    cout << sol1.compareVersion("1.1", "1.10") << endl;
    cout << endl;
    cout << sol1.compareVersion("1.10.1", "1.10") << endl;

    string tmp = "123 321 3 4 5 6 789";
    istringstream tmpstream(tmp);

    while ((tmpstream >> tmp)) {
        cout << tmp << endl;
    }

    return 0;
}

