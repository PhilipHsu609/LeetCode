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
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool strict = false) {
        if(root == nullptr || subRoot == nullptr) {
            return root == nullptr && subRoot == nullptr;
        }
        if(strict) {
            if(root->val != subRoot->val) {
                return false;
            }
            return isSubtree(root->left, subRoot->left, true) && isSubtree(root->right, subRoot->right, true);
        }

        return ((root->val == subRoot->val) && isSubtree(root->left, subRoot->left, true) && isSubtree(root->right, subRoot->right, true))
            || (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};