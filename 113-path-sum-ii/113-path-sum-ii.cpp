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
    void targetPaths(TreeNode* root, int targetSum, int sum, vector<int> output, vector<vector<int>> & ans){
        if(!root) return;
        if(!root->right && !root->left){
            output.push_back(root->val);
            sum+=root->val;
            if(sum==targetSum)
                ans.push_back(output);
        }
        sum+=root->val;
        output.push_back(root->val);
        targetPaths(root->left, targetSum, sum, output, ans);
        targetPaths(root->right, targetSum, sum, output, ans);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> output;
        int sum = 0;
        targetPaths(root, targetSum, sum, output, ans);
        return ans;
    }
};