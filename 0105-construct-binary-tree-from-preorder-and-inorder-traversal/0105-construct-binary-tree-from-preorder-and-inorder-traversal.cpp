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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> m;

        for(int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }

        return build(0, 0, n - 1, preorder, m);
    }

    TreeNode *build(int p, int l, int r, const vector<int> &preorder, unordered_map<int, int> &m) {
        if(l > r) {
            return nullptr;
        }

        int val = preorder[p];
        TreeNode *node = new TreeNode(val);

        node->left = build(p + 1, l, m[val] - 1, preorder, m);
        node->right = build(p + m[val] - l + 1, m[val] + 1, r, preorder, m);

        return node;
    }
};