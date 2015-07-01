#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //int removeDuplicates(vector<int>& nums) {
    //    if (nums.size() == 0 || nums.size() == 1) return nums.size();
    //    vector<int>::iterator it = nums.begin();
    //    int pre = *it++;
    //    
    //    while (it != nums.end()) {
    //        if (pre == *it) {
    //            nums.erase(it);
    //        } else {
    //            pre = *it++;
    //        }
    //    }
    //    return nums.size();
    //}

    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return nums.size();

        vector<int>::iterator it = nums.begin();
        int pre = *it++;
        
        int result = 1;
        while (it != nums.end()) {
            if (pre != *it) {
                pre = *it;
                nums[result] = pre;
                result++;
            }
            it++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    vector<int> case1;
    case1.push_back(1);
    case1.push_back(1);
    case1.push_back(1);
    case1.push_back(2);
    case1.push_back(3);

    cout << sol1.removeDuplicates(case1) << endl;

    return 0;
}

