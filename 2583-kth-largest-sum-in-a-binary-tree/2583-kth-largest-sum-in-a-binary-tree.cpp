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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            long long sum = 0;
            for(int i = q.size(); i > 0; i--) {
                TreeNode *n = q.front(); q.pop();
                sum += n->val;

                if(n->left != nullptr) {
                    q.push(n->left);
                }
                if(n->right != nullptr) {
                    q.push(n->right);
                }
            }
            sums.push_back(sum);
        }

        if(sums.size() < k) {
            return -1;
        }

        sort(sums.rbegin(), sums.rend());
        return sums[k - 1];
    }
};