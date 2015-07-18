#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* preHead = new ListNode(0);
        ListNode* p = preHead;          // point to the node just before duplicate nodes.
        preHead->next = head;
        if (head->val != head->next->val) p = head;
        ListNode* q = head;

        while (q->next->next) {
            if (q->val != q->next->val && q->next->val != q->next->next->val) {
                // when this node (q point to), next node and next next node is different, it will be save to move p pointer
                p->next = q->next;
                p = p->next;
            }
            q = q->next;
        }
        if (q->val == q->next->val) p->next = NULL;
        else p->next = q->next;

        return preHead->next;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

