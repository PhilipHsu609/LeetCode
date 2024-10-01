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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> s;

        int n = traversal.size();
        int i = 0;

        while(i < n) {
            int level = 0;
            while(i < n && traversal[i] == '-') {
                level++;
                i++;
            }

            int val = 0;
            while(i < n && isdigit(traversal[i])) {
                val *= 10;
                val += traversal[i] - '0';
                i++;
            }

            while(s.size() > level) {
                s.pop();
            }

            TreeNode *node = new TreeNode(val);
            if(!s.empty()) {
                if(s.top()->left == nullptr) {
                    s.top()->left = node;
                } else {
                    s.top()->right = node;
                }
            }
            s.push(node);
        }

        TreeNode *ret = nullptr;
        while(!s.empty()) {
            ret = s.top();
            s.pop();
        }

        return ret;
    }
};