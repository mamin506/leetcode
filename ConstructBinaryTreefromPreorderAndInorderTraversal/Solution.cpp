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

        return buildTree(preorder, 0, preorder.size(),
                         inorder,  0, inorder.size());
    }

    TreeNode *buildTree(vector<int> &preorder, int preL, int preR, 
                        vector<int> &inorder,  int inL,  int inR) {
        TreeNode *tmp = new TreeNode(preorder[preL]);
        
        int n;
        for (n = 0; n < inR - inL; n++) {
            if (inorder[inL + n] == tmp->val)
                break;
        }

        tmp->left  = ((n + inL) == inL)? NULL : buildTree(preorder, preL+1, preL+n+1,
                                                          inorder,  inL,    inL+n);
        tmp->right = ((n + inL) == inR-1)? NULL : buildTree(preorder, preL+n+1, preR,
                                                            inorder, inL+n+1, inR);
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);

    return 0;
}

