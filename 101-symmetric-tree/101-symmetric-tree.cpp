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
    bool isSymmetricHelp(TreeNode* leftNode, TreeNode* rightNode){
        if(leftNode == NULL || rightNode == NULL)
            return leftNode == rightNode;
        
        if(leftNode->val != rightNode->val)
            return false;
        
        bool leftSide = isSymmetricHelp(leftNode->left, rightNode->right);
        bool rightSide = isSymmetricHelp(leftNode->right, rightNode->left);
        
        return leftSide && rightSide;
    }
    
    
    
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelp(root->left, root->right);
    }
};