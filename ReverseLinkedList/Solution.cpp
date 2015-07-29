#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for single-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

// Difference of node counts
class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        stack<ListNode*> reverse_stack;
        ListNode *ret;
        ListNode *p;

        if (head == NULL)
            return NULL;

        while (head != NULL) {
            reverse_stack.push(head);
            head = head->next;
        }

        ret = reverse_stack.top();
        p = ret;
        reverse_stack.pop();
        while (!reverse_stack.empty()) {
            p->next = reverse_stack.top();
            p = p->next;
            reverse_stack.pop();
        }
        p->next = NULL;

        return ret;
        
    }
};


int main(int argc, char *argv[]) {
    class Solution sol1;
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;

    ListNode *p = sol1.reverseList(&node1);

    while (p != NULL) {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}

