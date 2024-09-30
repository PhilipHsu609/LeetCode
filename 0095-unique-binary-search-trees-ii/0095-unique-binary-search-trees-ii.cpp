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
    vector<TreeNode*> generateTrees(int n) {
        return gen(1, n);
    }

    vector<TreeNode*> gen(int start, int end) {
        if(start > end) {
            return {nullptr};
        }

        vector<TreeNode*> ret;
        for(int i = start; i <= end; i++) {
            auto left = gen(start, i - 1);
            auto right = gen(i + 1, end);

            for(auto *l : left) {
                for(auto *r : right) {
                    ret.push_back(new TreeNode(i, l, r));
                }
            }
        }

        return ret;
    }
};