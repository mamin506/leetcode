#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = nums.size()/2;
        return nums[index]; 
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    
    return 0;
}

