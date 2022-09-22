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
    int diff = 0;
    void helpFind(TreeNode* root, int maxx, int minn){
        if(!root) return;
        
        maxx = max(maxx, root->val);
        minn = min(minn, root->val);
        
        diff = max(diff, (maxx-minn));
        
        helpFind(root->left, maxx, minn);
        helpFind(root->right, maxx, minn);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        
        int maxx = INT_MIN;
        int minn = INT_MAX;
        helpFind(root, maxx, minn);
        return diff;
    }
};