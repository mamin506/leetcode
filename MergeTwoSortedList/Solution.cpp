#include <iostream>
#include <string>
#include <vector>

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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode ret(0);
        ListNode* p = &ret;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            } else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        if (l1 == NULL) {
            p->next = l2;
        }
        if (l2 == NULL) {
            p->next = l1;
        }
        return ret.next;
    }
};


int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

