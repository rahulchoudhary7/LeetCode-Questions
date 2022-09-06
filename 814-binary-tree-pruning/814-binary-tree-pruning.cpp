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
        if(root->val == 0 && !root->left && !root->right) return NULL;
        // if(root->val ==0 && !root->left && root->right->val == 0) return NULL;
        // if(root->val ==0 && root->left->val ==0 && !root->right) return NULL;
        // if(root->val ==0 && (root->left && root->left->val == 0 && root->right && root->right->val == 0))           return NULL;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && !root->left && !root->right) return NULL;
        return root;
    }
};