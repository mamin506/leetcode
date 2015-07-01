#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        vector<int>::reverse_iterator it = nums.rbegin();
        int result = 0;
        int last = nums.size()-1;
        while (it != nums.rend() && *it == val) {
            last--;
            it++;
        }

        while (it != nums.rend()) {
            if (*it != val) {
                result++;
            } else {
                *it = nums[last];
                last--;
            }
            it++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

