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
    void treePaths(TreeNode* root, string output, vector<string> &ans){
        if(root == NULL) return;
        if(!root->left && !root->right){
            output+=to_string(root->val);
            ans.push_back(output);
        }
        output+=to_string(root->val);
        output+="->";
        treePaths(root->left, output, ans);
        treePaths(root->right, output, ans);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string output = "";
        vector<string> ans;
        treePaths(root, output, ans);
        return ans;
    }
};