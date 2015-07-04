#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int> tmp;
        int sum = 0;
        int index = 0;

        sort(candidates.begin(), candidates.end());
        vector<vector<int> >::iterator it;
        //it = unique(candidates.begin(), candidates.end());
        //candidates.resize(distance(candidates.begin(), it));
        //printVec(candidates);

        combinationSum2(candidates, ret, tmp, index, sum, target);

        return ret;
    }

    void combinationSum2(vector<int> &candidates, vector<vector<int> > &ret, vector<int> &tmp, int index, int sum, int target) {
        if (sum > target) return;
        if (sum == target) {
            printVec(tmp);
            ret.push_back(tmp);
            return;
        }
            
        while (candidates.size() > index) {
            sum += candidates[index];
            tmp.push_back(candidates[index]);

            combinationSum2(candidates, ret, tmp, index+1, sum, target);

            sum -= candidates[index];
            tmp.pop_back();
            do {
                index++;
            } while (candidates[index] == candidates[index-1]);
        }
    }

    void printVec(vector<int> &t) {
        for (int i =0; i < t.size(); i++) {
            cout << t[i];
            if (i == t.size() - 1)
                cout << endl;
            else
                cout << ' ';
        }
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    int case1[] = {10, 1, 2, 7, 6, 1, 5};
    int case2[] = {8, 7, 4, 3};
    int case3[] = {7, 7, 3, 4, 3, 4, 2, 2};
    vector<int> test1(case1, case1 + sizeof(case1)/sizeof(int));
    vector<int> test2(case2, case2 + sizeof(case2)/sizeof(int));
    vector<int> test3(case3, case3 + sizeof(case3)/sizeof(int));

    sol1.combinationSum2(test1, 8);
    //sol1.combinationSum2(test2, 11);
    //sol1.combinationSum2(test3, 10);

    return 0;
}

