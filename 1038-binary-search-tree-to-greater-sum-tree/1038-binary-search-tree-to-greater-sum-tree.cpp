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
    int sum = 0;
    void GST(TreeNode* root){
        if(root == NULL) return;
        
        if(root->right)
            GST(root->right);
        root->val +=sum;
        sum = root->val;
        
        if(root->left)
            GST(root->left);
        
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;
        GST(root);
        return root;        
    }
};