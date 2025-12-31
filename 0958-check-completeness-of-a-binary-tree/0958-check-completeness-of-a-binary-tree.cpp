/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool nomore = false;
        while(!q.empty()) {
            auto *u = q.front();
            q.pop();

            if(u == nullptr) {
                nomore = true;
            } else {
                if(nomore) {
                    return false;
                }
                q.push(u->left);
                q.push(u->right);
            }
        }

        return true;
    }
};