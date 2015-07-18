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
        if (head == NULL) return NULL;
        ListNode* p = head;

        while (p->next) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
                continue;
            }
            p = p->next;
        }

        return head;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

