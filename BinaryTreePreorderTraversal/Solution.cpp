#include <iostream>
#include <string>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stack;
        
        if (root == NULL) return result;
        stack.push(root);

        TreeNode *top;
        while(!stack.empty()) {
            top = stack.top();
            stack.pop();
            result.push_back(top->val);

            if (top->right != NULL) {
                stack.push(top->right);
            }

            if (top->left != NULL) {
                stack.push(top->left);
            }

        }

        return result;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);

    node1->right = node2;

    sol1.levelOrder(node1);
    sol1.printResule();

    return 0;
}

