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
    int minvalue(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(root->val == key){
            
            //leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            // only one node
            //left == null
            else if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            //right == null
            else if(root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            //both nodes present
            else{
                int mini = minvalue(root->right);
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
            
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else{
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};