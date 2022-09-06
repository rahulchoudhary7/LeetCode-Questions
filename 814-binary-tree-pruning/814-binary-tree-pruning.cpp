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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        TreeNode* leftSide = pruneTree(root->left);
        TreeNode* rightSide = pruneTree(root->right);
        root->left = leftSide;
        root->right = rightSide;
        if(root->val == 0 && !leftSide && !rightSide) return NULL;
        return root;
    }
};