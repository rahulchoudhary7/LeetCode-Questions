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
    pair<int, int> height(TreeNode* root){
        if(root == NULL){
            pair<bool, int> p = {true, 0};
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = {true, root->val};
            return p;
        }
        
        pair<bool, int> leftAns = height(root->left);
        pair<bool, int> rightAns = height(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool check = root->val == leftSum + rightSum;
        
        pair<bool, int> ans;
        if(left && right && check){
            ans.first = true;
            ans.second = leftSum + rightSum;
        }
        
        else
            ans.first = false;
        
        return ans;
    }
public:
    bool checkTree(TreeNode* root) {
        return height(root).first;
    }
};