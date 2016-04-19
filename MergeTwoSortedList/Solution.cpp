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
    // My solution
    //ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //    if (l1 == NULL) return l2;
    //    if (l2 == NULL) return l1;
    //    ListNode ret(0);
    //    ListNode* p = &ret;
    //    while (l1 != NULL && l2 != NULL) {
    //        if (l1->val < l2->val) {
    //            p->next = l1;
    //            l1 = l1->next;
    //            p = p->next;
    //        } else {
    //            p->next = l2;
    //            l2 = l2->next;
    //            p = p->next;
    //        }
    //    }
    //    if (l1 == NULL) {
    //        p->next = l2;
    //    }
    //    if (l2 == NULL) {
    //        p->next = l1;
    //    }
    //    return ret.next;
    //}

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

