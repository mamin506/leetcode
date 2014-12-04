#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            long long l=10, r=10;

            if (x < 0) return false;

            while (l <= x) l *= 10;
            while (l > r) {
                if ((x % l) / (l/10) != (x % r) / (r/10))
                    return false;
                l /= 10;
                r *= 10;
            }

            return true;
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.isPalindrome(101) << endl;
    cout << sol1.isPalindrome(100) << endl;

    return 0;
}

