#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        queue<TreeNode*> queue;
        int n, m;
        if (root == NULL) return result;

        queue.push(root);
        n = 1;
        m = 0;
        while (!queue.empty() ) {
            // deal with n notes, save their children into the queue if they have
            for (int i = 0; i < n; i ++) {
                if (queue.front()->right != NULL) {
                    queue.push(queue.front()->right);
                    m++;
                }
                if (queue.front()->left != NULL) {
                    queue.push(queue.front()->left);
                    m++;
                }
                if (i == 0) {
                    result.push_back(queue.front()->val );
                }
                queue.pop();
            }

            // m know how many child note in queue
            // deal with these m notes in the next loop
            n = m;
            m = 0;
        }

        return result;
    }

    void printResult(vector<int> result) {
        vector<int>::iterator it;

        for (it = result.begin(); it != result.end(); it++) {
            cout << *it << endl;
        }
        cout << endl;
        cout << endl;
    }

};

int main(int argc, char *argv[]) {
    class Solution sol1;

    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);



    return 0;
}

