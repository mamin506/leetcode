#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 1) return A[0];
        
        int max = A[0];
        int tmp;
        for (int i = 1; i < n; i++) {
            tmp = A[i-1]*A[i];
            if (max <= tmp) {
                max = tmp;
            }
        }

        return max;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    
    int case1[4] = {2, 3, -2, 4};
    int case2[4] = {2, -3, 2, 4};

    cout << sol1.maxProduct(case1, 4) << endl;
    cout << sol1.maxProduct(case2, 4) << endl;

    return 0;
}

