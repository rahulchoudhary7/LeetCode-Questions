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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        //map of (horizontal dist, map(level, vector(nodes)));
        map<int, map<int, multiset<int> > > hashMap;
        
        //queue for level order traversal
        //queue of Node*, pair(hd, level))
        queue<pair<TreeNode*, pair<int, int> > > q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            pair<TreeNode*, pair<int, int> > temp = q.front();
            q.pop();
            
            TreeNode* frontNode = temp.first;
            
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            hashMap[hd][lvl].insert(frontNode->val);
            
            if(frontNode->left)
                q.push({frontNode->left, {hd-1, lvl+1}});
            
            if(frontNode->right)
                q.push({frontNode->right, {hd+1, lvl+1}});
        }
        
        for (auto p : hashMap) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};