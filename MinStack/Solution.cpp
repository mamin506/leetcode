#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
    public:
        void push(int x) {
            s.push(x);
            if (min.empty() || x <= min.top())
                min.push(x);
        }

        void pop() {
            if (!s.empty()) {
                if (min.top() == s.top())
                    min.pop();
                s.pop();
            }
        }

        int top() {
            return s.top();
        }

        int getMin() {
            return min.top();
        }

    private:
        stack<int> s;
        stack<int> min;
};

int main(int argc, char *argv[]) {
    MinStack sol1;
    sol1.push(10);
    sol1.push(2);
    cout << "min" << sol1.getMin() << endl;
    cout << "top" << sol1.top() << endl;
    sol1.pop();
    cout << "min" << sol1.getMin() << endl;
    cout << "top" << sol1.top() << endl;

    return 0;
}

