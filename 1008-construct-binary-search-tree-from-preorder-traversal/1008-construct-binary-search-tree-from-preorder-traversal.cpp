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
    TreeNode* helpBST(vector<int> &preorder, int maxi, int &i){
        if(i>=preorder.size()) return NULL;
        
        if(preorder[i] > maxi) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helpBST(preorder, root->val, i);
        root->right = helpBST(preorder, maxi, i);
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return helpBST(preorder, INT_MAX, i);
    }
};