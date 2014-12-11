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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        //ListNode *pre_head = new ListNode(0);
        //ListNode *p, *q;
        //pre_head->next = p = head;

        //for (int i = 1; i < n; i++) p = p->next;

        //q = pre_head;
        //while (p->next != NULL) {
        //    p = p->next;
        //    q = q->next;
        //}

        //q->next = q->next->next;

        //return pre_head->next;

        // here is a more elegant code from discuss
        ListNode** t1 = &head, *t2 = head;
        for(int i = 1; i < n; ++i)
        {
            t2 = t2->next;
        }
        while(t2->next != NULL)
        {
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        return head;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);

    node1->next = node2;

    cout << sol1.removeNthFromEnd(node1, 2)->val << endl;

    return 0;
}

