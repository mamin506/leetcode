#inlcude "../mlibs.h"

using namespace std;

class Queue {
private:
    stack<int> s1;
    stack<int> s1_reversed;
public:
    void push(int x) {
        while (!s1.empty()) {
            s1_reversed.push(s1.top());
            s1.pop();
        }
        s1_reversed.push(x);
        while (!s1_reversed.empty()) {
            s1.push(s1_reversed.top());
            s1_reversed.pop();
        }
    }

    void pop(void) {
        s1.pop();
    }

    int peek(void) {
        return s1.top();
    }

    bool empty(void) {
        return s1.empty();
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

