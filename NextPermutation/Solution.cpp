#include "../mlibs.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first, second;
        int length = nums.size();

        for (first = length-1; first > 0; first--) {
            if (nums[first-1] < nums[first])
                break;
        }

        if (first != 0) {
            for (second = length-1; second > first; second--) {
                if (nums[second] > nums[first-1])
                    break;
            }
            swap(nums, first-1, second);
        }

        reverse(nums, first, length-1);

    }

    void swap(vector<int>& list, int index1, int index2) {
        int tmp;
        tmp = list[index1];
        list[index1] = list[index2];
        list[index2] = tmp;
    }

    void reverse(vector<int>& list, int left, int right) {
        for (; left < right; left++, right--)
            swap(list, left, right);
    }

};

int main(int argc, char *argv[]) {
    Solution sol1;

    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    sol1.nextPermutation(nums);

    cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;

    return 0;
}

