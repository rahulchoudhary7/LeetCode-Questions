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
    void kthSmallestHelp(TreeNode* root, int k, int &ans, int &res){
        if(root == NULL) return;
        
        kthSmallestHelp(root->left, k, ans, res);
        ans++;
        if(ans == k){
            res = root->val;
            return;
        }
        kthSmallestHelp(root->right, k, ans, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int res = 0;
        kthSmallestHelp(root, k, ans, res);
        return res;
    }
};