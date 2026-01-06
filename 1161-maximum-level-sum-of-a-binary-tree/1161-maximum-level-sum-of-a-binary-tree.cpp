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
    int maxLevelSum(TreeNode* root) {
        int ret = 0;
        int d = 1;
        int maxi = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            int sum = 0;

            for(int s = 0; s < n; ++s) {
                auto *u = q.front();
                q.pop();

                sum += u->val;

                if(u->left != nullptr) {
                    q.push(u->left);
                }
                if(u->right != nullptr) {
                    q.push(u->right);
                }
            }

            if(sum > maxi) {
                maxi = sum;
                ret = d;
            }

            ++d;
        }

        return ret;
    }
};