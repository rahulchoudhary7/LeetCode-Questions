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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool nullCheck = false;
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front == NULL)
                nullCheck = true;
            
            else{
                if(nullCheck) return false;
                
                q.push(front->left);
                q.push(front->right);
            }
        }
        
        return true;
    }
};