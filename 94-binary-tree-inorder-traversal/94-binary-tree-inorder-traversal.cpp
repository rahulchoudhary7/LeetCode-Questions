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
    void inOrder(TreeNode* root, vector<int> & res) {
        
        if(root == NULL)
            return;
        
        inOrder(root->left, res);
        
        res.push_back(root->val);
        
        inOrder(root->right, res);
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        // inOrder(root, res);
        //Morris traversal
        
        TreeNode* curr = root;
        
        while(curr){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            
            else{
                TreeNode* temp = curr->left;
                while(temp->right && temp->right!=curr){
                    temp = temp->right;
                }
                
                if(temp->right == NULL){
                    temp->right = curr;
                    curr = curr->left;
                }
                
                else{
                    temp->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return res;
    }
};