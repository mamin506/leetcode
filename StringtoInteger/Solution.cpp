#include <iostream>
#include <string>

using namespace std;

#define INT_MAX  2147483647
#define INT_MIN -2147483648

class Solution {
    public:
        int atoi(const char *str) {
            if (str == NULL || str[0] == '\0') return 0;
           
            int i = 0;
            while (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9')) {
                if (str[i] == ' ')
                    i++;
                else 
                    return 0;
            }

            int sign;
            if (str[i] == '-') {
                sign = -1;
                i++;
            } else if (str[i] == '+') {
                sign = 1;
                i++;
            } else {
                sign = 1;
            }
            
            int tmp = 0;
            int checkPoint = INT_MAX/10;
            for (i ; str[i] != '\0'; i++) {
                if (str[i] >= '0' && str[i] <= '9') {
                    if (tmp < checkPoint) {
                        tmp *= 10;
                        tmp += str[i] - '0';
                    } else if (tmp == checkPoint) {
                        if (str[i] < '8' && str[i] > '0') {
                            tmp *= 10;
                            tmp += str[i] - '0';
                        } else if (sign == 1) {
                            return INT_MAX;
                        } else
                            return INT_MIN;
                    } else {
                        if (sign == 1)
                            return INT_MAX;
                        else
                            return INT_MIN;
                    }
                } else 
                    break;
            }
            return sign * tmp;
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.atoi("00001212") << endl;
    cout << sol1.atoi("    -200") << endl;

    return 0;
}

