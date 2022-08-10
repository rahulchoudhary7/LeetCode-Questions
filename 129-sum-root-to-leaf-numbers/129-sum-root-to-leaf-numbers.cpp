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
    void pathss(TreeNode* root, string output, vector<string> &ans){
        if(root == NULL){
            return;
        }
        
        if(!root->left && !root->right){
            output+=to_string(root->val);
            ans.push_back(output);
        }
        
        output+=to_string(root->val);
        
        pathss(root->left, output, ans);
        pathss(root->right, output, ans);
        
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<string> paths;
        string output = "";
        pathss(root, output, paths);
        
        int sum =0;
        
        for(int i = 0; i<paths.size(); i++){
            int add = stoi(paths[i]);
            sum+=add;
        }
        return sum;
    }
};