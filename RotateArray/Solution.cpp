#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        vector<int> tmp;
        k = k % n;
        for (int i = 0; i < k; i++) {
            tmp.push_back(nums[n-i-1]);
        }
        for (int i = n-k; i > 0; i--) {
            nums[i+k-1] = nums[i-1];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = tmp.back();
            tmp.pop_back();
        }
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

