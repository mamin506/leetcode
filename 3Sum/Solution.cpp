#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        
        if (num.empty()) return ans;

        sort(num.begin(), num.end());
        
        int len = num.size();
        for (int i = 0; i < len; i++) {
            if (i > 0 && num[i] == num[i-1])
                continue;

            int target = -num[i];
            int left = i+1, right = len-1;
            while (left < right) {
                int sum = num[left] + num[right];
                if (right < len-1 && num[right] == num[right+1])
                    right--;
                else if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else {
                    //int t[] = {num[i], num[left], num[right]};
                    //ans.push_back(vector<int>(t, t+3));
                    vector<int> t = {num[i], num[left], num[right]};
                    ans.push_back(t);
                    left++;
                    right--;
                }
            }
        }

        return ans;
    }
    
    void print1DimVector(vector<int> &v) {
        vector<int>::iterator it;

        for (it = v.begin(); it != v.end(); it++) {
            cout << *it << ' ';
        }
        cout << endl;
    }

    void print2DimVector(vector<vector<int> > &v) {
        vector<vector<int> >::iterator it;

        for (it = v.begin(); it != v.end(); it++) {
            print1DimVector(*it);
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    //int tmp[] = {-1, 0, 1, 2, -1, -4};
    //vector<int> case1(tmp, tmp + sizeof(tmp)/sizeof(int));
    vector<int> case1 = {-1, 0, 1, 2, -1, -4};
    vector<int> case2 = {-1, 0, 0, 0, 0, 1, 2, -1, -4};
    vector<int> case3 = {-1, 1, 0, 0, 2, 1, 2, -1, -4};
    
    sol1.threeSum(case1);
    sol1.threeSum(case2);
    sol1.threeSum(case3);

    return 0;
}

