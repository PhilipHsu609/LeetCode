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
    TreeNode *ret = nullptr;
    int max_depth = 0;

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        helper(root, 1);
        return ret;
    }

    int helper(TreeNode *node, int depth) {
        if(node == nullptr) {
            return depth - 1;
        }
        if(node->left == nullptr && node->right == nullptr) {
            if(depth > max_depth) {
                max_depth = depth;
                ret = node;
            }
            return depth;
        }

        int l = helper(node->left, depth + 1);
        int r = helper(node->right, depth + 1);

        if(l == r && l == max_depth) {
            ret = node;
        }
        return max(l, r);
    }
};