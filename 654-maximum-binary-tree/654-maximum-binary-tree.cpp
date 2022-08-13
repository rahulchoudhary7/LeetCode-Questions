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
    int maxPos(int s, int e, vector<int> &nums){
        int maxi =s;
        for(int i =s+1; i<=e; i++){
            if(nums[i]>nums[maxi]){
                maxi = i;
            }
        }
        return maxi;
    }
    
    TreeNode* constructMax(int s, int e, vector<int> & nums){
        if(s>e) return NULL;
        
        int pos = maxPos(s, e, nums);
        
        TreeNode* root = new TreeNode(nums[pos]);
        root->left = constructMax(s, pos-1, nums);
        root->right = constructMax(pos+1, e, nums);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMax(0, nums.size()-1, nums);
    }
};