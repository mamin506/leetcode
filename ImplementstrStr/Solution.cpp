#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() == 0) return -1;
        if (haystack.size() < needle.size()) return -1;
        int m = 0;
        int i = 0;
        vector<int> table;
        kmp_build_table(table, needle);
        while (m + i < haystack.size()) {
            if (needle[i] == haystack[m+i]) {
                if (i == needle.size() -1)
                    return m;
                i++;
            } else {
                if (table[i] > -1) {
                    m = m + i - table[i];
                    i = table[i];
                } else {
                    i = 0;
                    m++;
                }
            }
        }
        return -1;
    }

private:
    void kmp_build_table(vector<int>& table, string& str) {
        int pos = 2;
        int cnd = 0;
        table.push_back(-1);
        table.push_back(0);
        while (pos < str.size()) {
            if (str[pos-1] == str[cnd]) {
                cnd++;
                table.push_back(cnd);
                pos++;
            } else if (cnd > 0) {
                cnd = table[cnd];
            } else {
                table.push_back(0);
                pos++;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    return 0;
}
