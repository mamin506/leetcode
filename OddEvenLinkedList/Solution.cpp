#inlcude "../mlibs.h"

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;

        ListNode* preOddNode = head;
        ListNode* evenNode = head->next;
        ListNode* postOddNode;

        while (evenNode != NULL && evenNode->next != NULL) {
            postOddNode = evenNode->next;

            evenNode->next = postOddNode->next;
            evenNode = postOddNode->next;
            postOddNode->next = preOddNode->next;
            preOddNode->next = postOddNode;
            preOddNode = postOddNode;
        }
        return head;
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

