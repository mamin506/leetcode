#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // use set
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int i = 0;
        for (auto item : nums) {
            if (map.find(item) != map.end()) {
                if (i - map[item] <= k) return true;
                map[item] = i;
            } else {
                map[item] = i;
            }
            i++;
        }
        return false;
    }
    
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    return 0;
}

