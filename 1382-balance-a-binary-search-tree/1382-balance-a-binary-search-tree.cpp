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
    void inOrder(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }
    
    TreeNode* buildTree(vector<int> &inorder, int s, int e){
        if(s>e) return NULL;
        
        int mid = (s+e)/2;
        
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildTree(inorder, s, mid-1);
        root->right = buildTree(inorder, mid+1, e);
        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(root, inorder);
        TreeNode* newRoot = buildTree(inorder, 0, inorder.size()-1);
        return newRoot;
    }
};