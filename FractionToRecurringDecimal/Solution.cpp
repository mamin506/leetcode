#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            if (denominator == 0) 
                return "";
            else if (numerator == 0)
                return "0";

            long long n = numerator, d = denominator;
            string num;
            if (n < 0) {
                n = abs(n);
                d *= -1;    // a tricky way to detect sign of n and d
            }
            if (d < 0) {
                d = abs(d);
                num.push_back('-');
            }
            num += to_string(n / d);
            n %= d;
            if (n == 0)
                return num;

            num.push_back('.');
            unordered_map<long long, size_t> hash_table;
            while (n != 0) {
                if (hash_table.find(n) == hash_table.end()) {
                    hash_table[n] = num.size();
                } else {
                    num.insert(hash_table[n], "(");
                    num.push_back(')');
                    break;
                }
                n *= 10;
                num += to_string(n / d);
                n %= d;
            }
            return num;

        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

