#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isNumber(string s) {
            enum InputType {
                INVALID,        //Alphas, '(', ')', '&' and so on
                SPACE,
                SIGN,
                DIGIT,
                DOT,
                EXPONENT
            };

            int transtable[][6] = {
               //INV SPA SIG DIG DOT EXP
                {-1,  0,  3,  1,  2, -1}, // state 0 : init or space in head
                {-1,  8, -1,  1,  4,  5}, // state 1 : digit
                {-1, -1, -1,  4, -1, -1}, // state 2 : dot in the head
                {-1, -1, -1,  1,  2, -1}, // state 3 : sign
                {-1,  8, -1,  4, -1,  5}, // state 4 : number then dot
                {-1, -1,  6,  7, -1, -1}, // state 5 : 'e' or 'E'
                {-1, -1, -1,  7, -1, -1}, // state 6 : e then sign
                {-1,  8, -1,  7, -1, -1}, // state 7 : e then digit
                {-1,  8, -1, -1, -1, -1}, // state 8 : valid input then space
            };

            int state = 0;
            int i = 0;
            InputType  inType = INVALID;
            while (i < s.length()) {
                inType = INVALID;
                if (s[i] == ' ') inType = SPACE;
                else if (s[i] == '+' || s[i] == '-') inType = SIGN;
                else if (isdigit(s[i])) inType = DIGIT;
                else if (s[i] == '.') inType = DOT;
                else if (s[i] == 'e' || s[i] == 'E') inType = EXPONENT;
                state = transtable[state][inType];
                if (state == -1) return false;
                i++;
            }
            return state == 1 | state == 4 | state == 7 || state == 8;

        }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

