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
    void inorder(TreeNode* root, vector<int> &in){
        if(!root) return ;
        
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root->left && !root->right) return false;
        vector<int> in;
        inorder(root, in);
        
        int i=0, j=in.size()-1;
        int sum=0;
        while(i<j){
            sum=0;
            sum+=in[i];
            sum+=in[j];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                i++;
            }
            else j--;
        }
        return false;
    }
};