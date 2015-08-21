#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string> RPNtoken;
        RPNtoken = buildRPN(s);
        return evalRPN(RPNtoken)
    }

    // Reverse Polish Notation
    vector<string> buildRPN(string &infix_str) {
        stack<char> ops;
        vector<string> token;
        string nums;

        token.push_back("0");
        token.push_back("0");
        ops.push('+');

        for (auto c : infix_str) {
            if (isdigit(c)) {
                nums += c;
            } else {
                token.push_back(nums);
                nums = "";
                if (c == '+' || c == '-') {
                    if (ops.top() == '+' || ops.top() == '-') {
                        token.push_back(ops.top());
                        ops.pop;
                    }
                    ops.push(c);
                } else if (c == '(') {
                    ops.push(c);
                } else if (c == ')') {
                    while (ops.top() != '(') {
                        token.push_back(ops.top());
                        ops.pop();
                    }
                    ops.pop();
                }
            }
        }

        return token;
    }

    int evalRPN(vector<string> token) {
        stack<int> nums;
        int len = tokens.size();
        for (int i = 0; i < len; i ++) {             
            string x = tokens[i];             
            if ((x == "+") || (x == "-") || (x == "*") || (x == "/")) {                 
                // pop two numbers off the stack                 
                int a = nums.top();                 
                nums.pop();                 
                int b = nums.top();                 
                nums.pop();                 
                // evaluate and push the result back                 
                switch (x[0]) {                     
                    case '+': nums.push(a + b); break;                     
                    case '-': nums.push(b - a); break;                     
                    case '*': nums.push(b * a); break;                     
                    case '/': nums.push(b / a); break;                 
                }             
            } else { // push a number into the stack                 
                int n;                 
                istringstream(x) >> n;
                nums.push(n);
            }
        }
        if (nums.size()) {
            int xx = nums.top();
            while (nums.size()) {
                nums.pop();
            }
            return xx;
        }
        return 0; // error occurs
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    string case1 = "1+1";

    sol1.calculate(case1);

    return 0;
}

