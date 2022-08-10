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
    TreeNode* merge(TreeNode* first, TreeNode* second){
        if(first==NULL) return second;
        else if (second == NULL) return first;
        
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* temp = dummy;
        while(first && second){
            if(first->val < second-> val){
                temp->left = first;
                temp = first;
                first = first->left;
            }
            else{
                temp->left = second;
                temp = second;
                second = second -> left;
            }
        }
        if(first){
            temp->left = first;
        }
        else if(second){
            temp->left = second;
        }
        dummy->right = NULL;
        return dummy->left;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while(curr){
            if(curr->left){
                TreeNode* temp = curr->left;
                while(temp->right)
                    temp = temp->right;
                
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};