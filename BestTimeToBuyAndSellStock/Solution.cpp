#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    //int maxProfit(vector<int> &prices) {
    //    if (prices.size() == 0) {
    //        return 0;
    //    }
    //    int ret = 0, past = 0;
    //    for (int i = 1; i < prices.size(); i++) {
    //        ret += prices[i] - prices[i-1];
    //        // update the loest price
    //        if (ret < 0) ret = 0;
    //        // update the max profit
    //        if (ret > past) past = ret;
    //    }
    //    return past;
    //}

    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int profit = 0;
        int beginMin = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - beginMin > profit)
                profit = prices[i] - beginMin;

            if (prices[i] < beginMin)
                beginMin = prices[i];
        }
        return profit;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

