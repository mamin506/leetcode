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
    bool hasCycle(ListNode *head) {
        ListNode *tortoise = head;
        ListNode *hare = head;
        
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                return true;
            }
        }

        return false;
    }
};


int main(int argc, char *argv[]) {
    class Solution sol1;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    if (sol1.hasCycle(node1)) {
        cout << "has cycle" << endl;
    } else {
        cout << "no cycle" << endl;
    }

    return 0;
}

