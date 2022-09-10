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
    void inorder(TreeNode* root, vector<int> &ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    vector<int> merge(vector<int> &a, vector<int> &b){
        int n = a.size();
        int m = b.size();
        vector<int> ans(m+n);
        
        int i(0), j(0), ansIdx(0);
        
        while(i<n && j<m){
            if(a[i]<b[j]){
                ans[ansIdx++] = a[i++];
            }
            else{
                ans[ansIdx++] = b[j++];
            }
        }
        
        while(i<n){
            ans[ansIdx++] = a[i++];
        }
        while(j<m){
            ans[ansIdx++] = b[j++];
        }
        return ans;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        inorder(root1, list1);
        inorder(root2, list2);
        
        vector<int> ans = merge(list1, list2);
        return ans;
    }
};