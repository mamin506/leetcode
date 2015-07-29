#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int min = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                min = nums[i];
                break;
            }
        }

        return min;
    }
    
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

