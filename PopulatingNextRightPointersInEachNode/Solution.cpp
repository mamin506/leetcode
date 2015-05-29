#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 *
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
*/

class Solution {
public:
    // recursive
    //void connect(TreeLinkNode *root) {
    //    if (root == NULL) return;           //Not a empty tree
    //    if (root->left == NULL) return;     //Not a leave node
    //    root->left->next = root->right;
    //    if (root->next != NULL) {
    //        root->right->next = root->next->left;
    //    }
    //    connect(root->left);
    //    connect(root->right);
    //}

    // iterative
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *first = root;
        TreeLinkNode *p;
        
        while (first->left != NULL) {
            p = first;
            first = p->left;
            do {
                p->left->next = p->right;
                if (p->next)
                    p->right->next = p->next->left;
                p = p->next;
            } while (p);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;

    return 0;
}

