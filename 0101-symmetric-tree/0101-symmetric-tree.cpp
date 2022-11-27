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
private:
    bool symmetric(TreeNode* left, TreeNode* right){
        if(!left || !right) return left == right;
        if(left->val != right->val) return false;
        
        bool leftCheck = symmetric(left->left, right->right);
        bool rightCheck = symmetric(left->right, right->left);
        
        return leftCheck && rightCheck;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return symmetric(root->left, root->right);
    }
};