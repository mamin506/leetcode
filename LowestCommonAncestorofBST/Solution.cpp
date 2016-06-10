#inlcude "../mlibs.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL) return NULL;
        if ((root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val)) {
            return root;
        } else if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

