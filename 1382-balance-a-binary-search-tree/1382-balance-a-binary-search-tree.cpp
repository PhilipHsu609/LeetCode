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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        int n = inorder(root, nodes);
        return makeBalance(nodes, 0, n - 1);
    }

    int inorder(TreeNode *root, vector<TreeNode*> &nodes) {
        if(root == nullptr) {
            return 0;
        }

        int l = inorder(root->left, nodes);
        nodes.push_back(root);
        int r = inorder(root->right, nodes);

        return l + r + 1;
    }

    TreeNode *makeBalance(const vector<TreeNode*> &nodes, int l, int r) {
        if(l > r) {
            return nullptr;
        }

        int mid = l + (r - l) / 2;
        TreeNode *root = nodes[mid];
        root->left = makeBalance(nodes, l, mid - 1);
        root->right = makeBalance(nodes, mid + 1, r);

        return root;
    }
};