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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode dummy;
        TreeNode *tail = &dummy;

        while(cur != nullptr || !s.empty()) {
            if(cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode *u = s.top();
                s.pop();

                // process
                tail->right = u;
                u->left = nullptr;

                TreeNode *tmp = u->right;
                u->right = nullptr;
                tail = u;

                cur = tmp;
            }
        }

        return dummy.right;
    }
};