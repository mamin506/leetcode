#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../mlibs.h"

using namespace std;

class Solution {
    public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ret;
        ListNode* p;
        ListNode* q;
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ret = head->next;
        // swap
        head->next = ret->next;
        ret->next = head;
        p = ret->next;

        while (p->next != NULL) {
            q = p->next->next;
            if (q == NULL) {
               break;
            }
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    return 0;
}

