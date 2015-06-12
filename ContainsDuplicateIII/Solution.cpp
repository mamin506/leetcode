#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i - l > k) {
                window.erase(nums[l++]);
            }
            auto it = window.lower_bound((long)nums[i] - (long)t);
            // if use int num[i] + t could overflow
            if (it != window.end() && *it < (long)nums[i] + (long)t) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
    
};

int main(int argc, char *argv[]) {
    return 0;
}

