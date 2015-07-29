#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Solution1
    //TreeNode *left, *right;
    //void recoverTree(TreeNode *root) {
    //    left = NULL;
    //    right = NULL;
    //    TreeNode* pred = NULL;
    //    helper(root, pred);
    //    swap(left->val, right->val);
    //}

    //void helper(TreeNode* root, TreeNode*& pred) {
    //    if (!root) return;
    //    helper(root->left, pred);
    //    if (pred && pred->val > root->val) {
    //        if (!left) {
    //            left = pred;
    //            right = root;
    //        } else {
    //            right = root;
    //        }
    //    }
    //    helper(root->right, root);
    //    pred = root;
    //}

    TreeNode *left, *right, *pred;
    void recoverTree(TreeNode *root) {
        left = right = pred = NULL;
        findout(root);
        swap(left->val, right->val);
    }

    void findout(TreeNode *root) {
        if (root->left != NULL)
            findout(root->left);

        if (pred != NULL) {
            if (pred->val > root->val) {
                if (left == NULL) {
                    left = pred;
                }
                right = root;
            }
        }

        pred = root;

        if (root->right != NULL)
            findout(root->right);

    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);

    node1->right = node2;

    if (sol1.isValidBST(node1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

