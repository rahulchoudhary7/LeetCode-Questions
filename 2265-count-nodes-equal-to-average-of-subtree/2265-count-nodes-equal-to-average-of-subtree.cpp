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
    pair<int, int> helpAvg(TreeNode* root, int &ans){
        if(!root){
            return {0,0};
        }
        // pair<int, int> = {sum of node, count};
        pair<int, int> left = helpAvg(root->left, ans);

        pair<int, int> right = helpAvg(root->right, ans);
        
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        
        if(sum/count == root->val){
            ans++;
        }
        
        return {sum, count};
    }
public:
    int averageOfSubtree(TreeNode* root){
        int ans = 0;
        // int count = 0;
        helpAvg(root, ans);
        return ans;
    }
};