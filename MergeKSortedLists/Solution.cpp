#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../mlibs.h"

using namespace std;

class Solution {
    public:
    //ListNode* mergeKLists(vector<ListNode*>& lists) {
    //    if (lists.empty()) return NULL;
    //    int len = lists.size();
    //    while (len > 1) {
    //        for (int i = 0; i < len / 2; ++i) {
    //            lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
    //        }
    //        len = (len + 1) / 2;
    //    }
    //    return lists.front();
    //}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partion(lists, 0, lists.size()-1);
    }

    ListNode* partion(ListNode* lists, int s, int e) {
        if (s == e) return lists[s];
        if (s < e) {
            int q = (s + e)/2;
            ListNode* l1 = partion(lists, s, q);
            ListNode* l2 = partion(lists, q+1, e);
            return mergeTwoLists(l1, l2);
        } else {
            return NULL;
        }
    }

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

    ListNode node00 = ListNode(1);

    vector<ListNode*> lists;
    lists.push_back(&node00);
    sol1.mergeKLists(lists);

    return 0;
}

