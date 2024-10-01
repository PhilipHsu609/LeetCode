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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> m;

        for(int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }

        return build(n - 1, 0, n - 1, postorder, m);
    }

    TreeNode *build(int p, int l, int r, const vector<int> &postorder, unordered_map<int, int> &m) {
        if(l > r) {
            return nullptr;
        }

        int val = postorder[p];
        TreeNode *node = new TreeNode(val);

        node->right = build(p - 1, m[val] + 1, r, postorder, m);
        node->left = build(p - (r - m[val]) - 1, l, m[val] - 1, postorder, m);

        return node;
    }
};