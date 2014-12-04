#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int>::reverse_iterator it;
        int carry = 1;

        for (it = digits.rbegin(); it != digits.rend(); it++) {
            *it = *it + carry;
            if (*it > 9) {
                carry = 1;
                *it = *it - 10;
            } else {
                carry = 0;
                break;
            }
        }

        if (carry == 1)
            digits.insert(digits.begin(), 1);

        return digits;
    }

    void printResult(vector<int> digits) {
        vector<int>::iterator it;

        for (it = digits.begin(); it != digits.end(); it++) {
            cout << *it;
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    vector<int> num1 (4, 9);
    sol1.printResult(num1);
    sol1.printResult(sol1.plusOne(num1));

    return 0;
}

