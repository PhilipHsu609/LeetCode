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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        n = root;
    }
    
    int next() {
        if(!hasNext()) {
            return -1;
        }
        n = s.top(); s.pop();
        int ret = n->val;
        n = n->right;
        return ret;
    }
    
    bool hasNext() {
        if(n == nullptr && s.empty()) {
            return false;
        }
        while(n != nullptr) {
            s.push(n);
            n = n->left;
        }
        return true;
    }

    stack<TreeNode*> s;
    TreeNode *n;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */