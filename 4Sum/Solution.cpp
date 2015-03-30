#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        if (num.empty() || num.size() < 4) return ans;

        sort(num.begin(), num.end());

        int len = num.size();
        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;

            for(int e = len - 1; e >= i + 3; e--) {
                if (e < len - 1 && num[e] == num[e + 1]) continue;

                int j = i + 1;
                int k = e - 1;
                while (j < k) {
                    if (k < e - 1 && num[k] == num[k+1])
                        k--;
                    else if (num[i] + num[e] + num[j] + num[k] > target)
                        k--;
                    else if (num[i] + num[e] + num[j] + num[k] < target)
                        j++;
                    else {
                        vector<int> t = {num[i], num[j], num[k], num[e]};
                        ans.push_back(t);
                        j++;
                        k--;
                    }
                }
            }
        }

        print2DimVector(ans);
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
    vector<int> case4 = {-1, 2, 1, -4};
    
    sol1.fourSum(case1, 0);

    return 0;
}
