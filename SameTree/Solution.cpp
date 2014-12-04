#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        else if (p == NULL || q == NULL) return false;

        return p->val == q->val \
            && isSameTree(p->left, q->left) \
            && isSameTree(p->right, q->right);
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;

    struct TreeNode *tree1;
    struct TreeNode *tree2 = new TreeNode(0);

    if (sol1.isSameTree(tree1, tree2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

