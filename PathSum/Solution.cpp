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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;

        if (root->left == NULL && root->right == NULL && sum == root->val) return true;
        if (hasPathSum(root->left,  sum - root->val)) return true;
        if (hasPathSum(root->right, sum - root->val)) return true;
        return false;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);

    node1->right = node2;

    cout << sol1.hasPathSum(node1, 4) << endl;
    cout << sol1.hasPathSum(node1, 2) << endl;

    return 0;
}

