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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *prev = nullptr;

        TreeNode *n1 = nullptr, *n2 = nullptr;

        while(root != nullptr || !s.empty()) {
            while(root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top(); s.pop();

            if(prev != nullptr && prev->val > root->val) {
                if(n1 == nullptr) {
                    n1 = prev;
                    n2 = root;
                } else {
                    n2 = root;
                }
            }

            prev = root;
            root = root->right;
        }

        swap(n1->val, n2->val);
    }
};