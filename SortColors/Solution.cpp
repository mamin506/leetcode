#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

#define _red   0
#define _white 1
#define _blue  2

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int red_count = 0;
        int white_count = 0;
        int blue_count = 0;

        for (int i = 0; i < n; i++) {
            switch (A[i]) {
            case _red : 
                red_count++;
                break;
            case _white : 
                white_count++;
                break;
            case _blue : 
                blue_count++;
                break;
            default :
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (red_count > 0) {
                A[i] = _red;
                red_count--;
            } else if (white_count > 0) {
                A[i] = _white;
                white_count--;
            } else if (blue_count > 0) {
                A[i] = _blue;
                blue_count--;
            }
        }
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

