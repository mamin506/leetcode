#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                nums.insert(nums.begin() + i, target);
                break;
            }
        }
        return i;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    int case1[] = {1, 3, 5, 6};
    vector<int> vect(case1, case1 + sizeof(case1) / sizeof(int));

    cout << sol1.searchInsert(vect, 5) << endl;

    return 0;
}

