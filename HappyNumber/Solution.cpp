#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int num = 0;
        int tmp = 0;
        if (n == 1) return true;

        while (n > 0) {
            tmp = n %10;
            num += tmp * tmp;
            n /= 10;
        }
        if (num > 9) {
            return isHappy(num);
        }

        return (num == 1);
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    //if (sol1.isHappy(10)) {
    //    cout << "is happy number" << endl;
    //}

    return 0;
}

