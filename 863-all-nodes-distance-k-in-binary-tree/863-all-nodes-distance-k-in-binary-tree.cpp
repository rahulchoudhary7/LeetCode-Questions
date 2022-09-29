/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void addParent(TreeNode* root, unordered_map <TreeNode*, TreeNode*> &n2p){
        if(!root) return;
        
        if(root->left){
            n2p[root->left] = root;
            addParent(root->left, n2p);
        }
        
        if(root->right){
            n2p[root->right] = root;
            addParent(root->right, n2p);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> n2p;
        unordered_map<TreeNode*, bool> visited;
        
        addParent(root, n2p);
        
        n2p[root] = NULL;
        
        vector<int> res;
        
        queue<TreeNode*> q;
        
        q.push(target);
        

        
        while(!q.empty() && k>=0){
            int sz = q.size();
            
            while(sz--){
                TreeNode* front = q.front();
                q.pop();
                
                visited[front] = true;
                
                // cout<<front->val;
                
                if(k==0) res.push_back(front->val);
                
                if(n2p[front] && !visited[n2p[front]]){
                    visited[n2p[front]] = true;
                    q.push(n2p[front]);
                }
                
                if(front->left && !visited[front->left]){
                    visited[front->left] = true;
                    q.push(front->left);
                }
                
                if(front->right && !visited[front->right]){
                    visited[front->right] = true;
                    q.push(front->right);
                }
            }
            k--;
            
        }
        
        return res;
    }
};