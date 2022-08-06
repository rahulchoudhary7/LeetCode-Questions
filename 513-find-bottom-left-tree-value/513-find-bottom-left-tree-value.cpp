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
    int findBottomLeftValue(TreeNode* root) {
        map<int, int> m; //level, node->val
        queue<pair<TreeNode*, int> > q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            
            TreeNode* frontNode = temp.first;
            int level = temp.second;
            
            if(m.find(level) == m.end())
                m[level] = frontNode->val;
            
            if(frontNode->left)
                q.push({frontNode->left, level+1});
            
            if(frontNode->right)
                q.push({frontNode->right, level + 1});
        }
        int ans;
        for(auto i: m){
            ans = i.second;
        }
        return ans;
    }
};