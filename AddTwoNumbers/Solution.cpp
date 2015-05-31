#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *pRet = NULL;
        ListNode *pCurr = pRet;
        unsigned char carry = 0;
        unsigned char val1, val2;

        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                val1 = 0;
            } else {
                val1 = l1->val;
                l1 = l1->next;
            }

            if (l2 == NULL) {
                val2 = 0;
            } else {
                val2 = l2->val;
                l2 = l2->next;
            }

            carry = carry + val1 + val2;
            if (pRet == NULL) {
                pRet = new ListNode(carry%10);
                pCurr = pRet;
            } else {
                pCurr->next = new ListNode(carry%10);
                pCurr = pCurr->next;
            }
            carry /= 10;
        }
        if (carry != 0)
            pCurr->next = new ListNode(1);

        return pRet;
    }

    // solotion2
    //ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    //    ListNode preHead(0), *p = &preHead;
    //    int extra = 0;
    //    while (l1 || l2 || extra) {
    //        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
    //        extra = sum / 10;
    //        p->next = new ListNode(sum % 10);
    //        p = p->next;
    //        l1 = l1 ? l1->next : l1;
    //        l2 = l2 ? l2->next : l2;
    //    }
    //    return preHead.next;  //space for timing
    //}

};

int main(int argc, char *argv[]) {
    Solution sol1;
    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode(5);
    ListNode *p;

    p = sol1.addTwoNumbers(l1, l2);

    if (p != NULL)
        cout << p->val << " -> " << endl;

    return 0;
}

