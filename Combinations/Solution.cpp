#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > ret;
            vector<int> tmp;
            combine(1, n, k, tmp, ret);
            return ret;
        }

        void combine(int left, int right, int k, vector<int> &tmp, vector<vector<int> > &ret) {
            if (right - left + 1 < k) return;
            if (k == 0) {
                printTmp(tmp);
                ret.push_back(tmp);
                return;
            }

            tmp.push_back(left);
            combine(left+1, right, k-1, tmp, ret);
            tmp.pop_back();
            combine(left+1, right, k, tmp, ret);
        }

        void printTmp(vector<int> &t) {
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

    sol1.combine(4, 2);
    sol1.combine(5, 3);

    return 0;
}

