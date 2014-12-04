#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> > ret;
            vector<int> tmp;
            for (int i = 0; i < numRows; i++) {
                tmp.clear();
                for(int j = 0; j <= i; j++) {
                    if (j == 0 || j == i)
                        tmp.push_back(1);
                    else
                        tmp.push_back(ret[i-1][j] + ret[i-1][j-1]);
                }
                ret.push_back(tmp);
            }
            return ret;
        }

        void printResule(vector<vector<int> > ret) {
            for (int i = 0; i < ret.size(); i++) {
                for (int j = 0; j < ret[i].size(); j++) {
                    cout << ret[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    sol1.printResule(sol1.generate(1));
    sol1.printResule(sol1.generate(5));
    sol1.printResule(sol1.generate(7));
    sol1.printResule(sol1.generate(2));

    return 0;
}

