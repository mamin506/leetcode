#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        for (int i = 0; i <= rowIndex; i++) {
            ret.push_back(1);
            for (int j = i-1; j > 0; j--) {
               ret[j] = ret[j] + ret[j-1]; 
            }
        }
        return ret;
    }
    
    //vector<int> getRow(int rowIndex) {
    //    vector<int> ret;
    //    int tmp;
    //    for (int i = 0; i <= rowIndex; i++) {
    //        tmp = 1;
    //        for (int j = 0; j <= i; j++) {
    //            if (j == ret.size()) {
    //                ret.push_back(1);
    //            } else if (j > 0) {
    //                ret[j] = ret[j] + tmp;
    //                tmp = ret[j] - tmp;
    //            }
    //        }
    //    }
    //    return ret;
    //}

    void printResule(vector<int> ret) {
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << ' ';
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    sol1.printResule(sol1.getRow(1));
    sol1.printResule(sol1.getRow(2));
    sol1.printResule(sol1.getRow(3));
    sol1.printResule(sol1.getRow(4));
    sol1.printResule(sol1.getRow(5));
    sol1.printResule(sol1.getRow(7));

    return 0;
}

