#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &num, int target) {
        map<int, int> hashTable;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.find(nums[i]) == hashTable.end()) {
                hashTable[target - nums[i]] = i;
            } else {
                ret.push_back(hashTable[nums[i]] + 1);
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
    
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

