#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        unordered_map<string, vector<int>> ht;

        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            ht[key].push_back(i);
        }

        for (unordered_map<string, vector<int>>::iterator it = ht.begin(); it != ht.end(); it++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++) {
                    ret.push_back(strs[it->second[i]]);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;

    return 0;
}

