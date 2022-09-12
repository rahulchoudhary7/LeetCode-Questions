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
    TreeNode* addParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, int &start){

        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = NULL;
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front->val == start){
                res = front;
            }
            
            if(front->left){
                q.push(front->left);
                parent[front->left] = front;
            }
            
            if(front->right){
                q.push(front->right);
                parent[front->right] = front;
            }
        }
        return res;
    }
    
    int infectTree(TreeNode* &target, unordered_map<TreeNode*, TreeNode*> &parent){
        int time = 0;
        
        unordered_map<TreeNode*, bool> infected;
        infected[target] = true;
        queue<TreeNode*> q;
        q.push(target);
        
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            
            for(int i =0; i<n; i++){
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left && !infected[front->left]){
                    q.push(front->left);
                    infected[front->left] = true;
                    flag = true;
                }
                
                if(front->right && !infected[front->right]){
                    q.push(front->right);
                    infected[front->right] = true;
                    flag = true;
                }
                
                if(parent[front] && !infected[parent[front]]){
                    q.push(parent[front]);
                    infected[parent[front]] = true;
                    flag = true;
                }
            }
            if(flag) time++;
        }
        
        return time;
    }
    
    
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        
        TreeNode* target = addParent(root, parent, start);
        
        
        int time = infectTree(target, parent);
        
        return time; 
        
    }
};