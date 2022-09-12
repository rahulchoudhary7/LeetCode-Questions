/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    void help(TreeNode* clone, int target, TreeNode* &ans){
        if(!clone) return;
        help(clone->left, target, ans);
        help(clone->right, target, ans);
        if(clone->val == target){
            ans = clone;
            return;
        }
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int find = target->val;
        TreeNode* ans= NULL;
        help(cloned, find, ans);
        return ans;
    }
};