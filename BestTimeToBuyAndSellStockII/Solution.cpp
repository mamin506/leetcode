#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                ret += prices[i] - prices[i-1];
            }
        }
        return ret;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

