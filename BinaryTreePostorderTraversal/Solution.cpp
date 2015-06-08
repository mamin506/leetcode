#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

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
    // Recursive solution
    //vector<int> postorderTraversal(TreeNode *root) {
    //    vector<int> ret;
    //    if (root == NULL) return ret;
    //    postorderTraversal(root->left, ret);
    //    postorderTraversal(root->right, ret);
    //    ret.push_back(root->val);
    //    return ret;
    //}
    //void postorderTraversal(TreeNode *root, vector<int> &ret) {
    //    if (root == NULL) return;
    //    postorderTraversal(root->left, ret);
    //    postorderTraversal(root->right, ret);
    //    ret.push_back(root->val);
    //}

    // iterative solution1
    //vector<int> postorderTraversal(TreeNode *root) {
    //    vector<int> ret;
    //    if (root == NULL) return ret;

    //    stack<TreeNode *> leftStack, rightStack;
    //    TreeNode *tmp = root;
    //    
    //    leftStack.push_back(root);
    //    tmp = root->left;
    //    while (!leftStack.emptpy()) {
    //        if (tmp) {
    //            leftStack.push_back(tmp);
    //            tmp = tmp->left;
    //        } else {
    //            if (!right.empty() && !left.empty() && right.top()==left.top()) {
    //                tmp = right.top();
    //                right.pop();
    //                left.pop();
    //                res.push_back(tmp->val);
    //                tmp = NULL;
    //            } else if (!left.empty()) {
    //                tmp = left.top();
    //                if (tmp->right) {
    //                    right.push(tmp);
    //                    left.push(tmp->right);
    //                    tmp = tmp->right->left;
    //                } else {
    //                    left.pop();
    //                    res.push_back(tmp->val);
    //                    tmp = NULL;
    //                }
    //            }
    //        }
    //    }
    //}

    // iterative solution1
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) return ret;

        unordered_map<TreeNode *, bool> visitMap;
        stack<TreeNode *> s;
        s.push(root);
        visitMap[root] = false;
        while (!s.empty()) {
            if (s.top()->left && visitMap.find(s.top()->left) == visitMap.end()) {
                visitMap[s.top()->left] = false;
                s.push(s.top()->left);
            } else if (s.top()->right && visitMap.find(s.top()->right) == visitMap.end()) {
                visitMap[s.top()->left] = false;
                s.push(s.top()->right);
            } else {
                ret.push_back(s.top()->val);
                visitMap[s.top()] = true;
                s.pop();
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    return 0;
}

