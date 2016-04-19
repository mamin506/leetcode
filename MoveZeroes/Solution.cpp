#include <iostream>
#include <string>
#include <vector>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // neat solution
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) swap(nums[j++], nums[i]);
        }
    }

    //void moveZeroes(vector<int>& nums) {
    //    int i, j;
    //    for (i = 0; i < nums.size(); i++) {
    //        if (nums[i] == 0) {
    //            for (j = i + 1; j < nums.size(); j++) {
    //                if (nums[j] != 0) {
    //                    nums[i] = nums[j];
    //                    nums[j] = 0;
    //                    i++;
    //                }
    //            }
    //            return;
    //        }
    //    }
    //}
};


int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

