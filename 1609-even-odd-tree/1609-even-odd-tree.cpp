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
    void levelorder(TreeNode* root, vector<vector<int>> &levelOrder){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> output;
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL){
                levelOrder.push_back(output);
                output.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            
            else{
                output.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> levelOrder;
        levelorder(root, levelOrder);
        
        int n = levelOrder.size();
        
        for(int i =0; i<n; i++){
            vector<int> temp;
            temp = levelOrder[i];
            int m = temp.size();
            if(!(i&1)){
                for(int j = 0; j<m; j++){
                    if(j==0){
                        if(!(temp[j] &1) ) return false;
                    }
                    else{
                        if(!(temp[j]&1) || temp[j]<=temp[j-1]) return false;
                    }
                }
            }
            
            else{
                for(int k = 0; k<m; k++){
                    if(k==0){
                        if(temp[k]&1) return false;
                    }
                    else{
                        if(temp[k]&1 || temp[k]>=temp[k-1]) return false;
                    }
                }
            }
        }
        return true;
    }
};