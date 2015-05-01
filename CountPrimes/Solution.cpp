#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int n_sqrt = sqrt(n);
        //int *A = new int[n-2];
        bool *A = new bool[n-2];

        for (int i = 2; i <= n_sqrt; i++) {
            if (A[i-2] == 0) {
                for (int j = i*i; j <=n; j+=i) {
                    A[j-2] = 1;
                }
            }
        }

        int cnt = 1;
        for (int i = 1; i < n-2; i += 2) {
            if (A[i] == 0) {
                cout << i+2 << " is prime number" << endl;
                cnt++;
            }
        }

        free(A);
        cout << "cnt " << cnt << endl;
        return cnt;
        
        //
        // if (n <= 2) return 0;
        // double c = sqrt(n);
        // bool *bv = new bool[n];
        // for(int i = 3; i <= c; i += 2)
        //     if (!bv[i]) 
        //         for(int j = i*i, k = i << 1; j < n; j += k)
        //             bv[j] = 1;
        // int num = 1;
        // for(int i = 3; i < n; i += 2)
        //     if(!bv[i]) num++;
        // return num;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    sol1.countPrimes(12);

    return 0;
}

