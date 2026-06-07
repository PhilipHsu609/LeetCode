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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> v2n;
        unordered_map<int, int> c2p;

        for(const auto &d : descriptions) {
            int p = d[0];
            int c = d[1];
            int isLeft = d[2];

            if(v2n.find(p) == v2n.end()) {
                v2n[p] = new TreeNode(p);
            }
            if(v2n.find(c) == v2n.end()) {
                v2n[c] = new TreeNode(c);
            }

            if(isLeft) {
                v2n[p]->left = v2n[c];
            } else {
                v2n[p]->right = v2n[c];
            }

            c2p[c] = p;
        }

        for(auto [v, ptr] : v2n) {
            if(c2p.find(v) == c2p.end()) {
                return ptr;
            }
        }

        return nullptr;
    }
};