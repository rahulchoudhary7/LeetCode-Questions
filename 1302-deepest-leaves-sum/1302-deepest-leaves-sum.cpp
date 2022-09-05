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
        
        vector<int> temp;
        
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            
            if(frontNode== NULL){
                if(!q.empty()){
                    q.push(NULL);
                    temp.clear();
                }
            }
            else{
                temp.push_back(frontNode->val);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
        }
        
        int n = temp.size();
        int sum = 0;
        
        for(int i=0; i<temp.size(); i++)
            sum+=temp[i];
        
        return sum;
    }
};