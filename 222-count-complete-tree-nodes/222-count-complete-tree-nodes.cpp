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
//         if(root==NULL) return;
        
//         count++;
//         countt(root->left, count);
//         countt(root->right, count);
        TreeNode* curr = root;
        
        while(curr){
            if(!curr->left){
                curr = curr->right;
                count++;
            }
            
            else{
                TreeNode* temp = curr->left;
                while(temp->right && temp->right!=curr){
                    temp = temp->right;
                }
                
                if(temp->right == curr){
                    temp->right = NULL;
                    count++;
                    curr = curr->right;
                }
                else{
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int ans = 0;
        countt(root, ans);
        
        return ans;
    }
};