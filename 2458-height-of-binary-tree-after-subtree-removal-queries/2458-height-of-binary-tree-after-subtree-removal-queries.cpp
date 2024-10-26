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
    int maxh;
    unordered_map<int, int> lh, rh;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxh = 0;
        lpre(root, 0);
        maxh = 0;
        rpre(root, 0);

        vector<int> ret;
        for(int q : queries) {
            ret.push_back(max(lh[q], rh[q]));
        }

        return ret;
    }

    void lpre(TreeNode *n, int h) {
        if(n == nullptr) {
            return;
        }
        lh[n->val] = maxh;
        maxh = max(maxh, h);
        lpre(n->left, h + 1);
        lpre(n->right, h + 1);
    }

    void rpre(TreeNode *n, int h) {
        if(n == nullptr) {
            return;
        }
        rh[n->val] = maxh;
        maxh = max(maxh, h);
        rpre(n->right, h + 1);
        rpre(n->left, h + 1);
    }
};