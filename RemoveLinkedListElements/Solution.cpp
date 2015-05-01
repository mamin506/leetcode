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
    ListNode *removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;

        // while val is the value of head node
        while (head->val == val) {
            head = head->next;
            if (head == NULL) {
                return NULL;
            }
        }

        ListNode* pre = head;
        ListNode* curr = head->next;

        while (curr != NULL) {
            if (curr->val == val) {
                pre = curr->next;
            } else {
                pre = curr;
            }
            curr = curr->next;
        }

        return head;

    }
};

int main(int argc, char *argv[]) {
    Solution sol1;

    return 0;
}

