/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy; // Dummy node to simplify the result list creation
    struct ListNode* current = &dummy; // Pointer to the current node in the result list
    dummy.next = NULL; // Initialize the next pointer of the dummy node

    int carry = 0; // Initialize carry to 0

    while (l1 != NULL || l2 != NULL || carry > 0) {
        int sum = carry; // Start with the carry from the previous addition

        if (l1 != NULL) {
            sum += l1->val; // Add value from l1 if available
            l1 = l1->next; // Move to the next node in l1
        }

        if (l2 != NULL) {
            sum += l2->val; // Add value from l2 if available
            l2 = l2->next; // Move to the next node in l2
        }

        carry = sum / 10; // Calculate new carry for next iteration
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode)); // Allocate new node for result
        current = current->next; // Move to the new node
        current->val = sum % 10; // Set the value of the new node
        current->next = NULL; // Initialize next pointer to NULL
    }

    return dummy.next; // Return the head of the result list (skipping dummy)
}
// @lc code=end

