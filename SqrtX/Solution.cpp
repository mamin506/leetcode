#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    double sqrt(int x) {
        double ret = 2;
        double delta = 0.0001;

        while (fabs(pow(ret, 2) - x) > delta) {
            ret = (ret + x / ret) / 2;
        }

        return ret;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << sol1.sqrt(3) << endl;
    cout << sol1.sqrt(4) << endl;
    cout << sol1.sqrt(8) << endl;
    cout << sol1.sqrt(9) << endl;

    return 0;
}

