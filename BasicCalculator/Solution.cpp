#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string> RPNtokens;
        RPNtokens = buildRPN(s);

        return evalRPN(RPNtokens);
    }

    void printVector(vector<string> v) {
        for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
            cout << *it << endl;
        }
        cout << endl;
    }

    // Build Reverse Polish Notation(Shunting-yard algorithm)
    vector<string> buildRPN(string &infix_str) {
        stack<string> ops;
        vector<string> tokens;
        string nums;
        int len = infix_str.length();

        for (int i = 0; i < len; i++) {
            if (infix_str[i] == '+' || infix_str[i] == '-') {
                if (!ops.empty() && ops.top() != "(") {
                    tokens.push_back(ops.top());
                    ops.pop();
                }
                ops.push(infix_str.substr(i,1));
            } else if (infix_str[i] == '(') {
                ops.push(infix_str.substr(i,1));
            } else if (infix_str[i] == ')') {
                //while (ops.top().compare("(") != 0) {
                while (ops.top() != "(") {
                    tokens.push_back(ops.top());
                    ops.pop();
                }
                ops.pop();
            } else if (infix_str[i] == ' ') {
                continue;
            } else {
                nums = infix_str.substr(i, 1);
                while (infix_str[i+1] >= '0' && infix_str[i+1] <= '9') {
                    ++i;
                    nums = nums + infix_str[i];
                }
                tokens.push_back(nums);
            }
        }

        while (!ops.empty()) {
            tokens.push_back(ops.top());
            ops.pop();
        }

        return tokens;
    }

    // eval RPN 
    int evalRPN(vector<string> tokens) {
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

    string case1 = "1+3";
    string case2 = "10+23";
    string case3 = "1+(2+2)";
    string case4 = "1+2-3";
    
    int tmp = sol1.calculate(case1);
    cout << "The case1 result is : " << tmp << endl;
    tmp = sol1.calculate(case2);
    cout << "The case2 result is : " << tmp << endl;
    tmp = sol1.calculate(case3);
    cout << "The case3 result is : " << tmp << endl;
    tmp = sol1.calculate(case4);
    cout << "The case4 result is : " << tmp << endl;

    return 0;
}

