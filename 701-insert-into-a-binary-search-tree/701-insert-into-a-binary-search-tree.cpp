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
//     TreeNode* insert(TreeNode* root, int val){
//         if(root == NULL){
//             root = new TreeNode(val);
//             return root;
//         }
        
//         if(val > root->val){
//             root->right = insert(root->right, val);
//         }
//         else{
//             root->left = insert(root->left, val);
//         }
//         return root;
//     }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        
        if(val > root->val){
            root->right = insertIntoBST(root->right, val);
        }
        else{
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};