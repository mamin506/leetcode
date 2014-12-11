#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.empty()) return target;

        sort(num.begin(), num.end());
        
        int len = num.size();
        int closet = num[0] + num[1] + num[2];
        for (int i = 0; i < len; i++) {
            if (i > 0 && num[i] == num[i-1])
                continue;

            int left = i+1, right = len-1;
            while (left < right) {
                int sum = num[i] + num[left] + num[right];
                int diff = abs(sum - target);

                if (right < len-1 && num[right] == num[right+1])
                    right--;
                else if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else {
                    return sum;
                }

                closet = abs(closet - target) > diff ? sum : closet;
            }
        }

        return closet;
    }
    
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    //int tmp[] = {-1, 0, 1, 2, -1, -4};
    //vector<int> case1(tmp, tmp + sizeof(tmp)/sizeof(int));
    vector<int> case1 = {-1, 1, 2, -4};
    vector<int> case2 = {-1, 0, 0, 0, 0, 1, 2, -1, -4};
    vector<int> case3 = {-1, 1, 0, 0, 2, 1, 2, -1, -4};
    vector<int> case4 = {-1, 2, 1, -4};
    
    cout << sol1.threeSumClosest(case1, 0) << endl;
    cout << sol1.threeSumClosest(case1, 1) << endl;
    cout << sol1.threeSumClosest(case1, 2) << endl;
    cout << sol1.threeSumClosest(case2, 0) << endl;
    cout << sol1.threeSumClosest(case2, 1) << endl;
    cout << sol1.threeSumClosest(case2, 2) << endl;
    cout << sol1.threeSumClosest(case3, 0) << endl;
    cout << sol1.threeSumClosest(case3, 1) << endl;
    cout << sol1.threeSumClosest(case3, 2) << endl;
    cout << sol1.threeSumClosest(case4, 1) << endl;

    return 0;
}

