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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    int dfs(TreeNode *n) {
        if(n == nullptr) {
            return 0;
        }

        int l = dfs(n->left);
        int r = dfs(n->right);

        if(l == -1 || r == -1 || abs(l - r) > 1) {
            return -1;
        }

        return max(l, r) + 1;
    }
};