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
    int maxSum(TreeNode* root, int &maxS){
        if(root == NULL)
            return 0;
        
        int left = max(0, maxSum(root->left, maxS));
        int right = max(0, maxSum(root->right, maxS));
        
        int sum = root->val + left + right;
        maxS = max(maxS, sum);
        
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        int maxS = INT_MIN;
        maxSum(root, maxS);
        return maxS;
    }
};