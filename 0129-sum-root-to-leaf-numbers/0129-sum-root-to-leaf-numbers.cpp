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
    void pathss(TreeNode* root, string output, vector<string> &strings){
        if(!root) 
            return;
        
        if(!root->right && !root->left) {
            output+= to_string(root->val);
            strings.push_back(output);
        }
        
        output+= to_string(root->val);
        
        pathss(root->left, output, strings);
        pathss(root->right, output, strings);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<string> strings;
        string output = "";
        
        pathss(root, output, strings);
        
        for(int i=0; i<strings.size(); i++)
            cout<<strings[i]<<" "<<endl;
        
        int ans=0;
        for(int i = 0; i<strings.size(); i++){
            ans+=stoi(strings[i]);
        }
        
        return ans;
        
        
    }
};