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
    void inorder(TreeNode* root, vector<int> &in){
        TreeNode* curr = root;
        
        while(curr){
            if(!curr->left){
                in.push_back(curr->val);
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
                    in.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>in;
        inorder(root, in);
        
        int i=0, j = in.size()-1;
        
        while(i<j){
            int sum = in[i]+in[j];
            if(sum==k) return true;
            else if(sum<k) i++;
            else j--;
        }
        return false;
    }
};