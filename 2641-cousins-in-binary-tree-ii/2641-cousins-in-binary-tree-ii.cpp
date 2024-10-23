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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q; // {node, sibling sum}

        q.push({root, root->val});
        int lsum = root->val;

        while(!q.empty()) {
            int nlsum = 0; // next level sum
            for(int i = q.size(); i > 0; i--) {
                auto [n, ssum] = q.front(); q.pop();

                n->val = lsum - ssum;

                int nssum = 0;
                if(n->left != nullptr) {
                    nssum += n->left->val;
                }
                if(n->right != nullptr) {
                    nssum += n->right->val;
                }

                nlsum += nssum;
                if(n->left != nullptr) {
                    q.push({n->left, nssum});
                }
                if(n->right != nullptr) {
                    q.push({n->right, nssum});
                }
            }
            lsum = nlsum;
        }

        return root;
    }
};