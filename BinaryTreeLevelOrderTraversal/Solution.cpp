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
    vector<vector<int> > levelOrder(TreeNode *root) {
        levelOrder(root, 0);

        return result;
    }

    void levelOrder(TreeNode *root, int level) {
        if (root == NULL) return;

        if (result.size() == level)
            result.push_back(vector<int>());
            
        result[level].push_back(root->val);
        levelOrder(root->left, level+1);
        levelOrder(root->right, level+1);
    }

    void printResule() {
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << ' ';
            }
            cout << endl;
        }
    }

private:
    vector<vector<int> > result;
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

