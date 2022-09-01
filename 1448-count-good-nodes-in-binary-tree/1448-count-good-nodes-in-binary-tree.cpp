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
    void solve(TreeNode* root, int &ans, int prev){
        if(root == NULL) return;
        if(root->val >= prev){
            ans++;
            prev = root->val;
        }
        solve(root->left, ans, prev);
        solve(root->right, ans, prev);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int prev = INT_MIN;
        solve(root, ans, prev);
        return ans;
    }
};

//    int ans=0;
//     void pre(TreeNode* root,int max){
//         if(!root)return;
//         if(root->val >= max){ ans++; max=root->val; }
//         pre(root->left,max);
//         pre(root->right,max);
//     }
// public:
//     int goodNodes(TreeNode* root) {
//         pre(root,INT_MIN);
//         return ans;
//     }