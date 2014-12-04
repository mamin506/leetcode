#include <iostream>
#include <string>
#include <vector>

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
    bool isBalanced(TreeNode *root) {
        int depth = 0;

        return isBalanced(root, &depth);
    }

    bool isBalanced(TreeNode *root, int *depth) {
        if (root == NULL) {
            *depth = 0;
            return true;
        }
        
        int left, right;
        if (isBalanced(root->left, &left) && isBalanced(root->right, &right)) {
            int diff = left - right;
            if (diff <= 1 && diff >= -1) {
                *depth = 1 + (left > right? left : right);
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);

    return 0;
}

