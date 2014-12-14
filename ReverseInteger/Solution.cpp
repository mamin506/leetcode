#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while(x) {
            ret = ret * 10 + x % 10;
            x = x / 10;
        }

        return (ret > INT_MAX || ret < INT_MIN)? 0 : ret;
    }
    
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    cout << -20/10 << endl;
    cout << -23%10 << endl;

    cout << sol1.reverse(123) << endl;
    cout << sol1.reverse(-123) << endl;
    cout << sol1.reverse(-300) << endl;
    cout << sol1.reverse(111116666) << endl;
    cout << sol1.reverse(1111166666) << endl;

    return 0;
}

