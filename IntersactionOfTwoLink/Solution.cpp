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

// Difference of node counts
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenListA = countNodes(headA);
        int lenListB = countNodes(headB);
         
        if (lenListA > lenListB) {
            return getIntersectionNode(lenListA - lenListB, headA, headB);
        } else {
            return getIntersectionNode(lenListB - lenListA, headB, headA);
        }
    }

private:
    ListNode *getIntersectionNode(int diff, ListNode *headL, ListNode *headS) {
        while (diff != 0) {
            headL = headL->next;
            diff--;
        }

        while (headL != NULL && headS != NULL && headL != headS) {
            headL = headL->next;
            headS = headS->next;
        }

        return headL;
    }

    int countNodes(ListNode *head) {
        int ret = 0;
        ListNode *p = head;
        while (p != NULL) {
            ret++;
            p = p->next;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = NULL;

    node1->next = node2;

    sol1.getIntersectionNode(node1, node3);

    return 0;
}

