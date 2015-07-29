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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0) return NULL;

        return buildTree(inorder,    0, inorder.size(),
                         postorder,  0, postorder.size());
    }

    TreeNode *buildTree(vector<int> &inorder,   int inL,    int inR, 
                        vector<int> &postorder, int postL,  int postR) {
        TreeNode *tmp = new TreeNode(postorder[postR-1]);
        
        int n;
        for (n = 0; n < inR - inL; n++) {
            if (inorder[inL + n] == tmp->val)
                break;
        }

        tmp->left  = (n == 0)? NULL : buildTree(inorder,   inL,   inL+n,
                                                postorder, postL, postL+n);
        tmp->right = (n == inR - inL -1)? NULL : buildTree(inorder,    inL+n+1, inR,
                                                            postorder, postL+n, postR-1);
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);

    return 0;
}

