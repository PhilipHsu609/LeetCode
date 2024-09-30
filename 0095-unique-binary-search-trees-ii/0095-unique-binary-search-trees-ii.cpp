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
        map<pair<int, int>, vector<TreeNode*>> memo;
        return gen(1, n, memo);
    }

    vector<TreeNode*> gen(int start, int end, map<pair<int, int>, vector<TreeNode*>> &memo) {
        if(start > end) {
            return {nullptr};
        }

        if(memo.find({start, end}) != memo.end()) {
            return memo[{start, end}];
        }

        vector<TreeNode*> ret;
        for(int i = start; i <= end; i++) {
            auto left = gen(start, i - 1, memo);
            auto right = gen(i + 1, end, memo);

            for(auto *l : left) {
                for(auto *r : right) {
                    ret.push_back(new TreeNode(i, l, r));
                }
            }
        }

        return memo[{start, end}] = ret;
    }
};