#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> hashTable;
        vector<int> ret;
        // initial table
        for (int i = 0; i < nums1.size(); i++) {
            if (hashTable.find(nums1[i]) == hashTable.end()) {
                hashTable[nums1[i]] = false;
            } 
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (hashTable.find(nums2[i]) != hashTable.end()) {
                if (hashTable[nums2[i]] == false) {
                    hashTable[nums2[i]] = true;
                    ret.push_back(nums2[i]);
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

