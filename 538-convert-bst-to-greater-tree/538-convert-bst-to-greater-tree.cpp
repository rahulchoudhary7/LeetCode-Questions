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
    void convert(TreeNode* &root, vector<TreeNode*> &inorder){
        TreeNode* curr = root;
        while(curr){
            if(curr->left == NULL){
                inorder.push_back(curr);
                curr = curr->right;
            }
            else{
                TreeNode* temp = curr->left;
                while(temp->right && temp->right!=curr)
                    temp = temp->right;
                
                if(temp->right == NULL)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    temp->right = NULL;
                    inorder.push_back(curr);
                    curr = curr->right;
                }
            }
        }
        reverse(inorder.begin(), inorder.end());
    }
    
    int sum = 0;
    void helpConvert(TreeNode* root){
        if(root == NULL) return;
        if(root->right)
            helpConvert(root->right);
            root->val+=sum;
            sum=root->val;
        
        if(root->left)
            helpConvert(root->left);
        
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
//         vector<TreeNode*> revinorder;
        
//         int n = revinorder.size();
        
//         for(int i=1; i<n; i++){
//             revinorder[i]->val +=revinorder[i-1]->val;
//         }
//         return root;
        helpConvert(root);
        return root;
    }
};