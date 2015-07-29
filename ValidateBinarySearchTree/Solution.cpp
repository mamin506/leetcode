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
    // Solutioin 1
    //bool isValidBST(TreeNode *root) {
    //    vector<int> vect;

    //    return isValidBST_sub(root, vect);
    //
    //}

    //bool isValidBST_sub(TreeNode *root, vector<int> &vect) {
    //    if (root == NULL) return true;
    //    if (root->left != NULL) {
    //        if (!isValidBST_sub(root->left, vect))
    //            return false;
    //    }
    //    if (vect.empty() || vect.back() < root->val) {
    //        vect.push_back(root->val);
    //    } else {
    //        return false;
    //    }
    //    if (root->right != NULL) {
    //        if (!isValidBST_sub(root->right, vect))
    //            return false;
    //    }

    //    return true;
    //}

    bool isValidBST(TreeNode *root) {
        long long min = LLONG_MIN, max = LLONG_MAX;
        return isValidBST(root, min, max);
    }

    bool isValidBST(TreeNode *node, long long min, long long max){
        if(node == NULL)
            return true;
        if(node->val <= min || node->val >= max)
            return false;
        if(!isValidBST(node->left, min, node->val) || !isValidBST(node->right, node->val, max))
            return false;

        return true;

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

