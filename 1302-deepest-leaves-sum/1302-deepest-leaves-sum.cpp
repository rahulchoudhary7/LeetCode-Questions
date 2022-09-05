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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        int sum = 0;
        
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            
            if(frontNode== NULL){
                if(!q.empty()){
                    q.push(NULL);
                    sum=0;
                }
            }
            else{
                sum+=frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
        }
        
        
        return sum;
    }
};