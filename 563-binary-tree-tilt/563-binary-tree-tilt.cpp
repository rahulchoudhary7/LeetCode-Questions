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
    int help(TreeNode* root, int &sum){
        if(!root) return 0;
        
        
        int leftSum = help(root->left, sum);
        int rightSum = help(root->right, sum);
        
        sum+= abs(leftSum-rightSum);
        
        return leftSum + rightSum + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int sum =0;
        help(root, sum);
        return sum;
    }
};