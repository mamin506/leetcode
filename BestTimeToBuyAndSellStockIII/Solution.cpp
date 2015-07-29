#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;

        int *profit1 = new int[prices.size()]();
        int *profit2 = new int[prices.size()]();

        int curMin = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (profit1[i-1] < prices[i] - curMin)
                profit1[i] = prices[i] - curMin;
            else
                profit1[i] = profit1[i-1];

            if (curMin > prices[i])
                curMin = prices[i];
        }

        int curMax = prices.back();
        for (int i = prices.size()-2; i >= 0; i--) {
            if (profit2[i+1] < curMax - prices[i])
                profit2[i] = curMax - prices[i];
            else
                profit2[i] = profit2[i+1];

            if (curMax < prices[i])
                curMax = prices[i];
        }

        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (profit1[i] + profit2[i] > ret)
                ret = profit1[i] + profit2[i];
        }
        return ret;

    }

    //int maxProfit(vector<int> &prices) {
    //    int len = prices.size();
    //    if(len < 2) return 0;
    //    int ret = 0;
    //    for(int i = 0; i < 2; ++i){
    //        int profit = 0, minval = prices[0], minpos = 0, maxpos = 0, minposnow = 0;
    //        for(int j = 0; j < len; ++j){
    //            if(prices[j] == -1 && j < len-1){
    //                minposnow = j+1;
    //                minval = prices[j+1];
    //            }else if(prices[j] < minval){
    //                minval = prices[j];
    //                minposnow = j;
    //            }else if(prices[j] - minval > profit){
    //                profit = prices[j] - minval;
    //                minpos = minposnow;
    //                maxpos = j;
    //            }
    //        }
    //        if(profit == 0) return ret;
    //        ret += profit;
    //        prices[minpos] = prices[maxpos] = -1;
    //        reverse(prices.begin() + minpos, prices.begin() + (++maxpos));
    //    }
    //    return ret;
    //}

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

