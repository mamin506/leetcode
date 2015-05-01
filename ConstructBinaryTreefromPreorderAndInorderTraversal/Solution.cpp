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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) return NULL;

        TreeNode *tmp = new TreeNode(preorder.front());
        if (preorder.size() == 1) return tmp;

        vector<int> l_preorder;
        vector<int> r_preorder;
        vector<int> l_inorder;
        vector<int> r_inorder;

        bool findRoot = false;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == tmp.val) {
                findRoot = true;
                continue;
            }

            if (findRoot) {
                r_inorder.push_back(inorder[i]);
            } else {
                l_inorder.push_back(inorder[i]);
            }
        }

        for (int i = 0; i < l_inorder.size(); i++) {
            l_preorder.push_back(preorder[i+1]);
        }

        for (int i = 0; i < r_inorder.size(); i++) {
            r_preorder.push_back(preorder[i+1+l_inorder.size()]);
        }

        tmp.left = buildTree(l_preorder, l_inorder);
        tmp.right = buildTree(r_preorder, r_inorder);

        return tmp;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);

    return 0;
}

