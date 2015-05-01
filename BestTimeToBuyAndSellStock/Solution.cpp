#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int ret = 0, past = 0;
        for (int i = 1; i < prices.size(); i++) {
            ret += prices[i] - prices[i-1];
            if (ret < 0) ret = 0;
            if (ret > past) past = ret;
        }
        return past;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

