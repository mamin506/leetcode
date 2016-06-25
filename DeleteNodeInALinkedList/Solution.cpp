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
    void deleteNode(ListNode *node) {
        if (node == NULL) return;
        
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

