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
    void pathSum(TreeNode* root, int targetSum, int sum, bool &flag){
        if(root == NULL)
            return ;
        
        if(!root->left && !root->right){
            sum+=root->val;
            if(sum==targetSum){
                flag = true;
                return;
            }
           
        }
        
        sum+=root->val;
        pathSum(root->left, targetSum, sum, flag);
        pathSum(root->right, targetSum, sum, flag);
        
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        int sum = 0;
        pathSum(root, targetSum, sum, flag);
        
        return flag;
    }
};