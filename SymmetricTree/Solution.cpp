#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return true;
        if (root->left != NULL && root->right != NULL) {
            return isMirrorChild(root->left, root->right);
        } else {
            return false;
        }
    }

    bool isMirrorChild(TreeNode *leftTree, TreeNode *rightTree) {
        if (leftTree->val != rightTree->val) return false;

        if (leftTree->left == NULL && rightTree->right == NULL &&
                leftTree->right == NULL && rightTree->left == NULL) return true;

        bool outsideMirror = false;
        bool insideMirror = false;
        if (leftTree->left != NULL && rightTree->right != NULL) {
            outsideMirror = isMirrorChild(leftTree->left, rightTree->right);
        } else if (leftTree->left == NULL && rightTree->right == NULL) {
            outsideMirror = true;
        }

        if (leftTree->right != NULL && rightTree->left != NULL) {
            insideMirror = isMirrorChild(leftTree->right, rightTree->left);
        } else if (leftTree->right == NULL && rightTree->left == NULL) {
            insideMirror = true;
        }

        if (outsideMirror && insideMirror) {
            return true;
        } else {
            return false;
        }

    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

