#include <iostream>
#include <string>
#include <vector>
#include "../mlibs.h"

using namespace std;

class Solution {
public:

    ListNode* findNextK(ListNode* head, int k) {
        ListNode *p = head;
        int i = 1;

        while (p != NULL && p->next != NULL && i < k) {
            p = p->next;
            i++;
        }

        if (i == k) return p;

        return head;
    }

    void reverseLinkList(ListNode* head, ListNode* tail) {
        ListNode* t;
        
        while (head != tail) {
            t = head->next;
            head->next = tail->next;
            tail->next = head;
            head = t;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ret = head;
        ListNode *p, *q;
        ListNode *tail = NULL;

        p = head;
        do {
            if (p == NULL) break;
            q = findNextK(p, k);
            if (p == q) {
                break;
            }
            /* reverse from p -> q */
            reverseLinkList(p, q);

            /* now q point to the first node
             * p point to the last node
             */
            if (tail == NULL) {
                ret = q;
            } else {
                tail->next = q;
            }
            
            tail = p;
            p = p->next;
        } while (1);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    if (argc != 2)
        exit(1);

    int i = atoi(argv[1]);

    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    ListNode l7(7);
    ListNode *ret;

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;

    printf("%p\n", &l1);
    printf("%p\n", &l2);
    printf("%p\n", &l3);
    printf("%p\n", &l4);
    printf("%p\n", &l5);
    printf("%p\n", &l6);
    printf("%p\n", &l7);
    printf("\n");
    //ret = sol1.findNextK(&l1, i);
    ret = sol1.reverseKGroup(&l1, i);

    while (ret) {
        printf("%d %p\n", ret->val, ret);
        ret = ret->next;
    }

    return 0;
}

