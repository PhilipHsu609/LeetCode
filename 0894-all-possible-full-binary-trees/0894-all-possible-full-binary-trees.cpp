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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) {
            return {};
        }

        if(n == 1) {
            return {new TreeNode()};
        }

        vector<TreeNode*> ret;
        // (1, 5), (3, 3)
        for(int i = 1; i <= n / 2; i += 2) {
            auto lfbt = allPossibleFBT(i);
            auto rfbt = allPossibleFBT(n - 1 - i);

            for(int j = 0; j < lfbt.size(); ++j) {
                for(int k = 0; k < rfbt.size(); ++k) {
                    TreeNode *root1 = new TreeNode(0, lfbt[j], rfbt[k]);
                    ret.push_back(root1);
                    if(i != n - 1 - i) {
                        TreeNode *root2 = new TreeNode(0, rfbt[k], lfbt[j]);
                        ret.push_back(root2);
                    }
                }
            }
        }

        return ret;
    }
};