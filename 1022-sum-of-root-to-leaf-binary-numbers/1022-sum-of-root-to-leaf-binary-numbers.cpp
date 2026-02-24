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
    int sumRootToLeaf(TreeNode* root) {
        int ret = 0;
        helper(root, 0, ret);
        return ret;
    }

    void helper(TreeNode *root, int val, int &ret) {
        if(root == nullptr) {
            return;
        }
        
        if(root->val == 0) {
            val = val * 2;
        } else {
            val = val * 2 + 1;
        }

        if(root->left == nullptr && root->right == nullptr) {
            ret += val;
            return;
        }

        helper(root->left, val, ret);
        helper(root->right, val, ret);
    }
};