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
    void countt(TreeNode* root, int &count){
        if(root==NULL) return;
        
        count++;
        countt(root->left, count);
        countt(root->right, count);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int ans = 0;
        countt(root, ans);
        
        return ans;
    }
};