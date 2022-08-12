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
//     void kthSmallestHelp(TreeNode* root, int k, int &smallValueCount, int &res){
//         if(root == NULL) return;
        
//         kthSmallestHelp(root->left, k, smallValueCount, res);
//         smallValueCount++;
//         if(smallValueCount == k){
//             res = root->val;
//             return;
//         }
//         kthSmallestHelp(root->right, k, smallValueCount, res);
//     }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode* curr = root;
        
        vector<int> ans;
        
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            
            else{
                TreeNode* temp = curr->left;
                while(temp->right!= NULL && temp->right != curr)
                    temp = temp->right;
                
                if(temp->right==NULL){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    temp->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        int res = ans[k-1];
        ans.clear();
        return res;
    }
};