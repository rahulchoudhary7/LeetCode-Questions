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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return NULL;
        if(depth == 1){
            TreeNode* newRoot = new TreeNode (val);
            newRoot->left = root;
            return newRoot;
        }
        if(depth == 2){
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;
            
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            
            root->left = newLeft;
            newLeft->left = tempLeft;
            root->right = newRight;
            newRight->right = tempRight;
            
            return root;
        }
        
        else{
            depth--;
            addOneRow(root->left, val, depth);
            addOneRow(root->right, val, depth);
        }
        
        return root;
    }
};