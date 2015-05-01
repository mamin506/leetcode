#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int lenS = S.length();
        int lenT = T.length();
        if (lenT = 0) return 1;
        if (lenT > lenS) return 0;
        if (lenT == lenS) return S==T? 1 : 0;

        vector<int> num(lenT+1, 0);
        num[0] = 1;
        for (int i = 0; i < lenS; i++) {
            for (int j = lenT; j > 0; j--) {
                if (S[i] == T[j-1])
                    num[j] += num[j-1];
            }
        }
        return num[lenT];
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

