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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        map<int, int> hash_map; //(level, node->val)
        
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            
            TreeNode* frontNode = temp.first;
            int level = temp.second;
            
            if(hash_map.find(level)== hash_map.end())
                hash_map[level] = frontNode->val;
            
            else if(hash_map[level] < frontNode->val)
                hash_map[level] = frontNode->val;
            
            if(frontNode->left)
                q.push({frontNode->left, level+1});
            
            if(frontNode->right)
                q.push({frontNode->right, level+1});
            
        }
        
        for(auto i : hash_map){
            ans.push_back(i.second);
        }
        return ans;
    }
};