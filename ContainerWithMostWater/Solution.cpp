#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;

        int left = 0, right = height.size()-1;
        int lower;
        int max = 0;

        while (left < right) {
            lower = (height[left] < height[right])? height[left] : height[right];
            max = (max > lower * (right - left))? max : lower * (right - left)
            while(height[left] <= lower && left < right) ++left;
            while(height[right] <= lower && left < right) ++right;
        }

        return max;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

