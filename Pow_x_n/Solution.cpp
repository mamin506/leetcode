#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int pow(double x, int n) {
            double tmp = 0;
            if (n == 0)
                return 1;
            tmp = pow(x, n/2);
            if (n % 2 ==0)
                return tmp * tmp;
            else {
                if (n > 0)
                    return x * tmp * tmp;
                else
                    return tmp * tmp / x;
            }
            return ret;
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    sol1.pow(50, 2);

    return 0;
}

