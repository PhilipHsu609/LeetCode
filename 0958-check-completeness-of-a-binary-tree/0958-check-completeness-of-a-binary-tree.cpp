/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        bool hitNull = false;
        while (!q.empty()) {
            for (int s = q.size(); s > 0; --s) {
                auto* node = q.front();
                q.pop();

                if(hitNull && node != nullptr) {
                    return false;
                }

                if (node != nullptr) {
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    hitNull = true;
                }
            }
        }

        return true;
    }
};