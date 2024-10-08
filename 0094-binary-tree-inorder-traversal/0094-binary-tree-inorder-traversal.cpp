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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;

        while(root != nullptr || !s.empty()) {
            while(root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top(); s.pop();
            ret.push_back(root->val);
            root = root->right;
        }

        return ret;
    }
};