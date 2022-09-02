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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> lot;
        vector<int> temp1;
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL){
                lot.push_back(temp1);
                temp1.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                temp1.push_back(temp->val);
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        
        for(int i=0; i<lot.size(); i++){
            double avg = 0;
            for(int j=0; j<lot[i].size(); j++){
                avg+=lot[i][j];
            }
            avg = avg/lot[i].size();
            ans.push_back(avg);
        }
        return ans;
    }
};